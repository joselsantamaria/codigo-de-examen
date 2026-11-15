<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Ejercicio resuelto: hilos que reparten un cálculo en Python / Solved exercise: threads that split a calculation in Python

**ES:** Reparte lecturas de sensores entre hilos en Python, calcula resúmenes parciales y únelos sin condiciones de carrera ni resultados mal ordenados.

**EN:** Split sensor readings across Python threads, compute partial summaries and merge them without race conditions or output that depends on thread timing.

| | ES | EN |
|---|---|---|
| Post | [ejercicio-resuelto-hilos-que-reparten.html](https://www.larebelion.com/2026/11/ejercicio-resuelto-hilos-que-reparten.html) | [solved-exercise-threads-that-split.html](https://www.larebelion.com/2026/11/solved-exercise-threads-that-split.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Sistemas operativos | Operating systems |
| Lenguaje / Language | Python | Python |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `solution.py` and `tests/` (`NN.in`, `NN.out`): Spanish edition / edición en español (5 cases).
- `en/solution.py` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (5 cases).

## Ejecutar / Run

```sh
cd python/hilos-que-reparten-un-calculo-en-python
python3 solution.py < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
