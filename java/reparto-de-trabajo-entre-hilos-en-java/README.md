<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: splitting work across threads in Java

**EN:** Solved Java exam exercise: split an array among K threads, accumulate with synchronized and wait with join, with tested code and common mistakes.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-splitting-work-across.html](https://www.larebelion.com/2026/10/solved-exercise-splitting-work-across.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Sistemas operativos | Operating systems |
| Lenguaje / Language | Java | Java |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/Main.java` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (6 cases).

## Ejecutar / Run

```sh
cd java/reparto-de-trabajo-entre-hilos-en-java
javac -d /tmp/out Main.java && java -cp /tmp/out Main < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
