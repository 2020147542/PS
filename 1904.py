n = int(input())

m = [0 for _ in range(n+1)]
m[0] = 1
m[1] = 1

for i in range(2, n+1):
    m[i] = (m[i-2] + m[i-1]) % 15746

print(m[n])
