from sys import stdin

for s in stdin:
    s = s[:-1]
    if s.isdigit():
        s = s[::-1]
        i = 0
        while i < len(s[::-1]):
            if s[i] == '1':
                w = s[i:i + 3]
                i += 3
            else:
                w = s[i:i + 2]
                i += 2

            print(str(chr(int(w))), end = "")
    else:
        res = ""
        for c in s:
            res += str(ord(c))

        print(res[::-1], end = "")

    print()

