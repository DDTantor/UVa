from sys import stdin
from sys import stdout


dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

def solve(x, y):
    global n
    global c
    t = p = 0
    while t < 1000:
        if x < 0 or y < 0 or x >= n or y >= n:
            break
        
        t += 1
        if x == n - 1 and y == 0:
            return "Yes"

        bit = (1 << (y * n + (n - x - 1)))
        if c & bit:
            p = (p + 1) % 4
        else:
            p = (p - 1) % 4
            
        x = x + dx[p]
        y = y + dy[p]
        c ^= bit
    
    return "Kaputt!"


for s in (s for s in stdin if s != "0 0 0 0\n"):
    n, c, x, y = list(map(int, s.split()))
    y = n - y;
    x = x - 1
    print(solve(x, y))
