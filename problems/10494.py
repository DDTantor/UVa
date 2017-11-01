from sys import stdin

for s in stdin:
    s = s.split()
    x, c, y = int(s[0]), s[1], int(s[2])
    print(x // y if c == '/' else x % y)
