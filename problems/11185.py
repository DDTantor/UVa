from sys import stdin

def int2base(n, b):
    if n == 0:
        return "0"

    digits = []
    while n:
        digits.append(hex(n % b)[2:])
        n //= b

    return "".join(digits[::-1])

for x in (x for x in list(map(int, stdin)) if x >= 0):
    print(int2base(x, 3))
