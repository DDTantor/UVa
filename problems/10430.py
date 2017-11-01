from sys import stdin
from fractions import gcd

print("Dear GOD, Pardon Me")

for t, s in enumerate(stdin):
    if t:
        print()
    s = s.split()
    t, n = int(s[0]), int(s[1])
    x = 1
    k = t
    for i in range(1, n):
        x += k
        k *= t
        
    print("X = %d\nK = %d" % (x, k))
