<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Ejercicio resuelto: herencia, constructores y super en Java

**ES:** Ejercicio de examen resuelto en Java: jerarquía de empleados con clase abstracta, constructores encadenados con super y this, y sueldos con super.sueldo().

| | ES | EN |
|---|---|---|
| Post | [java-ejercicio-sobre-herencia.html](https://www.larebelion.com/2021/02/java-ejercicio-sobre-herencia.html) | — |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Programación orientada a objetos | Object-oriented programming |
| Lenguaje / Language | Java | Java |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `Main.java` and `tests/` (`NN.in`, `NN.out`): Spanish edition / edición en español (5 cases).

## Ejecutar / Run

```sh
cd java/herencia-constructores-y-super-en-java
javac -d /tmp/out Main.java && java -cp /tmp/out Main < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
