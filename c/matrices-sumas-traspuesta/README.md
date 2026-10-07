# Matrices en C: sumas, traza, antidiagonal, simetría y traspuesta / Matrices in C: sums, trace, antidiagonal, symmetry and transpose

**ES:** Una cuadrícula de N×N sensores de humedad (N ≤ 10). Lee la matriz y escribe las sumas por filas y por columnas, la traza, la antidiagonal, si es simétrica y su traspuesta, con formato exacto y mensajes de error para entrada inválida o incompleta.

**EN:** An N×N grid of humidity sensors (N ≤ 10). Read the matrix and print row and column sums, trace, antidiagonal, whether it is symmetric, and its transpose, in an exact format with error messages for invalid or incomplete input.

| | ES | EN |
|---|---|---|
| Post | [gestion-de-matrices-en-c.html](https://www.larebelion.com/2019/01/gestion-de-matrices-en-c.html) | [solved-exercise-c-matrix-sums-transpose.html](https://www.larebelion.com/2026/10/solved-exercise-c-matrix-sums-transpose.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Matrices y funciones | Matrices and functions |
| Lenguaje / Language | C | C |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `solution.c` and `tests/` (`NN.in`, `NN.out`): Spanish edition (6 cases). / Edición en español.
- `en/solution.c` and `en/tests/`: English edition (same program, English messages). / Edición en inglés.

## Ejecutar / Run

```sh
cd c/matrices-sumas-traspuesta
gcc -std=c11 -Wall -o /tmp/sol solution.c && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
