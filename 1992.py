m = int(input())
grid = list()

for _ in range(m):
    x = input()
    get = list()
    for i in x:
        get.append(i)

    grid.append(get)


def onePiece(element):
    if '(' in element[0]:
        return False

    for i in range(1, 4):
        if element[0] != element[i]:
            return False
    return True


def divide_and_conquer(row, col, n):

    if n == 1:
        return grid[row][col]

    element = ['-1'] * 4
    element[0] = divide_and_conquer(row, col, n//2)
    element[1] = divide_and_conquer(row, col + n//2, n//2)
    element[2] = divide_and_conquer(row + n//2, col, n//2)
    element[3] = divide_and_conquer(row + n//2, col + n//2, n//2)

    if not onePiece(element):
        result = ''
        for i in range(4):
            result += f'{element[i]}'

        result = '(' + result + ')'
        return result
    else:
        return element[0]


print(divide_and_conquer(0, 0, m))
