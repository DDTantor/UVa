t = int(input())

for i in range(t):
    s = input()
    a, b, c = s.replace("+", "").replace("=", "").split()
    res = 0
    if all(x == 1 for x in list(map(lambda x: int(x, 19), a + b + c))):
        res = int(sum(list(map(int, a + b))) == sum(list(map(int, c))))
    else:
        for j in range(2, 19):
            if any(x >= j for x in list(map(lambda x: int(x, 19), a + b + c))):
                continue

            if int(a, j) + int(b, j) == int(c, j):
                res = j
                break

    print(res)
