from sys import stdin

def IsPrime(p):
    if p == 1:
        return False
    
    for i in range(2, int(p ** 0.5) + 1):
        if not p % i:
            return False

    return True

for s in (s for s in stdin if s != "0\n"):
    s = s[:-1]
    best = "0"
    for i in range(len(s)):
        for j in range(i + 1, i + 6):
            #print(best)
            if IsPrime(int(s[i:j])):
                best = s[i:j] if int(best) < int(s[i:j]) else best

    print(best.lstrip('0'))
                            
