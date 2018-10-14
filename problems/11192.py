inp = input()

while inp != "0":
    n, s = inp.split(' ')
    n = int(len(s) / int(n))
    l = [s[i : i + n] for i in range(0, len(s), n)]
    for i in l:
        print(i[::-1], end = '')

    print()
    inp = input()
