import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;

public class Main {

    static class Wallet {
        private static final int MAXIMUM = 15000;

        private final String owner;
        private int balance;

        Wallet(String owner) {
            this.owner = owner;
            this.balance = 0;
        }

        String getOwner() {
            return owner;
        }

        int getBalance() {
            return balance;
        }

        String topUp(int cents) {
            if (cents <= 0) {
                return "INVALID";
            }
            if (balance + cents > MAXIMUM) {
                return "LIMIT";
            }
            balance += cents;
            return "OK";
        }

        String pay(int cents) {
            if (cents <= 0) {
                return "INVALID";
            }
            if (cents > balance) {
                return "INSUFFICIENT";
            }
            balance -= cents;
            return "OK";
        }

        String balanceInDollars() {
            return String.format("%d.%02d", balance / 100, balance % 100);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String first = in.readLine();
        if (first == null || first.isBlank()) {
            return;
        }
        int n = Integer.parseInt(first.trim());
        Map<String, Wallet> wallets = new HashMap<>();
        StringBuilder output = new StringBuilder();

        for (int i = 0; i < n; i++) {
            String line = in.readLine();
            if (line == null) {
                break;
            }
            String[] parts = line.trim().split("\\s+");
            String owner = parts[0];
            String operation = parts[1];
            int amount = Integer.parseInt(parts[2]);

            Wallet w = wallets.computeIfAbsent(owner, Wallet::new);
            String result;
            if (operation.equals("TOPUP")) {
                result = w.topUp(amount);
            } else {
                result = w.pay(amount);
            }
            output.append(result).append(' ')
                  .append(w.getOwner()).append(' ')
                  .append(w.balanceInDollars()).append('\n');
        }
        System.out.print(output);
    }
}
