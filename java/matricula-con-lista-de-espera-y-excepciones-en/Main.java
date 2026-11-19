import java.io.*;
import java.util.*;

public class Main {

    static class MatriculaException extends Exception {
        MatriculaException(String mensaje) {
            super(mensaje);
        }
    }

    static class Asignatura {
        private final String codigo;
        private final int plazas;
        private final Set<String> matriculados = new LinkedHashSet<>();
        private final Deque<String> espera = new ArrayDeque<>();

        Asignatura(String codigo, int plazas) {
            this.codigo = codigo;
            this.plazas = plazas;
        }

        private boolean figura(String alumno) {
            return matriculados.contains(alumno) || espera.contains(alumno);
        }

        // Devuelve 0 si obtiene plaza; si no, su posicion en la espera (desde 1).
        int matricular(String alumno) throws MatriculaException {
            if (figura(alumno)) {
                throw new MatriculaException(alumno + " ya figura en " + codigo);
            }
            if (matriculados.size() < plazas) {
                matriculados.add(alumno);
                return 0;
            }
            espera.addLast(alumno);
            return espera.size();
        }

        // Devuelve el alumno admitido desde la espera, o null si nadie sube.
        String darDeBaja(String alumno) throws MatriculaException {
            if (matriculados.remove(alumno)) {
                String siguiente = espera.pollFirst();
                if (siguiente != null) {
                    matriculados.add(siguiente);
                }
                return siguiente;
            }
            if (espera.remove(alumno)) {
                return null;
            }
            throw new MatriculaException(alumno + " no figura en " + codigo);
        }

        String resumen() {
            return codigo + " " + matriculados.size() + "/" + plazas
                    + " matriculados=" + unir(matriculados) + " espera=" + unir(espera);
        }

        private static String unir(Collection<String> nombres) {
            return nombres.isEmpty() ? "-" : String.join(",", nombres);
        }
    }

    static class Secretaria {
        private final Map<String, Asignatura> asignaturas = new TreeMap<>();

        void crearAsignatura(String codigo, String textoPlazas) throws MatriculaException {
            if (asignaturas.containsKey(codigo)) {
                throw new MatriculaException("asignatura duplicada " + codigo);
            }
            if (!textoPlazas.matches("[0-9]+")) {
                throw new MatriculaException("plazas incorrectas " + textoPlazas);
            }
            int plazas;
            try {
                plazas = Integer.parseInt(textoPlazas);
            } catch (NumberFormatException e) {
                throw new MatriculaException("plazas incorrectas " + textoPlazas);
            }
            if (plazas < 1) {
                throw new MatriculaException("plazas incorrectas " + textoPlazas);
            }
            asignaturas.put(codigo, new Asignatura(codigo, plazas));
        }

        Asignatura buscar(String codigo) throws MatriculaException {
            Asignatura asignatura = asignaturas.get(codigo);
            if (asignatura == null) {
                throw new MatriculaException("asignatura desconocida " + codigo);
            }
            return asignatura;
        }

        List<String> informe() {
            if (asignaturas.isEmpty()) {
                return List.of("sin asignaturas");
            }
            List<String> lineas = new ArrayList<>();
            for (Asignatura asignatura : asignaturas.values()) {
                lineas.add(asignatura.resumen());
            }
            return lineas;
        }
    }

    private static void exigirTokens(String[] t, int cuantos) throws MatriculaException {
        if (t.length != cuantos) {
            throw new MatriculaException("orden mal formada");
        }
    }

    static List<String> ejecutar(Secretaria secretaria, String[] t) throws MatriculaException {
        return switch (t[0]) {
            case "ASIGNATURA" -> {
                exigirTokens(t, 3);
                secretaria.crearAsignatura(t[1], t[2]);
                yield List.of("OK asignatura " + t[1]);
            }
            case "MATRICULA" -> {
                exigirTokens(t, 3);
                int posicion = secretaria.buscar(t[2]).matricular(t[1]);
                yield List.of(posicion == 0
                        ? "MATRICULADO " + t[1] + " " + t[2]
                        : "ESPERA " + t[1] + " " + t[2] + " #" + posicion);
            }
            case "BAJA" -> {
                exigirTokens(t, 3);
                String admitido = secretaria.buscar(t[2]).darDeBaja(t[1]);
                List<String> lineas = new ArrayList<>();
                lineas.add("BAJA " + t[1] + " " + t[2]);
                if (admitido != null) {
                    lineas.add("ADMITIDO " + admitido + " " + t[2]);
                }
                yield lineas;
            }
            case "INFORME" -> {
                exigirTokens(t, 1);
                yield secretaria.informe();
            }
            default -> throw new MatriculaException("orden mal formada");
        };
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        Secretaria secretaria = new Secretaria();
        StringBuilder salida = new StringBuilder();
        String linea;
        while ((linea = in.readLine()) != null) {
            linea = linea.trim();
            if (linea.isEmpty()) {
                continue;
            }
            String[] tokens = linea.split("\\s+");
            try {
                for (String resultado : ejecutar(secretaria, tokens)) {
                    salida.append(resultado).append('\n');
                }
            } catch (MatriculaException e) {
                salida.append("ERROR ").append(e.getMessage()).append('\n');
            }
        }
        System.out.print(salida);
    }
}
