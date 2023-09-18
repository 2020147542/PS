t = int(input())

for _ in range(t):
    line = input().split()
    stack = []

    for i in range(len(line)):
        for j in line[i]:
            stack.append(j)

        for k in range(len(stack)):
            print(stack.pop(), end="")

        print(end=" ")

    print()
