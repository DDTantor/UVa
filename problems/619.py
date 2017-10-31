from sys import stdin

for s in (x for x in stdin if x != "*\n"):
    name = s
    val = s
    try:
        val = s = int(s)
        name = ""
        while s:
            name = chr(ord('a') + (s - 1) % 26) + name
            s = (s - 1) // 26
            
    except ValueError:
        name = s[0:len(s) - 1]
        val = 0
        for i, c in enumerate(name[::-1]):
            val += (26 ** i) * (ord(c) - ord('a') + 1)

    print(name.ljust(21), "{:,}".format(val))
