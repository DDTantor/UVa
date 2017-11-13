from sys import stdin

def conv(s, b):
    res = 0;
    for c in s:
        res *= b;
        res += int(c)

    return res;

for s in (s for s in stdin if s != "0\n"):
    m = max(list(map(int, s[:-1])))
    for b in range(m + 1, 100):
        n = conv(s[:-1], b)
        a = int(n ** 0.5)
        if (a ** 2 == n):
            print(b)
            break;
        
