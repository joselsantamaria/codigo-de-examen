# Matrices dinámicas con malloc y free en C / Dynamic matrices with malloc and free in C

**ES:** Una matriz F×C reservada con malloc se rota 90 grados en sentido horario y después se eliminan las filas formadas solo por ceros, liberando la memoria sin fugas.

**EN:** An F×C matrix allocated with malloc is rotated 90 degrees clockwise, then rows made only of zeros are removed, freeing memory without leaks.

| | ES | EN |
|---|---|---|
| Post | [matrices-dinamicas-en-c.html](https://www.larebelion.com/2020/04/matrices-dinamicas-en-c.html) | [solved-exercise-dynamic-matrices-with.html](https://www.larebelion.com/2026/10/solved-exercise-dynamic-matrices-with.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Memoria dinámica y estructuras de datos | Dynamic memory and data structures |
| Lenguaje / Language | C | C |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `solution.c` and `tests/` (`NN.in`, `NN.out`): Spanish edition (6 cases). / Edición en español.
- `en/solution.c` and `en/tests/`: English edition (same program, English messages). / Edición en inglés.

## Ejecutar / Run

```sh
cd c/matrices-dinamicas
gcc -std=c11 -Wall -o /tmp/sol solution.c && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
