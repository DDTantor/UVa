from sys import stdin

for s in (s for s in stdin if s != "0 0\n"):
    d, n = s.split()
    n = n.replace(d, "")
    print(0 if n == "" else int(n))
