from sys import stdin
from math import factorial

for n in list(map(int, (s for s in stdin))):
    print("%d!\n%d" %(n, factorial(n)))
