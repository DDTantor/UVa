from sys import stdin

D = [5, 7, 5]
R = "aeiouy"

for s in (s for s in stdin if s != "e/o/i\n"):
    res = "Y"
    s = s.split("/")
    for i in range(3):
        cnt = j = 0
        while j < len(s[i]):
            if s[i][j] in R:
                cnt += 1
                while j < len(s[i]) and s[i][j] in R:
                    j += 1

            j += 1

        if cnt != D[i]:
            res = i + 1
            break;

    print(res)
