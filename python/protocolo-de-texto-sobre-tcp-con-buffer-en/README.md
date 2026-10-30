<!-- exercises-repo-sync:generated — delete this line to edit this README by hand -->
# Solved exercise: a TCP text protocol with a receive buffer in Python

**EN:** Simulate a TCP server in Python that reassembles fragmented messages in a buffer, parses them and replies, with tested code, hints and typical mistakes.

| | ES | EN |
|---|---|---|
| Post | — | [solved-exercise-tcp-text-protocol-with.html](https://www.larebelion.com/2026/10/solved-exercise-tcp-text-protocol-with.html) |
| Dificultad / Difficulty | Nivel examen | Exam level |
| Tema / Topic | Redes | Networking |
| Lenguaje / Language | Python | Python |

The full explanation, hints and traces are in the posts above. / La explicación completa, las pistas y las trazas están en los artículos enlazados.

## Estructura / Layout

- `en/solution.py` and `en/tests/` (`NN.in`, `NN.out`): English edition / edición en inglés (5 cases).

## Ejecutar / Run

```sh
cd python/protocolo-de-texto-sobre-tcp-con-buffer-en
python3 solution.py < tests/01.in | diff - tests/01.out
```

To run every case of every exercise: `scripts/run-tests.sh` (from the repository root).

Code: MIT. Statements and text: CC BY 4.0. Author: La Rebelión — Código de Examen.
