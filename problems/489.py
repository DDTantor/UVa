from sys import stdin
from collections import OrderedDict

for s in (s for s in stdin if s != "-1\n"):
    print("Round %s" %s, end = "")
    s = input()
    a = input()
    a = "".join(OrderedDict.fromkeys(a))
    cnt = 7
    for c in a:
        if not len(s) or not cnt:
            break
        
        if c in s:
            s = s.replace(c, '')
        else:
            cnt -= 1

    if len(s) == 0:
        print("You win.")
    elif cnt == 0:
        print("You lose.")
    else:
        print("You chickened out.")
