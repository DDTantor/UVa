from sys import stdin

mod = 131071

v = 0
for s in stdin:
    for c in s:
        if c == "#":
            print("YES" if not v else "NO")
            v = 0
        elif c.isdigit():
            v = (ord(c) - ord("0") + (v << 1)) % mod
        
            
