# 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수

n = int(input())
m = [0 for _ in range(n+1)]

m[0] = 1
m[1] = 1

for i in range(2, n+1):
    m[i] = (m[i-1] + m[i-2]) % 10007

print(m[n])
