import sys


def read_input(data):
    """Separate the width (first line) from the rest of the text."""
    parts = data.split("\n", 1)
    width = int(parts[0])
    text = parts[1] if len(parts) > 1 else ""
    return width, text


def split_word(word, width):
    """Return the list of pieces of a word; none is longer than width."""
    pieces = []
    while len(word) > width:
        pieces.append(word[:width - 1] + "-")
        word = word[width - 1:]
    pieces.append(word)
    return pieces


def wrap(text, width):
    """Distribute the text over lines of at most 'width' characters."""
    tokens = []
    for word in text.split():
        tokens.extend(split_word(word, width))
    lines = []
    current = ""
    for token in tokens:
        if current == "":
            current = token
        elif len(current) + 1 + len(token) <= width:
            current += " " + token
        else:
            lines.append(current)
            current = token
    if current:
        lines.append(current)
    return lines


def fill_percent(lines, width):
    """Integer (truncated) percentage of characters used."""
    used = sum(len(line) for line in lines)
    return 100 * used // (len(lines) * width)


def main():
    width, text = read_input(sys.stdin.read())
    lines = wrap(text, width)
    if not lines:
        print("No text")
        return
    for n, line in enumerate(lines, start=1):
        print(f"{n:02d}: {line}")
    print(f"Lines: {len(lines)}, fill: {fill_percent(lines, width)}%")


main()
