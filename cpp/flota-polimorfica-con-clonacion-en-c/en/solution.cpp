#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// Abstract interface: never instantiated directly.
class Vehicle {
public:
    explicit Vehicle(std::string id) : id_(std::move(id)) {}
    virtual ~Vehicle() = default;

    const std::string& id() const { return id_; }

    virtual long long cost(long long km) const = 0;
    virtual long long range() const = 0;
    virtual void describe(std::string& out) const = 0;
    virtual std::unique_ptr<Vehicle> clone() const = 0;
    virtual bool tune(long long) { return false; }

protected:
    // Copying is only reachable from derived classes: no slicing from outside.
    Vehicle(const Vehicle&) = default;
    Vehicle& operator=(const Vehicle&) = default;

private:
    std::string id_;
};

// Intermediate class: vehicles with a tunable price per kilometre.
class Rated : public Vehicle {
public:
    Rated(std::string id, long long cpk, long long rng)
        : Vehicle(std::move(id)), cpk_(cpk), rng_(rng) {}

    long long range() const override { return rng_; }
    bool tune(long long value) override {
        cpk_ = value;
        return true;
    }

protected:
    long long cpk_;
    long long rng_;
};

class Van final : public Rated {
public:
    using Rated::Rated;

    long long cost(long long km) const override { return cpk_ * km; }
    void describe(std::string& out) const override {
        out += "V(";
        out += std::to_string(cpk_);
        out += ")";
    }
    std::unique_ptr<Vehicle> clone() const override {
        return std::make_unique<Van>(*this);
    }
};

class Electric final : public Rated {
public:
    using Rated::Rated;
    static constexpr long long CHARGING_FEE = 150;

    long long cost(long long km) const override {
        return cpk_ * km + CHARGING_FEE;
    }
    void describe(std::string& out) const override {
        out += "E(";
        out += std::to_string(cpk_);
        out += ")";
    }
    std::unique_ptr<Vehicle> clone() const override {
        return std::make_unique<Electric>(*this);
    }
};

class Bike final : public Vehicle {
public:
    using Vehicle::Vehicle;

    long long cost(long long km) const override { return 40 * km; }
    long long range() const override { return 25; }
    void describe(std::string& out) const override { out += "B"; }
    std::unique_ptr<Vehicle> clone() const override {
        return std::make_unique<Bike>(*this);
    }
};

// Decorator: IS a Vehicle and exclusively HAS another Vehicle.
class Trailer final : public Vehicle {
public:
    Trailer(std::string id, std::unique_ptr<Vehicle> base, long long extra)
        : Vehicle(std::move(id)), base_(std::move(base)), extra_(extra) {}

    // Deep copy: the base is duplicated through its own clone().
    Trailer(const Trailer& o)
        : Vehicle(o), base_(o.base_->clone()), extra_(o.extra_) {}

    long long cost(long long km) const override {
        return base_->cost(km) + extra_ * km;
    }
    long long range() const override {
        return base_->range() * 8 / 10;
    }
    void describe(std::string& out) const override {
        out += "T(";
        out += std::to_string(extra_);
        out += ")+";
        base_->describe(out);
    }
    std::unique_ptr<Vehicle> clone() const override {
        return std::make_unique<Trailer>(*this);
    }
    bool tune(long long value) override {
        extra_ = value;
        return true;
    }

private:
    std::unique_ptr<Vehicle> base_;
    long long extra_;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    if (!(std::cin >> n)) return 0;

    std::vector<std::unique_ptr<Vehicle>> fleet;
    std::map<std::string, std::size_t> index;

    auto add = [&](std::unique_ptr<Vehicle> v) {
        index[v->id()] = fleet.size();
        fleet.push_back(std::move(v));
    };

    for (int k = 0; k < n; ++k) {
        char op = ' ';
        std::cin >> op;
        if (op == 'V' || op == 'E') {
            std::string id;
            long long cpk = 0, rng = 0;
            std::cin >> id >> cpk >> rng;
            if (op == 'V') add(std::make_unique<Van>(id, cpk, rng));
            else add(std::make_unique<Electric>(id, cpk, rng));
        } else if (op == 'B') {
            std::string id;
            std::cin >> id;
            add(std::make_unique<Bike>(id));
        } else if (op == 'T') {
            std::string id, base;
            long long extra = 0;
            std::cin >> id >> base >> extra;
            const Vehicle& original = *fleet[index.at(base)];
            add(std::make_unique<Trailer>(id, original.clone(), extra));
        } else if (op == 'C') {
            std::string id;
            long long value = 0;
            std::cin >> id >> value;
            if (!fleet[index.at(id)]->tune(value)) {
                std::cout << "NOT_TUNABLE " << id << '\n';
            }
        } else if (op == 'Q') {
            long long km = 0;
            std::cin >> km;
            const Vehicle* best = nullptr;
            long long bestCost = 0;
            for (const auto& v : fleet) {
                if (v->range() < km) continue;
                long long c = v->cost(km);
                if (best == nullptr || c < bestCost ||
                    (c == bestCost && v->id() < best->id())) {
                    best = v.get();
                    bestCost = c;
                }
            }
            std::cout << km << ": ";
            if (best != nullptr) std::cout << best->id() << ' ' << bestCost << '\n';
            else std::cout << "NONE\n";
        } else if (op == 'L') {
            if (fleet.empty()) std::cout << "EMPTY FLEET\n";
            for (const auto& v : fleet) {
                std::string d;
                v->describe(d);
                std::cout << v->id() << ' ' << d << " range=" << v->range() << '\n';
            }
        }
    }
    return 0;
}
