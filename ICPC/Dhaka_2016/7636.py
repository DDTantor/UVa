from sys import stdin

while True:
    s = input()
    n, t = s.split()
    if n == "0" and t == "0":
        break
    
    base = (16 if s[0:2] == "0x" else (8 if s[0] == "0" else 10)) 
    t, n = int(t), int(n, base)
    res = 0
    for i in range(t):
        s = input()
        com, a = s.split()
        if com == "++i":
            n += 1
        elif com == "--i":
            n -= 1

            
        res += (n == int(a))
        n = int(a);
        if com == "i++":
            n += 1
        elif com == "i--":
            n -= 1

    print(res)
