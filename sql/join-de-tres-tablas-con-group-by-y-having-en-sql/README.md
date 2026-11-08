<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Ejercicio resuelto: JOIN de tres tablas con GROUP BY y HAVING en SQL

**ES:** Consulta SQL resuelta paso a paso: une barrios, hortelanos y cosechas, agrega con SUM y COUNT DISTINCT y filtra grupos con HAVING en SQLite.

| | ES | EN |
|---|---|---|
| Post | [ejercicio-resuelto-join-de-tres-tablas.html](https://www.larebelion.com/2026/11/ejercicio-resuelto-join-de-tres-tablas.html) | — |
| Dificultad / Difficulty | Nivel básico | Basic level |
| Tema / Topic | Bases de datos | Databases |
| Lenguaje / Language | SQL | SQL |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `solution.sql` and `tests/` (`NN.in`, `NN.out`): Spanish edition / edición en español (4 cases).

## Ejecutar / Run

```sh
cd sql/join-de-tres-tablas-con-group-by-y-having-en-sql
python3 ../../scripts/sqlrun.py solution.sql < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
