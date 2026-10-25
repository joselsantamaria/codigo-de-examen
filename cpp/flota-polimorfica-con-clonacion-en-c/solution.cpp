#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// Interfaz abstracta: nunca se instancia directamente.
class Vehiculo {
public:
    explicit Vehiculo(std::string id) : id_(std::move(id)) {}
    virtual ~Vehiculo() = default;

    const std::string& id() const { return id_; }

    virtual long long coste(long long km) const = 0;
    virtual long long autonomia() const = 0;
    virtual void describir(std::string& out) const = 0;
    virtual std::unique_ptr<Vehiculo> clonar() const = 0;
    virtual bool ajustar(long long) { return false; }

protected:
    // Copia solo accesible desde las derivadas: evita el corte (slicing).
    Vehiculo(const Vehiculo&) = default;
    Vehiculo& operator=(const Vehiculo&) = default;

private:
    std::string id_;
};

// Clase intermedia: vehiculos con precio por kilometro ajustable.
class ConTarifa : public Vehiculo {
public:
    ConTarifa(std::string id, long long cpk, long long aut)
        : Vehiculo(std::move(id)), cpk_(cpk), aut_(aut) {}

    long long autonomia() const override { return aut_; }
    bool ajustar(long long nuevo) override {
        cpk_ = nuevo;
        return true;
    }

protected:
    long long cpk_;
    long long aut_;
};

class Furgoneta final : public ConTarifa {
public:
    using ConTarifa::ConTarifa;

    long long coste(long long km) const override { return cpk_ * km; }
    void describir(std::string& out) const override {
        out += "F(";
        out += std::to_string(cpk_);
        out += ")";
    }
    std::unique_ptr<Vehiculo> clonar() const override {
        return std::make_unique<Furgoneta>(*this);
    }
};

class Electrica final : public ConTarifa {
public:
    using ConTarifa::ConTarifa;
    static constexpr long long TARIFA_CONEXION = 150;

    long long coste(long long km) const override {
        return cpk_ * km + TARIFA_CONEXION;
    }
    void describir(std::string& out) const override {
        out += "E(";
        out += std::to_string(cpk_);
        out += ")";
    }
    std::unique_ptr<Vehiculo> clonar() const override {
        return std::make_unique<Electrica>(*this);
    }
};

class Bicicleta final : public Vehiculo {
public:
    using Vehiculo::Vehiculo;

    long long coste(long long km) const override { return 40 * km; }
    long long autonomia() const override { return 25; }
    void describir(std::string& out) const override { out += "B"; }
    std::unique_ptr<Vehiculo> clonar() const override {
        return std::make_unique<Bicicleta>(*this);
    }
};

// Decorador: ES un Vehiculo y TIENE (en exclusiva) otro Vehiculo.
class Remolque final : public Vehiculo {
public:
    Remolque(std::string id, std::unique_ptr<Vehiculo> base, long long extra)
        : Vehiculo(std::move(id)), base_(std::move(base)), extra_(extra) {}

    // Copia profunda: la base se duplica a traves de su propio clonar().
    Remolque(const Remolque& o)
        : Vehiculo(o), base_(o.base_->clonar()), extra_(o.extra_) {}

    long long coste(long long km) const override {
        return base_->coste(km) + extra_ * km;
    }
    long long autonomia() const override {
        return base_->autonomia() * 8 / 10;
    }
    void describir(std::string& out) const override {
        out += "R(";
        out += std::to_string(extra_);
        out += ")+";
        base_->describir(out);
    }
    std::unique_ptr<Vehiculo> clonar() const override {
        return std::make_unique<Remolque>(*this);
    }
    bool ajustar(long long nuevo) override {
        extra_ = nuevo;
        return true;
    }

private:
    std::unique_ptr<Vehiculo> base_;
    long long extra_;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    if (!(std::cin >> n)) return 0;

    std::vector<std::unique_ptr<Vehiculo>> flota;
    std::map<std::string, std::size_t> indice;

    auto alta = [&](std::unique_ptr<Vehiculo> v) {
        indice[v->id()] = flota.size();
        flota.push_back(std::move(v));
    };

    for (int k = 0; k < n; ++k) {
        char op = ' ';
        std::cin >> op;
        if (op == 'F' || op == 'E') {
            std::string id;
            long long cpk = 0, aut = 0;
            std::cin >> id >> cpk >> aut;
            if (op == 'F') alta(std::make_unique<Furgoneta>(id, cpk, aut));
            else alta(std::make_unique<Electrica>(id, cpk, aut));
        } else if (op == 'B') {
            std::string id;
            std::cin >> id;
            alta(std::make_unique<Bicicleta>(id));
        } else if (op == 'R') {
            std::string id, base;
            long long extra = 0;
            std::cin >> id >> base >> extra;
            const Vehiculo& original = *flota[indice.at(base)];
            alta(std::make_unique<Remolque>(id, original.clonar(), extra));
        } else if (op == 'C') {
            std::string id;
            long long valor = 0;
            std::cin >> id >> valor;
            if (!flota[indice.at(id)]->ajustar(valor)) {
                std::cout << "NO_AJUSTABLE " << id << '\n';
            }
        } else if (op == 'Q') {
            long long km = 0;
            std::cin >> km;
            const Vehiculo* mejor = nullptr;
            long long mejorCoste = 0;
            for (const auto& v : flota) {
                if (v->autonomia() < km) continue;
                long long c = v->coste(km);
                if (mejor == nullptr || c < mejorCoste ||
                    (c == mejorCoste && v->id() < mejor->id())) {
                    mejor = v.get();
                    mejorCoste = c;
                }
            }
            std::cout << km << ": ";
            if (mejor != nullptr) std::cout << mejor->id() << ' ' << mejorCoste << '\n';
            else std::cout << "NINGUNO\n";
        } else if (op == 'L') {
            if (flota.empty()) std::cout << "FLOTA VACIA\n";
            for (const auto& v : flota) {
                std::string d;
                v->describir(d);
                std::cout << v->id() << ' ' << d << " aut=" << v->autonomia() << '\n';
            }
        }
    }
    return 0;
}
