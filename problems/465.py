from sys import stdin
from math import log2

for s in stdin:
    print(s.replace("\n", ""))
    s = s.split()
    s[0] = int(s[0])
    s[2] = int(s[2])

    first_too_big = s[0].bit_length() >= 32
    second_too_big = s[2].bit_length() >= 32
    res_too_big = ((s[0] + s[2]).bit_length() if s[1] == "+" else (s[0] * s[2]).bit_length()) >= 32

    if first_too_big:
        print("first number too big")

    if second_too_big:
        print("second number too big")

    if res_too_big:
        print("result too big")

