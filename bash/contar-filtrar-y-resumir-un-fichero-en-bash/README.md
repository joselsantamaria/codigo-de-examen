<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: count, filter and summarize a log file in Bash

**EN:** Bash script with getopts and awk that validates a lab usage log, filters by room and threshold, and totals minutes per user. Explained solution.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-count-filter-and.html](https://www.larebelion.com/2026/11/solved-exercise-count-filter-and.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Fundamentos de programación | Programming fundamentals |
| Lenguaje / Language | Bash | Bash |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.sh` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (6 cases).

## Ejecutar / Run

```sh
cd bash/contar-filtrar-y-resumir-un-fichero-en-bash
bash solution.sh $(cat tests/01.args 2>/dev/null) < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
