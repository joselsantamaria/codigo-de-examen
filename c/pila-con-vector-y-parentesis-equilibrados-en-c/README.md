<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Ejercicio resuelto: pila con vector y paréntesis equilibrados en C / Solved exercise: array-based stack and balanced brackets in C

**ES:** Implementa una pila de tamaño fijo sobre un vector en C y úsala para comprobar si una fórmula tiene sus paréntesis, corchetes y llaves equilibrados.

**EN:** Build a fixed-size stack over an array in C and use it to check whether a formula has its parentheses, brackets and braces balanced.

| | ES | EN |
|---|---|---|
| Post | [ejercicio-resuelto-pila-con-vector-y.html](https://www.larebelion.com/2026/10/ejercicio-resuelto-pila-con-vector-y.html) | [solved-exercise-array-based-stack-and.html](https://www.larebelion.com/2026/10/solved-exercise-array-based-stack-and.html) |
| Dificultad / Difficulty | Nivel básico | Basic level |
| Tema / Topic | Estructuras de datos | Data structures |
| Lenguaje / Language | C | C |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `solution.c` and `tests/` (`NN.in`, `NN.out`): Spanish edition / edición en español (5 cases).
- `en/solution.c` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (5 cases).

## Ejecutar / Run

```sh
cd c/pila-con-vector-y-parentesis-equilibrados-en-c
gcc -std=c17 -Wall -o /tmp/sol solution.c && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
