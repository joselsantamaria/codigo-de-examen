import sys
from abc import ABC, abstractmethod


def money(cents):
    """Format non-negative integer cents as 20.48."""
    return f"{cents // 100}.{cents % 100:02d}"


class Line(ABC):
    RANK = 9  # tie-break position by type; subclasses override it

    def __init__(self, name, price, quantity):
        if price <= 0 or quantity <= 0:
            raise ValueError("price and quantity must be positive")
        self.name = name
        self.price = price
        self.quantity = quantity

    @abstractmethod
    def amount(self):
        """Amount of the line in cents."""

    @abstractmethod
    def detail(self):
        """Text between the name and the equals sign."""

    def __eq__(self, other):
        if not isinstance(other, Line):
            return NotImplemented
        return (type(self) is type(other)
                and self.name == other.name
                and self.price == other.price)

    def __hash__(self):
        return hash((type(self), self.name, self.price))

    def __add__(self, other):
        if not isinstance(other, Line):
            return NotImplemented
        if self != other:
            raise ValueError("cannot add different products")
        return type(self)(self.name, self.price,
                          self.quantity + other.quantity)

    def sort_key(self):
        return (-self.amount(), self.name, self.RANK, self.price)

    def __str__(self):
        return f"{self.name} {self.detail()} = {money(self.amount())}"


class UnitLine(Line):
    RANK = 1

    def amount(self):
        return self.price * self.quantity

    def detail(self):
        return f"{self.quantity} x {money(self.price)}"


class WeightLine(Line):
    RANK = 0

    def amount(self):
        # price in cents per kg, quantity in grams; halves round up
        return (self.price * self.quantity + 500) // 1000

    def detail(self):
        return f"{self.quantity} g at {money(self.price)}/kg"


class Receipt:
    def __init__(self):
        self._lines = []

    def add(self, line):
        for i, existing in enumerate(self._lines):
            if existing == line:
                self._lines[i] = existing + line
                return
        self._lines.append(line)

    def __len__(self):
        return len(self._lines)

    def __iter__(self):
        return iter(sorted(self._lines, key=Line.sort_key))

    def total(self):
        return sum(line.amount() for line in self._lines)

    def __str__(self):
        rows = [str(line) for line in self]
        rows.append(f"Lines: {len(self)}")
        rows.append(f"TOTAL: {money(self.total())}")
        return "\n".join(rows)


KINDS = {"U": UnitLine, "W": WeightLine}


def main():
    receipt = Receipt()
    for text in sys.stdin:
        parts = text.split()
        if not parts:
            continue
        cls = KINDS[parts[0]]
        receipt.add(cls(parts[1], int(parts[2]), int(parts[3])))
    print(receipt)


main()
