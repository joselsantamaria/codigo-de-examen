<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: linked list with classes and new/delete in C++

**EN:** Singly linked list in C++ with head and tail pointers, removal, in-place reversal and the rule of three: exam statement, hints, solution and tests.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-linked-list-with.html](https://www.larebelion.com/2026/11/solved-exercise-linked-list-with.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Estructuras de datos | Data structures |
| Lenguaje / Language | C++ | C++ |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.cpp` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (5 cases).

## Ejecutar / Run

```sh
cd cpp/lista-enlazada-con-clases-y-new-delete-en-c
g++ -std=c++20 -Wall -o /tmp/sol solution.cpp && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
