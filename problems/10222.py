from sys import stdin

D = "qwertyuiop[]asdfghjkl;'zxcvbnm,."

for s in stdin:
    print(''.join(list(map(lambda x: ' ' if x == ' ' else D[D.index(x.lower()) - 2], s[:-1]))))
