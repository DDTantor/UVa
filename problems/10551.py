from sys import stdin

def int2base(n, b):
    if n == 0:
        return "0"

    digits = []
    while n:
        digits.append(hex(n % b)[2:])
        n //= b

    return "".join(digits[::-1])

for s in (s for s in stdin if s != "0\n"):
    base, a, b = s.split()
    print(int2base(int(a, int(base)) % int(b, int(base)), int(base)))
