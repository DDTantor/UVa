from sys import stdin

for x in list(map(int, (s for s in stdin))):
    print(((x * (x + 1)) // 2) ** 2)
