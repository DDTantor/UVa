from sys import stdin

for s in (s for s in stdin if s[0] != "-"):
    s = s.replace("\n", "")
    print(int(s, 16) if s[0] == "0" else "0x%X" %int(s))
