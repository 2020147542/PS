m = int(input())
grid = list()
result = [0]*3  # -1, 0, 1 저장

for _ in range(m):
    x = input().split()
    grid.append(x)


def onePiece(list):
    temp = list[0]
    for i in range(1, 9):
        if temp != list[i]:
            return False
    return True


def divideAndConquer(row, col, n):
    element = [-5]*9

    if n == 1:
        return int(grid[row][col])

    element[0] = divideAndConquer(row, col, n//3)
    element[1] = divideAndConquer(row, col+n//3, n//3)
    element[2] = divideAndConquer(row, col+2*(n//3), n//3)
    element[3] = divideAndConquer(row+n//3, col, n//3)
    element[4] = divideAndConquer(row+n//3, col+n//3, n//3)
    element[5] = divideAndConquer(row+n//3, col+2*(n//3), n//3)
    element[6] = divideAndConquer(row+2*(n//3), col, n//3)
    element[7] = divideAndConquer(row+2*(n//3), col+n//3, n//3)
    element[8] = divideAndConquer(row+2*(n//3), col+2*(n//3), n//3)

    if not onePiece(element):
        for i in range(9):
            if element[i] != -5:
                result[element[i]+1] += 1
        return -5
    elif onePiece(element) and element[0] == -5:
        return -5
    else:
        if n == m:
            result[element[0]+1] += 1
        return element[0]


divideAndConquer(0, 0, m)
for i in range(3):
    print(result[i])
