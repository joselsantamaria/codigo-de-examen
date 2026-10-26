<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: matrix rotate and shift commands in C

**EN:** C exam exercise: read a matrix, apply circular column shifts and 90-degree rotations, and print it aligned with the product of every row and column.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-matrix-rotate-and-shift.html](https://www.larebelion.com/2026/10/solved-exercise-matrix-rotate-and-shift.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Fundamentos de programación | Programming fundamentals |
| Lenguaje / Language | C | C |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.c` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (6 cases).

## Ejecutar / Run

```sh
cd c/matriz-con-ordenes-de-giro-y-desplazamiento-en-c
gcc -std=c17 -Wall -o /tmp/sol solution.c && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
