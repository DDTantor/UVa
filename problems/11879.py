from sys import stdin

for x in (x for x in list(map(int, stdin)) if x != 0):
    print(int(not(x % 17)))
