import decimal
from sys import stdin

decimal.getcontext().prec = 31

t = int(input())

for i in range(t):
    sum = 0
    x = input()
    while x != "0":
        sum += decimal.Decimal(x)
        x = input()

    print(str("{:.25f}".format(sum)).rstrip("0").rstrip("."))
