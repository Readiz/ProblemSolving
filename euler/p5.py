
i = 2520
while True:
    print(i)
    k = i
    flag = True
    for p in range(1, 21):
        if k % p != 0:
            flag = False
            break
    if flag == True:
        print(i)
        break
    i += 1


# 2     2
# 3     3
# 4     2 2
# 5     5
# 6     2 3
# 7     7
# 8     2 2 2
# 9     3 3
# 10    2 5
# 11    11
# 12    2 2 3
# 13    13
# 14    2 7
# 15    3 5
# 16    2 2 2 2
# 17    17
# 18    2 9
# 19    19
# 20    2 2 5 

# 2^4
# 3^2
# 5
# 7
# 11
# 13
# 17
# 19