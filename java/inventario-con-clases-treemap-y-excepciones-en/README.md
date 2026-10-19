<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: warehouse inventory with classes, TreeMap and exceptions in Java

**EN:** Java exam exercise on classes, collections and custom checked exceptions: a warehouse inventory with validated stock movements, solved and explained.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-warehouse-inventory.html](https://www.larebelion.com/2026/10/solved-exercise-warehouse-inventory.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Programación orientada a objetos | Object-oriented programming |
| Lenguaje / Language | Java | Java |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/Main.java` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (4 cases).

## Ejecutar / Run

```sh
cd java/inventario-con-clases-treemap-y-excepciones-en
javac -d /tmp/out Main.java && java -cp /tmp/out Main < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
