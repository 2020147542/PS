t = int(input())
stack = list()

for _ in range(t):
    cmd = input()
    vps = True
    stack = list()

    for j in cmd:
        if j == '(':
            stack.append(j)

        else:
            if len(stack):
                stack.pop()
            else:
                vps = False
                break

    if len(stack):
        vps = False

    if vps:
        print('YES')
    else:
        print('NO')
