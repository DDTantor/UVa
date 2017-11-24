from sys import stdin

for x in list(map(int, [x for x in stdin if x != "0\n"])):
    lo, hi = 0, x
    while lo <= hi:
        mid = (lo + hi) // 2
        if mid ** 2 <= x:
            res = mid ** 2
            lo = mid + 1
        else:
            hi = mid - 1

    print(res)
