# Traspuesta, diagonales y sumas de matrices en Python / Matrix transpose, diagonals and row sums in Python

**ES:** Matriz de trayectos entre estaciones de bicicletas compartidas: traspuesta, flujos de salida y entrada, diagonales, pares asimétricos y estación con mayor balance.

**EN:** Trip matrix between shared-bike stations: transpose, outgoing and incoming flows, diagonals, asymmetric pairs and the station with the best balance.

| | ES | EN |
|---|---|---|
| Post | [ejercicio-resuelto-traspuesta.html](https://www.larebelion.com/2026/10/ejercicio-resuelto-traspuesta.html) | [solved-exercise-matrix-transpose.html](https://www.larebelion.com/2026/10/solved-exercise-matrix-transpose.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Matrices y listas | Matrices and lists |
| Lenguaje / Language | Python | Python |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `solution.py` and `tests/` (`NN.in`, `NN.out`): Spanish edition (5 cases). / Edición en español.
- `en/solution.py` and `en/tests/`: English edition (same program, English messages). / Edición en inglés.

## Ejecutar / Run

```sh
cd python/matriz-traspuesta-diagonales
python3 solution.py < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
