from sys import stdin

for t, s in enumerate(stdin):
    d = {}
    if t:
        print()
    for c in s[:-1]:
        d[ord(c)] = d.get(ord(c), 0) + 1

    l = list(d.items())
    l.sort(key = lambda x: (x[1], -x[0]))
    for p in l:
        print(p[0], p[1])


    
