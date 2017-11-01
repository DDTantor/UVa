from sys import stdin

sol = [1652, -3927, 5995, -781, 7068]
for n in (n for n in list(map(int, stdin)) if n != 0):
    sum = 0
    n = (n * n) % 10007
    b = n
    for i in range(5):
        sum = ( sol[i] * b + sum) % 10007
        b = (b * n) % 10007

    print(sum)
