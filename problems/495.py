from sys import stdin

F = [0] * 5001
F[0], F[1] = 0, 1
for i in range(2, 5001):
    F[i] = F[i - 1] + F[i - 2]

for x in list(map(int, stdin)):
    print("The Fibonacci number for %d is %d" %(x, F[x]))
