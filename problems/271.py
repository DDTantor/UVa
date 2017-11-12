from sys import stdin

def solve(s):
    cnt = 0;
    for c in s[::-1]:
        if ord(c) in range(ord('p'), ord('z') + 1):
            cnt += 1
        elif c == 'N':
            if cnt == 0:
                return False
        elif c in "CDEI":
            if cnt < 2:
                return False

            cnt -= 1
        else:
            return False

    return cnt == 1


for s in stdin:
    print("YES" if solve(s[:-1]) else "NO")
