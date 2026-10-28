<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: array sum and maximum in x86-64 assembly

**EN:** Read an integer array, compute its sum and maximum with loops in x86-64 assembly (Intel syntax), and print the result by calling scanf and printf.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-array-sum-and-maximum.html](https://www.larebelion.com/2026/10/solved-exercise-array-sum-and-maximum.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Fundamentos de programación | Programming fundamentals |
| Lenguaje / Language | Ensamblador | Assembly |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.s` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (6 cases).

## Ejecutar / Run

```sh
cd asm/suma-y-maximo-de-un-vector-en-ensamblador-x86-64
gcc -no-pie -o /tmp/sol solution.s && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
