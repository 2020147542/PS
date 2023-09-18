n = int(input())
stack = list()
lines = list()

for _ in range(n):
    line = input()
    lines.append(line)


for i in range(n):
    line = lines[i].split()
    commend = line[0]

    if commend == 'push':
        stack.append(line[1])
    elif commend == 'pop':
        if len(stack):
            print(stack.pop())
        else:
            print(-1)
    elif commend == 'size':
        print(len(stack))
    elif commend == 'empty':
        if len(stack):
            print(0)
        else:
            print(1)
    else:
        if len(stack):
            print(stack[len(stack) - 1])
        else:
            print(-1)