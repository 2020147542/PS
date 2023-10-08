# 백설공주를 도와 일곱 난쟁이를 찾는 프로그램

# input = 아홉 난쟁이 키 - 아홉 난쟁이의 키는 모두 다름
heights = list()
sum = 0
for _ in range(9):
    h = int(input())
    heights.append(h)
    sum += h

# 일곱 난쟁이의 키의 합이 100
# 전체 키 합 - 100 = 9 난쟁이 중 2 난쟁이 키 합
gap = sum - 100
for i in range(9):
    r = gap - heights[i]
    if r != heights[i] and r in heights:
        heights.remove(r)
        heights.remove(heights[i])
        break

# 가능한 정답이 여러 가지인 경우에는 아무거나 출력
heights.sort()
for i in range(7):
    print(heights[i])
