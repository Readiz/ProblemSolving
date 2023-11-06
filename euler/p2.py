cur = 1
prev = 1
ans = 0
while True:
    nval = cur + prev
    if nval > 4000000:
        break
    if nval % 2 == 0:
        ans += nval
    prev = cur
    cur = nval
print(ans)