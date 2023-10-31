n = int(input())
m = [[0 for _ in range(2)] for _ in range(n+1)]

m[1][1] = 1

for i in range(2, n+1):

    m[i][0] = m[i-1][0] + m[i-1][1]
    m[i][1] = m[i-1][0]

print(m[n][0]+m[n][1])
