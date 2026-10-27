<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved Exercise: 6 POSIX Threads That Identify Themselves in C

**EN:** Solved OS exam exercise in C: six POSIX threads with their own logical ID, pthread_create, pthread_join and deterministic output, with tests.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-6-posix-threads-that.html](https://www.larebelion.com/2026/10/solved-exercise-6-posix-threads-that.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Sistemas operativos | Operating systems |
| Lenguaje / Language | C | C |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.c` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (6 cases).

## Ejecutar / Run

```sh
cd c/6-hilos-posix-que-se-identifican-en-c
gcc -std=c17 -Wall -o /tmp/sol solution.c && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
