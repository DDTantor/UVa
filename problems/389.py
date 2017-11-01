from sys import stdin

def int2base(n, b):
    if n == 0:
        return "0"

    digits = []
    while n:
        digits.append(hex(n % b)[2:])
        n //= b

    return "".join(digits[::-1])

for s in stdin:
    a, base, b = s.split()
    if any(a >= int(base) for a in list(map(lambda x: int(x, 36), a))):
        print("ERROR".rjust(7))
    else:
        res = int2base(int(a, int(base)), int(b))
        if len(res) > 7:
            print("ERROR".rjust(7))
        else:
            print(res.rjust(7).upper())
