from sys import stdin
from sys import stdout
from math import log2

for x in (s for s in list(map(int, stdin)) if s != 0):
    x -= 1
    stdout.write("{ ")
    i = 0
    for i in range(x.bit_length()):
        if x & (1 << i):
            stdout.write("%d" %(3 ** i))
            if i != x.bit_length() - 1:
                stdout.write(", ")
            
    stdout.write(" }\n")
