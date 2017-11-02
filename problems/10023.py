t = int(input())
for x in range(t):
    if x:
        print()
    input()
    n = int(input())
    temp = n >> ((len(bin(n)) - 2) >> 1)
    while True:
        result = (temp + (n // temp)) >> 1
        if temp != result:
            temp = result
        else:
            break
        
    print(result)
