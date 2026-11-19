<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Ejercicio resuelto: matrícula con lista de espera y excepciones en Java

**ES:** Examen de Java resuelto: secretaría de matrícula con clases, TreeMap, LinkedHashSet, lista de espera con ArrayDeque y una excepción comprobada propia.

| | ES | EN |
|---|---|---|
| Post | [ejercicio-resuelto-matricula-con-lista.html](https://www.larebelion.com/2026/11/ejercicio-resuelto-matricula-con-lista.html) | — |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Programación orientada a objetos | Object-oriented programming |
| Lenguaje / Language | Java | Java |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `Main.java` and `tests/` (`NN.in`, `NN.out`): Spanish edition / edición en español (6 cases).

## Ejecutar / Run

```sh
cd java/matricula-con-lista-de-espera-y-excepciones-en
javac -d /tmp/out Main.java && java -cp /tmp/out Main < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
