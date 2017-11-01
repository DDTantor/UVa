from sys import stdin

def solve(a, b):
    for i in range(2, 37):
        if any(a >= i for a in list(map(lambda x: int(x, 36), list(a)))):
            continue
        
        for j in range(2, 37):
            if any(a >= j for a in list(map(lambda x: int(x, 36), list(b)))):
                continue

            if (int(a, i) == int(b, j)):
                return "%s (base %d) = %s (base %d)" %(a, i, b, j)

    return "%s is not equal to %s in any base 2..36" %(a, b)

for s in stdin:
    a, b = s.split()
    print(solve(a, b))
    
