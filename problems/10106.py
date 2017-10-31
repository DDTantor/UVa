from sys import stdin

s = list(map(int, stdin));
for x, y in zip(s[0::2], s[1::2]):
    print(x * y)
