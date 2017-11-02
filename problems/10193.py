from fractions import gcd

t = int(input())
for i in range(1, t + 1):
    print("Pair #%d: " %i, end = "")
    s1, s2 = int(input(), 2), int(input(), 2)
    print("All you need is love!" if gcd(s1, s2) > 1 else "Love is not all you need!") 
