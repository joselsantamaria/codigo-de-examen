# Código de Examen / Exam Code

[![pipeline status](https://gitlab.com/joselsantamaria/codigo-de-examen/badges/main/pipeline.svg)](https://gitlab.com/joselsantamaria/codigo-de-examen/-/pipelines)

## Español

**Código de Examen** es una serie de ejercicios de programación resueltos, al estilo de un examen universitario, publicada en [La Rebelión](https://www.larebelion.com). Cada artículo trae enunciado, pistas, solución explicada, casos de prueba y errores típicos. Este repositorio reúne el código de cada solución junto con sus casos de prueba, para poder descargarlo y ejecutarlo.

Cada solución se compila y se prueba en CI (GitLab CI) contra sus casos de prueba en cada cambio. El código es exactamente el publicado en los artículos.

Índice de la serie: <https://www.larebelion.com/p/ejercicios.html>

## English

**Exam Code** is a series of solved programming exercises in university-exam style, published on [La Rebelión](https://www.larebelion.com). Each post has a statement, hints, an explained solution, test cases and common mistakes. This repository gathers the code of every solution with its test cases so you can download and run it.

Every solution is compiled and tested in CI (GitLab CI) against its test cases on every change. The code is exactly what the posts publish.

Series index: <https://www.larebelion.com/p/exercises.html>

## Ejercicios / Exercises

| Lenguaje / Language | Directorio / Directory | Tema / Topic | Dificultad / Difficulty | Artículos / Posts |
|---|---|---|---|---|
| C | [`c/matrices-sumas-traspuesta`](c/matrices-sumas-traspuesta) | Matrices y funciones / Matrices and functions | Nivel examen / Exam level | [ES](https://www.larebelion.com/2019/01/gestion-de-matrices-en-c.html) · [EN](https://www.larebelion.com/2026/10/solved-exercise-c-matrix-sums-transpose.html) |
| C | [`c/paso-por-valor-y-referencia`](c/paso-por-valor-y-referencia) | Punteros y paso de parámetros / Pointers and parameter passing | Nivel básico / Basic level | [ES](https://www.larebelion.com/2019/01/paso-por-referencia-y-paso-por-valor-en.html) · [EN](https://www.larebelion.com/2026/10/solved-exercise-pass-by-value-and-by.html) |
| C | [`c/matrices-dinamicas`](c/matrices-dinamicas) | Memoria dinámica y estructuras de datos / Dynamic memory and data structures | Nivel examen / Exam level | [ES](https://www.larebelion.com/2020/04/matrices-dinamicas-en-c.html) · [EN](https://www.larebelion.com/2026/10/solved-exercise-dynamic-matrices-with.html) |
| Python | [`python/matriz-traspuesta-diagonales`](python/matriz-traspuesta-diagonales) | Matrices y listas / Matrices and lists | Nivel examen / Exam level | [ES](https://www.larebelion.com/2026/10/ejercicio-resuelto-traspuesta.html) · [EN](https://www.larebelion.com/2026/10/solved-exercise-matrix-transpose.html) |

Cada ejercicio tiene una edición en español y otra en inglés (`en/`). / Each exercise has a Spanish and an English edition (`en/`).

## Ejecutar las pruebas / Run the tests

```sh
scripts/run-tests.sh          # all / todo
scripts/run-tests.sh c        # C only
scripts/run-tests.sh python   # Python only
```

Requisitos / Requirements: gcc (C11) and python3.

## Licencia / License

- Código / Code: [MIT](LICENSE)
- Enunciados y textos / Statements and text: [CC BY 4.0](LICENSE-content)

Autoría / Authorship: La Rebelión — Código de Examen.
