from sys import stdin

a = []
for s in stdin:
    a += list(map(int, s.split()))

print(a)
d = {}
for x in a:
    d[x] = d.get(x, 0) + 1
    
for n in list(d.items()):
    print(n[0], n[1])
