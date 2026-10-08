# scaffold-version: 2
# Runs a SQL solution on SQLite: stdin is the setup script, the file the statements.
import sqlite3, sys
setup = sys.stdin.read()
solution = open(sys.argv[1], encoding="utf-8").read()
db = sqlite3.connect(":memory:")
db.executescript(setup)
def fmt(v):
    if v is None: return "NULL"
    if isinstance(v, float) and v.is_integer(): return str(int(v))
    if isinstance(v, float): return ("%.2f" % v)
    return str(v)
for stmt in [s for s in solution.split(";") if s.strip()]:
    cur = db.execute(stmt)
    if cur.description:
        print("|".join(d[0] for d in cur.description))
        for row in cur.fetchall():
            print("|".join(fmt(v) for v in row))
db.commit()
