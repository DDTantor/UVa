def IsTheorem(s):
    if s.count("M") != 1 or s.count("E") != 1 or s.index("M") == 0 or s.index("E") == len(s) - 1:
        return "no-"

    x, y = s.split("M")
    y, z = y.split("E")
    if x != "?" * len(x) or y != "?" * len(y) or z != "?" * len(z) or not len(x) or not len(y) or not len(z) or len(x) + len(y) != len(z):
        return "no-"

    return ""

t = int(input())
for i in range(t):
    s = input()
    s = IsTheorem(s)
    print("%stheorem" %s)
