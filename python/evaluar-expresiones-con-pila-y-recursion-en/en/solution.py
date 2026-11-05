import sys
from collections import deque

PREC = {'+': 1, '-': 1, '*': 2, '/': 2}


class DivisionByZero(Exception):
    pass


def tokenize(line):
    queue = deque()
    i = 0
    n = len(line)
    while i < n:
        c = line[i]
        if c.isspace():
            i += 1
        elif c.isdigit():
            j = i
            while j < n and line[j].isdigit():
                j += 1
            queue.append(line[i:j])
            i = j
        else:
            queue.append(c)
            i += 1
    return queue


def divide(a, b):
    if b == 0:
        raise DivisionByZero()
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b >= 0) else -q


def apply_op(op, a, b):
    if op == '+':
        return a + b
    if op == '-':
        return a - b
    if op == '*':
        return a * b
    return divide(a, b)


def to_postfix(tokens):
    queue = deque(tokens)
    output = []
    stack = []
    while queue:
        t = queue.popleft()
        if t.isdigit():
            output.append(t)
        elif t == '(':
            stack.append(t)
        elif t == ')':
            while stack[-1] != '(':
                output.append(stack.pop())
            stack.pop()
        else:
            while stack and stack[-1] != '(' and PREC[stack[-1]] >= PREC[t]:
                output.append(stack.pop())
            stack.append(t)
    while stack:
        output.append(stack.pop())
    return output


def eval_postfix(postfix):
    stack = []
    for t in postfix:
        if t.isdigit():
            stack.append(int(t))
        else:
            b = stack.pop()
            a = stack.pop()
            stack.append(apply_op(t, a, b))
    return stack[0]


def eval_recursive(tokens):
    queue = deque(tokens)

    def expression():
        value = term()
        while queue and queue[0] in ('+', '-'):
            op = queue.popleft()
            value = apply_op(op, value, term())
        return value

    def term():
        value = factor()
        while queue and queue[0] in ('*', '/'):
            op = queue.popleft()
            value = apply_op(op, value, factor())
        return value

    def factor():
        t = queue.popleft()
        if t == '(':
            value = expression()
            queue.popleft()
            return value
        return int(t)

    return expression()


def main():
    lines = sys.stdin.read().split('\n')
    n = int(lines[0].strip())
    result = []
    for k in range(1, n + 1):
        line = lines[k] if k < len(lines) else ''
        tokens = list(tokenize(line))
        if not tokens:
            result.append('EMPTY')
            continue
        postfix = to_postfix(tokens)
        text = ' '.join(postfix)
        try:
            value = eval_postfix(postfix)
            if value != eval_recursive(tokens):
                raise RuntimeError('the two evaluations disagree')
            result.append(text + ' = ' + str(value))
        except DivisionByZero:
            result.append(text + ' = ERROR')
    print('\n'.join(result))


main()
