from sys import stdin

d = {}
S = "?!,.\n"
s = ""
for res in stdin:
    if res[0] != "#":
        if not res.isspace():
            s += res[:-1] if res[-2] == "-" else res
    else:
        s = s.replace("'", "")
        s = s.replace("-", "")
        for c in S:
            s = s.replace(c, " ")

        s = s.split()
        for i in s:
            d[len(i)] = d.get(len(i), 0) + 1

        l = list(d.items())
        l.sort()
        for i in l:
            print(i[0], i[1])
            
        d.clear()
        s = ""
        print()
    
