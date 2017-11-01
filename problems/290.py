from sys import stdin
from sys import stdout


def int2base(n, b):
    if n == 0:
        return "0"

    digits = []
    while n:
        digits.append(hex(n % b)[2:])
        n //= b

    return "".join(digits[::-1])

for x in stdin:
    t = s = x.split("\n")[0]
    for i in range(15, 1, -1):
        s = t
        if all(a < i for a in list(map(lambda x: int(x, 16), list(x)[:-1]))):
            step = 0
            while s != s[::-1] and step < 101:
                s = int2base(int(s, i) + int(s[::-1], i), i)
                step += 1
                
            stdout.write("%d" %step)
        else:
            stdout.write("?")

        if i != 2:
            stdout.write(" ")

    print()
    
