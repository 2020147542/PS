integers = input().split()
a = int(integers[0])
b = int(integers[1])
c = int(integers[2])


def square(x, y):

    # base case
    if y == 0:
        return 1

    # 쪼개기
    result = square(x, y//2)
    ans = (result * result) % c

    if y % 2:
        return (ans * x) % c


ans = square(a, b)
print(ans)
