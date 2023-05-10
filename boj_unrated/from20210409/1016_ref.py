from sys import stdin
input = stdin.readline
 
min, max = map(int, input().split())
isChecked = [False] * 1000001
isSquare = [False] * 1000001
 
ans = max - min + 1
for i in range(2, 1000001):
    if i ** 2 > max:
        break
    
    if isChecked[i]:
        continue
 
    for j in range(i, 1000001, i):
        if j ** 2 > max:
            break
        isChecked[j] = True
 
    square = i ** 2
    minimum = ((min - 1) // square + 1) * square
    for j in range(minimum, max + 1, square):
        if isSquare[j - min] == False:
            isSquare[j - min] = True
            ans -= 1
 
print(ans)

# 출처: https://haedallog.tistory.com/179 [SM's Development Log]