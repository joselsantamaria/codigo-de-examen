<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: exact rank and determinant with Bareiss in C

**EN:** Solved C exam question: column products, rank and exact determinant of an integer matrix using Bareiss elimination, row pivoting and long long.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-exact-rank-and.html](https://www.larebelion.com/2026/10/solved-exercise-exact-rank-and.html) |
| Dificultad / Difficulty | Nivel nota | Top-grade level |
| Tema / Topic | Fundamentos de programación | Programming fundamentals |
| Lenguaje / Language | C | C |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.c` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (6 cases).

## Ejecutar / Run

```sh
cd c/rango-y-determinante-exactos-con-bareiss-en-c
gcc -std=c17 -Wall -o /tmp/sol solution.c && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
