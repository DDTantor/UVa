from sys import stdin

for n in list(map(int, stdin)):
    print(1 if n == 0 else n * n - n + 2)
