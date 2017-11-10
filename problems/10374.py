t = int(input())
for i in range(t):
    if i:
        print()
    n = input()
    n = int(input())
    V, D = {}, {}
    for j in range(n):
        s1 = input()
        s2 = input()
        V[s1] = s2

    n = int(input())
    for j in range(n):
        s1 = input()
        D[s1] = D.get(s1, 0) + 1

    l = list(D.items())
    l.sort(key = lambda x: -x[1])
    print("tie" if len(l) != 1 and l[0][1] == l[1][1] else V[l[0][0]])
