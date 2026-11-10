<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: JOINs, subqueries and GROUP BY in SQL

**EN:** Modules below their programme's average in SQLite: JOIN, derived subquery, GROUP BY, HAVING and NULL handling, with an explained solution and tests.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-joins-subqueries-and.html](https://www.larebelion.com/2026/11/solved-exercise-joins-subqueries-and.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Bases de datos | Databases |
| Lenguaje / Language | SQL | SQL |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.sql` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (5 cases).

## Ejecutar / Run

```sh
cd sql/joins-subconsultas-y-agrupaciones-en-sql
python3 ../../scripts/sqlrun.py solution.sql < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
