t = int(input())
D = [9, 8, 7, 6, 5, 4, 3, 2]

for i in range(t):
    n = int(input())
    res = []
    if n != 0:
        for d in D:
            while (not n % d):
                res.append(d)
                n //= d

        res.sort()
        if n != 1:
            print(-1)
        else:
            print(1 if len(res) == 0 else "".join(list(map(str, res))))
    else:
        print(0)
        
