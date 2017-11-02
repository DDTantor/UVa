def int2base(n, b):
    if n == 0:
        return "0"

    digits = []
    while n:
        digits.append(hex(n % b)[2:])
        n //= b

    return "".join(digits[::-1])

t = int(input())
for i in range(t):
    s = input()
    b, p, a = s.split()[::-1]
    a = int2base(int(a, 16), 2)
    b = int2base(int(b, 16), 2)
    res = int(a, 2) + int(b, 2) if p == "+" else int(a, 2) - int(b, 2)
    print("%s %s %s = %d" %(a.rjust(13, "0"), p, b.rjust(13, "0"), res))
    
