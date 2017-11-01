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
    base, b, a = s.split()
    if any(c >= int(base) for c in list(map(lambda x: int(x, 36), a))):
        print("%s is an illegal base %s number" %(a, base))
    else:
        res = int2base(int(a, int(base)), int(b))
        print("%s base %s = %s base %s" %(a, base, res.upper(), b))
        

    
