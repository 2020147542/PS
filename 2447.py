n = int(input())
result = [[' ' for j in range(n)] for i in range(n)]


def star(row, col):

    for i in range(3):
        for j in range(3):
            if i == 1 and j == 1:
                continue
            result[row+i][col+j] = '*'

    return result


def divideAndConquer(row, col, n):

    if n == 3:
        return star(row, col)

    divideAndConquer(row, col, n//3)
    divideAndConquer(row + n//3, col, n//3)
    divideAndConquer(row + (n//3)*2, col, n//3)

    divideAndConquer(row, col + n//3, n//3)
    divideAndConquer(row + (n//3)*2, col + n//3, n//3)

    divideAndConquer(row, col + (n//3)*2, n//3)
    divideAndConquer(row + n//3, col + (n//3)*2, n//3)
    divideAndConquer(row + (n//3)*2, col + (n//3)*2, n//3)


divideAndConquer(0, 0, n)

for i in range(n):
    for j in range(n):
        print(result[i][j], end="")
    print()
