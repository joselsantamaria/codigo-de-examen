import re
import sys

LETTERS = "TRWAGMYFPDXBNJZSQVHLCKE"
NAME_CHARS = "A-Za-zÁÉÍÓÚÜÑáéíóúüñ"

PATTERN = re.compile(
    r"(?P<num>\d{8})(?P<letter>[A-Z]);"
    r"(?P<surname>[" + NAME_CHARS + r"][" + NAME_CHARS + r" -]*), "
    r"(?P<name>[" + NAME_CHARS + r"][" + NAME_CHARS + r" -]*);"
    r"(?P<course>[A-Z]{3}-\d{3});"
    r"(?P<mark>10(?:\.0{1,2})?|\d(?:\.\d{1,2})?)"
)


def parse_line(line):
    m = PATTERN.fullmatch(line)
    if m is None:
        return None
    if LETTERS[int(m.group("num")) % 23] != m.group("letter"):
        return None
    student_id = m.group("num") + m.group("letter")
    return student_id, m.group("surname"), m.group("name"), m.group("course"), float(m.group("mark"))


def main():
    marks = {}
    rejected = []
    valid = 0
    best = None
    for number, raw in enumerate(sys.stdin.read().splitlines(), 1):
        line = raw.strip()
        if not line:
            continue
        data = parse_line(line)
        if data is None:
            rejected.append(number)
            continue
        valid += 1
        student_id, surname, name, course, mark = data
        marks.setdefault(course, []).append(mark)
        if best is None or mark > best[3]:
            best = (student_id, name, surname, mark)
    print(f"VALID: {valid}")
    print(f"REJECTED: {len(rejected)}")
    for k in rejected:
        print(f"REJECTED LINE {k}")
    for course in sorted(marks):
        values = marks[course]
        mean = sum(values) / len(values)
        print(f"{course}: students={len(values)} mean={mean:.2f}")
    if best is not None:
        student_id, name, surname, mark = best
        print(f"BEST: {student_id} {name} {surname} {mark:.2f}")


main()
