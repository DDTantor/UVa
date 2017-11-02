from sys import stdin

def IsPrime(x):
    for i in range(2, int(x ** 0.5) + 1):
        if not x % i:
            return False
        
    return True

for s in stdin:
    s = " " if IsPrime(sum(list(map(lambda x: ord(x) + 1 - (ord('A') - 26 if x.isupper() else ord('a')), s[:-1])))) else " not "
    print("It is%sa prime word." %s)
