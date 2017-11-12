from sys import stdin

for s in stdin:
    for i in range(len(s)):
        if not s[i].isalpha():
            s = s.replace(s[i], " ")

    print(len(s.split()))
