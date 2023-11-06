def isP(num):
    cpy = num
    tmp = 0
    while cpy > 0:
        tmp *= 10
        tmp += cpy % 10
        cpy //= 10
    if tmp == num:
        return True
    return False


ans = 0
i = 999
while i >= 100:
    j = 999
    while j >= 100:
        if isP(i*j):
            tmp = i*j
            if tmp > ans:
                ans = tmp
        j -= 1
    i -= 1
print(ans)