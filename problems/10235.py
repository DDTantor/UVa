from sys import stdin

def IsPrime(x):
    for i in range(2, int(x ** 0.5) + 1):
        if not x % i:
            return False
        
    return True

for x in stdin:
    x = x[:-1]
    y = x[::-1]
    a = IsPrime(int(x))
    b = IsPrime(int(y))
    if not a:
        print("%s is not prime." %x)
    elif (a and not b) or (a and x == y):
        print("%s is prime." %x)
    else:
        print("%s is emirp." %x)
