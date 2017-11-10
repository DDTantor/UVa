from sys import stdin

for s in stdin:
    d = {}
    s = ''.join([c for c in s if c.isalpha()])
    for c in s:
        d[c] = d.get(c, 0) + 1

    l = list(d.items())
    l.sort(key = lambda x: (x[1], x[0].isupper(), -ord(x[0])))
    l = list(reversed(l))
    best = l[0][1]
    l = ''.join(list(map(lambda x: x[0], [x for x in l if x[1] == best])))
    print(l, best)
