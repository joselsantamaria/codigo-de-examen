import java.io.*;
import java.nio.file.*;
import java.util.*;

public class Main {

    static class Product implements Serializable {
        private static final long serialVersionUID = 1L;
        final String name;
        long quantity;
        long price;

        Product(String name, long quantity, long price) {
            this.name = name;
            this.quantity = quantity;
            this.price = price;
        }
    }

    static class Warehouse implements Serializable {
        private static final long serialVersionUID = 1L;
        private final List<Product> products = new ArrayList<>();
        private transient long totalValue = 0;

        private Product find(String name) {
            for (Product p : products) {
                if (p.name.equals(name)) return p;
            }
            return null;
        }

        void add(String name, long quantity, long price) {
            Product p = find(name);
            if (p == null) {
                p = new Product(name, quantity, price);
                products.add(p);
                totalValue += quantity * price;
            } else {
                totalValue -= p.quantity * p.price;
                p.quantity += quantity;
                p.price = price;
                totalValue += p.quantity * p.price;
            }
        }

        String sell(String name, long quantity) {
            Product p = find(name);
            if (p == null) return "ERROR unknown product";
            if (p.quantity < quantity) return "ERROR insufficient stock";
            p.quantity -= quantity;
            totalValue -= quantity * p.price;
            return "SOLD " + name + " " + p.quantity;
        }

        long value() {
            return totalValue;
        }

        int size() {
            return products.size();
        }

        List<Product> list() {
            return products;
        }

        private void readObject(ObjectInputStream in)
                throws IOException, ClassNotFoundException {
            in.defaultReadObject();
            totalValue = 0;
            for (Product p : products) {
                totalValue += p.quantity * p.price;
            }
        }
    }

    static final Path FILE = Paths.get("warehouse.dat");

    static void save(Warehouse w) throws IOException {
        try (ObjectOutputStream out = new ObjectOutputStream(
                new BufferedOutputStream(Files.newOutputStream(FILE)))) {
            out.writeObject(w);
        }
    }

    static Warehouse load() throws IOException, ClassNotFoundException {
        try (ObjectInputStream in = new ObjectInputStream(
                new BufferedInputStream(Files.newInputStream(FILE)))) {
            return (Warehouse) in.readObject();
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Warehouse warehouse = new Warehouse();
        StringBuilder sb = new StringBuilder();
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            if (line.isEmpty()) continue;
            String[] t = line.split("\\s+");
            switch (t[0]) {
                case "ADD" -> {
                    warehouse.add(t[1], Long.parseLong(t[2]), Long.parseLong(t[3]));
                    sb.append("ADDED ").append(t[1]).append('\n');
                }
                case "SELL" -> sb.append(warehouse.sell(t[1], Long.parseLong(t[2]))).append('\n');
                case "VALUE" -> sb.append("VALUE ").append(warehouse.value()).append('\n');
                case "SAVE" -> {
                    save(warehouse);
                    sb.append("SAVED ").append(warehouse.size()).append('\n');
                }
                case "LOAD" -> {
                    if (!Files.exists(FILE)) {
                        sb.append("ERROR no file\n");
                    } else {
                        warehouse = load();
                        sb.append("LOADED ").append(warehouse.size()).append('\n');
                    }
                }
                case "LIST" -> {
                    for (Product p : warehouse.list()) {
                        sb.append(p.name).append(' ').append(p.quantity)
                          .append(' ').append(p.price).append('\n');
                    }
                }
                default -> { }
            }
        }
        System.out.print(sb);
        Files.deleteIfExists(FILE);
    }
}
