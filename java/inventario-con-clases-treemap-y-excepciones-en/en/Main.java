import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class Main {

    static class InvalidMovementException extends Exception {
        public InvalidMovementException(String reason) {
            super(reason);
        }
    }

    static class Item {
        private final String code;
        private final String name;
        private int stock;

        Item(String code, String name, int stock) {
            this.code = code;
            this.name = name;
            this.stock = stock;
        }

        void receive(int quantity) throws InvalidMovementException {
            if (quantity <= 0) {
                throw new InvalidMovementException("invalid quantity");
            }
            stock += quantity;
        }

        void issue(int quantity) throws InvalidMovementException {
            if (quantity <= 0) {
                throw new InvalidMovementException("invalid quantity");
            }
            if (quantity > stock) {
                throw new InvalidMovementException("insufficient stock");
            }
            stock -= quantity;
        }

        @Override
        public String toString() {
            return code + " " + name + " " + stock;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<String> lines = new ArrayList<>();
        String line;
        while ((line = br.readLine()) != null) {
            if (!line.trim().isEmpty()) {
                lines.add(line.trim());
            }
        }

        int pos = 0;
        int n = Integer.parseInt(lines.get(pos++));
        Map<String, Item> inventory = new TreeMap<>();
        for (int i = 0; i < n; i++) {
            String[] p = lines.get(pos++).split("\\s+");
            inventory.put(p[0], new Item(p[0], p[1], Integer.parseInt(p[2])));
        }

        int m = Integer.parseInt(lines.get(pos++));
        int applied = 0;
        int rejected = 0;
        StringBuilder errors = new StringBuilder();

        for (int k = 1; k <= m; k++) {
            String[] p = lines.get(pos++).split("\\s+");
            try {
                String type = p[0];
                if (!type.equals("RECEIVE") && !type.equals("ISSUE")) {
                    throw new InvalidMovementException("unknown type");
                }
                Item item = inventory.get(p[1]);
                if (item == null) {
                    throw new InvalidMovementException("no such item");
                }
                int quantity = Integer.parseInt(p[2]);
                if (type.equals("RECEIVE")) {
                    item.receive(quantity);
                } else {
                    item.issue(quantity);
                }
                applied++;
            } catch (InvalidMovementException e) {
                rejected++;
                errors.append("Movement ").append(k).append(": ")
                      .append(e.getMessage()).append("\n");
            }
        }

        StringBuilder out = new StringBuilder();
        out.append(errors);
        out.append("Inventory:\n");
        for (Item item : inventory.values()) {
            out.append(item).append("\n");
        }
        out.append("Applied: ").append(applied)
           .append(", rejected: ").append(rejected).append("\n");
        System.out.print(out);
    }
}
