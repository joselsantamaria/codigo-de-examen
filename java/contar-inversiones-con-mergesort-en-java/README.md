<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Ejercicio resuelto: contar inversiones con mergesort en Java

**ES:** Ejercicio de examen resuelto en Java: contar parejas desordenadas de un vector en O(n log n) modificando mergesort, con pistas, trazas y errores típicos.

| | ES | EN |
|---|---|---|
| Post | [ejercicio-resuelto-contar-inversiones.html](https://www.larebelion.com/2026/10/ejercicio-resuelto-contar-inversiones.html) | — |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Algoritmia | Algorithms |
| Lenguaje / Language | Java | Java |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `Main.java` and `tests/` (`NN.in`, `NN.out`): Spanish edition / edición en español (6 cases).

## Ejecutar / Run

```sh
cd java/contar-inversiones-con-mergesort-en-java
javac -d /tmp/out Main.java && java -cp /tmp/out Main < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
