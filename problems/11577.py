t = int(input())
for i in range(t):
    s = input()
    d = {}
    for c in s:
        if c.isalpha():
            d[c.lower()] = d.get(c.lower(), 0) + 1

    l = list(d.items())
    l.sort(key = lambda x: (-x[1], x[0]))
    res = ""
    best = l[0][1]
    for i in l:
        if i[1] == best:
            res += i[0]

    print(res)
