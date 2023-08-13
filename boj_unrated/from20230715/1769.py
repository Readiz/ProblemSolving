x = int(input())
cnt = 0
while x >= 10 :
    nextx = 0
    while x > 0 :
        nextx = nextx + (x % 10)
        x = x // 10
    x = nextx
    cnt += 1

print(cnt)
if (x % 3 == 0):
    print("YES")
else:
    print("NO")
