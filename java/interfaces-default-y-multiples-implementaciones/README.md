<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: interfaces, default methods and multiple implementation in Java

**EN:** Solved Java exercise on interfaces: contracts, classes implementing several interfaces and default methods, with tested code and a full explanation.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-interfaces-default.html](https://www.larebelion.com/2026/10/solved-exercise-interfaces-default.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Programación orientada a objetos | Object-oriented programming |
| Lenguaje / Language | Java | Java |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/Main.java` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (5 cases).

## Ejecutar / Run

```sh
cd java/interfaces-default-y-multiples-implementaciones
javac -d /tmp/out Main.java && java -cp /tmp/out Main < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
