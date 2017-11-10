from sys import stdin

D = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
E = "SVYZ"

for s in stdin:
    for c in s[:-1]:
        if c.isalpha():
            i = D.index(c) // 3 + 2
            if c in E:
                i -= 1

            c = i

        print(c, end = "")

    print()
            
