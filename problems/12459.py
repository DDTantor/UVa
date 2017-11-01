from sys import stdin

fib = [0] * 81
fib[0] = 1
fib[1] = 1
for i in range(2, 81):
    fib[i] = fib[i - 1] + fib[i - 2]

for n in (n for n in list(map(int, stdin)) if n != 0):
    print(fib[n])
