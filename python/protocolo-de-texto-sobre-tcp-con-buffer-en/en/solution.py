import sys

DELIMITER = "|"


def handle(message, store):
    """Process one complete, non-empty message. Returns (reply, close)."""
    parts = message.split(None, 2)
    command = parts[0].upper()
    args = parts[1:]
    if command == "SET":
        if len(args) != 2:
            return "ERR 400 arguments", False
        store[args[0]] = args[1]
        return "OK", False
    if command in ("GET", "DEL"):
        if len(args) != 1:
            return "ERR 400 arguments", False
        key = args[0]
        if key not in store:
            return "ERR 404", False
        if command == "GET":
            return "VAL " + store[key], False
        del store[key]
        return "OK", False
    if command == "COUNT":
        if args:
            return "ERR 400 arguments", False
        return "VAL " + str(len(store)), False
    if command == "QUIT":
        if args:
            return "ERR 400 arguments", False
        return "BYE", True
    return "ERR 400 unknown command", False


def simulate(segments):
    """Reassemble the TCP stream. Returns (replies, processed, pending)."""
    store = {}
    buffer = ""
    replies = []
    processed = 0
    for i, segment in enumerate(segments):
        buffer += segment
        while DELIMITER in buffer:
            message, buffer = buffer.split(DELIMITER, 1)
            message = message.strip()
            if not message:
                continue
            reply, close = handle(message, store)
            replies.append(reply)
            processed += 1
            if close:
                discarded = sum(len(s) for s in segments[i + 1:])
                return replies, processed, len(buffer) + discarded
    return replies, processed, len(buffer)


def main():
    lines = sys.stdin.read().split("\n")
    n = int(lines[0]) if lines[0].strip() else 0
    segments = [line.rstrip("\r") for line in lines[1:1 + n]]
    replies, processed, pending = simulate(segments)
    for reply in replies:
        print(reply)
    print(f"SUMMARY processed={processed} pending={pending}")


if __name__ == "__main__":
    main()
