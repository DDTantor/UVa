n = int(input())
d = {}
for i in range(n):
    s = input()
    s = s.split()
    d[s[0]] = d.get(s[0], 0) + 1

l = list(d.items())
l.sort()
for i in l:
    print(i[0], i[1])
