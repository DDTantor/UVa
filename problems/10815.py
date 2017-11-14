from sys import stdin

rj = {}
for s in (s for s in stdin if s != "\n"):
    s = s.lower()
    for c in s:
        if not c.isalpha():
            s = s.replace(c, ' ');

    for a in s.split():
        rj[a] = rj.get(a, 0)

l = list(rj.items())
l.sort();
for a in l:
    print(a[0])
