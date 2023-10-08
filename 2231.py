n = int(input())
found = False

for num in range(1, n):
    total = num
    for c in str(num):
        total += int(c)

    if total == n:
        print(num)
        found = True
        break

if not found:
    print(0)
