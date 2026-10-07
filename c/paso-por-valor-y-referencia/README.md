# Paso por valor y por referencia en C / Pass by value and by reference in C

**ES:** Tiempos de los tramos de una marcha ciclista dados como horas, minutos y segundos sin normalizar. Con tres funciones obligatorias (por valor y por puntero) hay que normalizar cada tramo, sumar el total y señalar el tramo más largo.

**EN:** Stage times of a cycling event given as unnormalised hours, minutes and seconds. Using three mandatory functions (by value and by pointer), normalise each stage, add up the total and report the longest stage.

| | ES | EN |
|---|---|---|
| Post | [paso-por-referencia-y-paso-por-valor-en.html](https://www.larebelion.com/2019/01/paso-por-referencia-y-paso-por-valor-en.html) | [solved-exercise-pass-by-value-and-by.html](https://www.larebelion.com/2026/10/solved-exercise-pass-by-value-and-by.html) |
| Dificultad / Difficulty | Nivel básico | Basic level |
| Tema / Topic | Punteros y paso de parámetros | Pointers and parameter passing |
| Lenguaje / Language | C | C |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `solution.c` and `tests/` (`NN.in`, `NN.out`): Spanish edition (6 cases). / Edición en español.
- `en/solution.c` and `en/tests/`: English edition (same program, English messages). / Edición en inglés.

## Ejecutar / Run

```sh
cd c/paso-por-valor-y-referencia
gcc -std=c11 -Wall -o /tmp/sol solution.c && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
