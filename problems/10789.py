def IsPrime(n):
    if n == 1:
        return False

    for i in range(2, int(n ** 0.5) + 1):
        if not n % i:
            return False

    return True

t = int(input())
for c in range(1, t + 1):
    print("Case %d: " %c, end = "")
    s = input()
    d = {}
    for c in s:
        d[c] = d.get(c, 0) + 1

    l = list(d.items())
    l.sort()
    res = []
    for i in l:
        if IsPrime(i[1]):
            res.append(i[0])

    res = "".join(res)
    if len(res) == 0:
        print("empty")
    else:
        print(res)
    
