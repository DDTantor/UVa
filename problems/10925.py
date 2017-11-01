from sys import stdin

for c, s in enumerate((x for x in stdin if x != "0 0\n"), 1):
    n, f = int(s.split()[0]), int(s.split()[1])
    sum = 0
    for i in range(n):
        sum += int(input())

    print("Bill #%d costs %d: each friend should pay %d\n" %(c, sum, sum // f))
