t = int(input())

def isPrime(a):
    for i in range(2, int(a ** 0.5) + 1):
        if not(a % i):
            return False

    return True;
        
for k in range(t):
    s = input()
    a, b = list(map(int, s.split()))
    if a != 0 and b != 0:
        print("P" if isPrime(a * a + b * b) else "C")
    elif a != 0:
        print("P" if isPrime(abs(a)) and abs(a) % 4 == 3 else "C")
    else:
        print("P" if isPrime(abs(b)) and abs(b) % 4 == 3 else "C")
