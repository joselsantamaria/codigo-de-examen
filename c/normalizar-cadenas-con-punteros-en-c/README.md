<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: normalize a string in place with pointers in C

**EN:** Normalize a C string in place with a read and a write pointer, collapsing spaces and counting words: an exam question solved and explained step by step.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-normalize-string-in.html](https://www.larebelion.com/2026/10/solved-exercise-normalize-string-in.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Fundamentos de programación | Programming fundamentals |
| Lenguaje / Language | C | C |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.c` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (6 cases).

## Ejecutar / Run

```sh
cd c/normalizar-cadenas-con-punteros-en-c
gcc -std=c17 -Wall -o /tmp/sol solution.c && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
