from sys import stdin
from sys import stdout
from math import log10

for s in stdin:
    t, a, b = s.split()
    t, a, b = int(t), int(a), int(b)
    stdout.write("(%s^%s-1)/(%s^%s-1) " % (t, a, t, b))
    if t == 1:
        print("is not an integer with less than 100 digits.")
    elif a == b:
        print(1)
    elif int((a - b) * log10(t)) > 99 or a % b or a < b:
        print("is not an integer with less than 100 digits.")
    else:
        num = int(t) ** int(a) - 1
        den = int(t) ** int(b) - 1
        print(num // den)
    
