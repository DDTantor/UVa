from sys import stdin

for s in stdin:
    s = s[:-1]
    l = len(s)
    p = str(int(s) * int(s))
    if p.endswith(s) and int(s) != 0:
        print("Automorphic number of %d-digit." %l)
    else:
        print("Not an Automorphic number.")
