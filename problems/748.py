from sys import stdin
for s in stdin:
    s = s.split()
    s[0] = s[0].strip("0")
    d = len(s[0].split('.')[1])
    n = int(s[1])
    s = str(int(s[0].replace(".", "")) ** n)
    if len(s) < n * d:
        s = "." + ("0" * (n * d - len(s))) + s
    else:
        s = s[:len(s) - n * d] + "." + s[len(s) - n * d:]

    print(s)
