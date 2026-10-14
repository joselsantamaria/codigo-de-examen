<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: Java serialization with transient fields

**EN:** Serialize a warehouse to a working file with Serializable and transient, then reload it with readObject and rebuild the derived total value.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-java-serialization-with.html](https://www.larebelion.com/2026/10/solved-exercise-java-serialization-with.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Programación orientada a objetos | Object-oriented programming |
| Lenguaje / Language | Java | Java |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/Main.java` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (6 cases).

## Ejecutar / Run

```sh
cd java/serializacion-con-transient-en-java
javac -d /tmp/out Main.java && java -cp /tmp/out Main < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
