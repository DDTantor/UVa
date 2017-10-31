from sys import stdin

dp = 1005 * [0]
dp[0] = 1
for i in range(1001):
    for j in range(4):
        dp[i + 1 + j % 3] += dp[i]
                
for n in map(int, stdin):
    print(dp[n])
