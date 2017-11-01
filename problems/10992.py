from sys import stdin
from calendar import isleap

D = {2 : "Ghost of Tanveer Ahsan!!!",
     5 : "Ghost of Shahriar Manzoor!!!",
     7 : "Ghost of Adrian Kugel!!!",
     11 : "Ghost of Anton Maydell!!!",
     15 : "Ghost of Derek Kisman!!!",
     20 : "Ghost of Rezaul Alam Chowdhury!!!",
     28 : "Ghost of Jimmy Mardell!!!",
     36 : "Ghost of Monirul Hasan!!!"
}

for c, x in enumerate(x for x in list(map(int, stdin)) if x != 0):
    print() if c else None
    print(x)
    G = []
    for k, v in D.items():
        if x % k == 2148 % k:
            G.append(v)

    if isleap(x):
        G.append("Ghost of K. M. Iftekhar!!!")

    if not(len(G)) or x < 2148:
        print("No ghost will come in this year")
    else:
        for s in G:
            print(s)
