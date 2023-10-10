n, r, c = map(int, input().split())
m = 2**n
count = -1


def divide_and_conquer(row, col, n):

    global count

    if n == 1:
        count += 1
        if row == r and col == c:
            print(count)
        return

    if row <= r and r < row + n//2:
        if col <= c and c < col + n//2:
            # 1번
            divide_and_conquer(row, col, n//2)
        else:
            # 2번
            count += (n//2)*(n//2)
            divide_and_conquer(row, col + n//2, n//2)

    else:
        if col <= c and c < col + n//2:
            # 3번
            count += 2*(n//2)*(n//2)
            divide_and_conquer(row + n//2, col, n//2)
        else:
            # 4번
            count += 3*(n//2)*(n//2)
            divide_and_conquer(row+n//2, col + n//2, n//2)

    return


divide_and_conquer(0, 0, m)
