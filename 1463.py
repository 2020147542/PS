n = int(input())
m = [0 for _ in range(n+1)]

for i in range(2, n+1):
    # OPT(i) = i까지 연산 사용하는 횟수 최솟값

    ans = m[i-1]

    if i % 3 == 0:
        # X가 3으로 나누어 떨어지면, 3으로 나눈다.
        ans = min(m[i//3], ans)

    if i % 2 == 0:
        # X가 2로 나누어 떨어지면, 2로 나눈다.
        ans = min(m[i//2], ans)

    m[i] = ans + 1


print(m[n])
