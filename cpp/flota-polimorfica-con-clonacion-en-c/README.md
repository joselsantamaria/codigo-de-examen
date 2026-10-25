<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Ejercicio resuelto: flota polimórfica con clonación en C++

**ES:** Ejercicio resuelto en C++ de herencia y polimorfismo: flota de vehículos, clase abstracta, remolque decorador y copia profunda con clonar y unique_ptr.

| | ES | EN |
|---|---|---|
| Post | [ejercicio-resuelto-flota-polimorfica.html](https://www.larebelion.com/2026/10/ejercicio-resuelto-flota-polimorfica.html) | — |
| Dificultad / Difficulty | Nivel nota | Top-grade level |
| Tema / Topic | Programación orientada a objetos | Object-oriented programming |
| Lenguaje / Language | C++ | C++ |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `solution.cpp` and `tests/` (`NN.in`, `NN.out`): Spanish edition / edición en español (6 cases).

## Ejecutar / Run

```sh
cd cpp/flota-polimorfica-con-clonacion-en-c
g++ -std=c++20 -Wall -o /tmp/sol solution.cpp && /tmp/sol < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
