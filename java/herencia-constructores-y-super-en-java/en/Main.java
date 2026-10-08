import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static abstract class Employee {
        private final String id;
        private final int base;

        protected Employee(String id, int base) {
            this.id = id;
            this.base = base;
        }

        public String getId() {
            return id;
        }

        public int getBase() {
            return base;
        }

        public abstract String type();

        public int salary() {
            return base;
        }

        @Override
        public String toString() {
            return id + " " + type() + " " + salary();
        }
    }

    static class Developer extends Employee {
        private static final int DEVELOPER_BASE = 1800;
        private static final int HOURLY_RATE = 25;
        private final int overtimeHours;

        public Developer(String id, int overtimeHours) {
            this(id, DEVELOPER_BASE, overtimeHours);
        }

        protected Developer(String id, int base, int overtimeHours) {
            super(id, base);
            this.overtimeHours = overtimeHours;
        }

        @Override
        public String type() {
            return "Developer";
        }

        @Override
        public int salary() {
            return super.salary() + HOURLY_RATE * overtimeHours;
        }
    }

    static class SeniorDeveloper extends Developer {
        private static final int SENIOR_BASE = 2400;
        private static final int ON_CALL_BONUS = 150;
        private final int onCallShifts;

        public SeniorDeveloper(String id, int overtimeHours, int onCallShifts) {
            super(id, SENIOR_BASE, overtimeHours);
            this.onCallShifts = onCallShifts;
        }

        @Override
        public String type() {
            return "Senior";
        }

        @Override
        public int salary() {
            return super.salary() + ON_CALL_BONUS * onCallShifts;
        }
    }

    static class SalesRep extends Employee {
        private static final int SALES_BASE = 1500;
        private static final int PERCENT = 8;
        private final int sales;

        public SalesRep(String id, int sales) {
            super(id, SALES_BASE);
            this.sales = sales;
        }

        @Override
        public String type() {
            return "Sales";
        }

        @Override
        public int salary() {
            return super.salary() + sales * PERCENT / 100;
        }
    }

    static class Manager extends Employee {
        private static final int MANAGER_BASE = 3500;

        public Manager(String id) {
            super(id, MANAGER_BASE);
        }

        @Override
        public String type() {
            return "Manager";
        }
    }

    public static void main(String[] args) throws IOException {
        String input = new String(System.in.readAllBytes()).trim();
        String[] tk = input.isEmpty() ? new String[0] : input.split("\\s+");
        int p = 0;
        int n = tk.length == 0 ? 0 : Integer.parseInt(tk[p++]);

        List<Employee> staff = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String kind = tk[p++];
            String id = tk[p++];
            Employee created = switch (kind) {
                case "D" -> new Developer(id, Integer.parseInt(tk[p++]));
                case "S" -> {
                    int hours = Integer.parseInt(tk[p++]);
                    int shifts = Integer.parseInt(tk[p++]);
                    yield new SeniorDeveloper(id, hours, shifts);
                }
                case "R" -> new SalesRep(id, Integer.parseInt(tk[p++]));
                case "M" -> new Manager(id);
                default -> throw new IllegalArgumentException("Unknown type: " + kind);
            };
            staff.add(created);
        }

        StringBuilder out = new StringBuilder();
        long total = 0;
        for (Employee e : staff) {
            out.append(e).append('\n');
            total += e.salary();
        }
        out.append("TOTAL ").append(total).append('\n');
        System.out.print(out);
    }
}
