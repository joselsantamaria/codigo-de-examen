import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {

    static abstract class Empleado {
        private final String dni;
        private final int base;

        protected Empleado(String dni, int base) {
            this.dni = dni;
            this.base = base;
        }

        public String getDni() {
            return dni;
        }

        public int getBase() {
            return base;
        }

        public abstract String tipo();

        public int sueldo() {
            return base;
        }

        @Override
        public String toString() {
            return dni + " " + tipo() + " " + sueldo();
        }
    }

    static class Programador extends Empleado {
        private static final int BASE_PROGRAMADOR = 1800;
        private static final int PRECIO_HORA = 25;
        private final int horasExtra;

        public Programador(String dni, int horasExtra) {
            this(dni, BASE_PROGRAMADOR, horasExtra);
        }

        protected Programador(String dni, int base, int horasExtra) {
            super(dni, base);
            this.horasExtra = horasExtra;
        }

        @Override
        public String tipo() {
            return "Programador";
        }

        @Override
        public int sueldo() {
            return super.sueldo() + PRECIO_HORA * horasExtra;
        }
    }

    static class ProgramadorSenior extends Programador {
        private static final int BASE_SENIOR = 2400;
        private static final int PLUS_GUARDIA = 150;
        private final int guardias;

        public ProgramadorSenior(String dni, int horasExtra, int guardias) {
            super(dni, BASE_SENIOR, horasExtra);
            this.guardias = guardias;
        }

        @Override
        public String tipo() {
            return "Senior";
        }

        @Override
        public int sueldo() {
            return super.sueldo() + PLUS_GUARDIA * guardias;
        }
    }

    static class Comercial extends Empleado {
        private static final int BASE_COMERCIAL = 1500;
        private static final int PORCENTAJE = 8;
        private final int ventas;

        public Comercial(String dni, int ventas) {
            super(dni, BASE_COMERCIAL);
            this.ventas = ventas;
        }

        @Override
        public String tipo() {
            return "Comercial";
        }

        @Override
        public int sueldo() {
            return super.sueldo() + ventas * PORCENTAJE / 100;
        }
    }

    static class Gerente extends Empleado {
        private static final int BASE_GERENTE = 3500;

        public Gerente(String dni) {
            super(dni, BASE_GERENTE);
        }

        @Override
        public String tipo() {
            return "Gerente";
        }
    }

    public static void main(String[] args) throws IOException {
        String entrada = new String(System.in.readAllBytes()).trim();
        String[] tk = entrada.isEmpty() ? new String[0] : entrada.split("\\s+");
        int p = 0;
        int n = tk.length == 0 ? 0 : Integer.parseInt(tk[p++]);

        List<Empleado> plantilla = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            String tipo = tk[p++];
            String dni = tk[p++];
            Empleado nuevo = switch (tipo) {
                case "P" -> new Programador(dni, Integer.parseInt(tk[p++]));
                case "S" -> {
                    int horas = Integer.parseInt(tk[p++]);
                    int guardias = Integer.parseInt(tk[p++]);
                    yield new ProgramadorSenior(dni, horas, guardias);
                }
                case "C" -> new Comercial(dni, Integer.parseInt(tk[p++]));
                case "G" -> new Gerente(dni);
                default -> throw new IllegalArgumentException("Tipo desconocido: " + tipo);
            };
            plantilla.add(nuevo);
        }

        StringBuilder salida = new StringBuilder();
        long total = 0;
        for (Empleado e : plantilla) {
            salida.append(e).append('\n');
            total += e.sueldo();
        }
        salida.append("TOTAL ").append(total).append('\n');
        System.out.print(salida);
    }
}
