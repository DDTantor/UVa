from sys import stdin

D = "_abcdefghijklmnopqrstuvwxyz."

for s in (s for s in stdin if s != "0\n"):
    k, s = s.split()
    k = int(k)
    res = [0] * len(s)
    for i in range(len(s)):
        res[(k * i) % len(s)] = (D.index(s[i]) + i) % 28

    print(''.join(list(map(lambda x: D[x], res))))
        
