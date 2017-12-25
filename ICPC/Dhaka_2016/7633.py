from sys import stdin
from math import sqrt

def good(s):
    n = int(s)
    return n == round(n ** (1 / 3)) ** 3 and sqrt(n) == round(sqrt(n))

for s in (s for s in stdin if s != "0\n"):
    print("Special" if good(s) else "Ordinary")
