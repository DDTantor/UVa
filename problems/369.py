from sys import stdin
from math import factorial

for s in (s for s in stdin if s.replace(" ", "") != "00\n"):
    n, m = map(int, [x for x in s[:-1].split(" ") if x != ""])
    res = factorial(n) // (factorial(m) * factorial(n - m))
    print("%d things taken %d at a time is %d exactly." %(n, m, res))
