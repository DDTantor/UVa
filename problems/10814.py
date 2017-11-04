from fractions import gcd

t = int(input())

for i in range(t):
    s = input()
    a, b = list(map(int, s.replace("/", "").split()))
    print("%d / %d" %(a // gcd(a, b), b // gcd(a, b)))
    
