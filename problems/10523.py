from sys import stdin

for s in stdin:
    sum = 0
    n, a = int(s.split()[0]), int(s.split()[1])
    for i in range(1, n + 1):
        sum += i * a ** i

    print(sum)
