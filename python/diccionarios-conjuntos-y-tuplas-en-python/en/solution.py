import sys


def read_records(lines):
    """Return (attendees, duplicates, ignored).

    attendees: dict workshop -> set of students, in first-appearance order.
    """
    records = set()        # (workshop, student) tuples already seen
    attendees = {}
    duplicates = 0
    ignored = 0
    for line in lines:
        parts = line.split()
        if not parts:
            continue                  # blank line: not counted
        if len(parts) != 2:
            ignored += 1
            continue
        pair = (parts[0], parts[1])
        if pair in records:
            duplicates += 1
            continue
        records.add(pair)
        workshop, student = pair
        if workshop not in attendees:
            attendees[workshop] = set()
        attendees[workshop].add(student)
    return attendees, duplicates, ignored


def common_to_all(attendees):
    """Students present in every workshop (empty set if there are none)."""
    if not attendees:
        return set()
    groups = list(attendees.values())
    common = set(groups[0])           # copy: never touch the original
    for students in groups[1:]:
        common &= students
    return common


def main():
    lines = sys.stdin.read().splitlines()
    attendees, duplicates, ignored = read_records(lines)
    for workshop, students in attendees.items():
        print(f"{workshop}: {len(students)}")
    common = common_to_all(attendees)
    if common:
        print("ALL: " + ", ".join(sorted(common)))
    else:
        print("ALL: -")
    print(f"DUPLICATES: {duplicates}")
    print(f"IGNORED: {ignored}")


if __name__ == "__main__":
    main()
