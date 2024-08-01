import random

N = int(input())
dic = []
for _ in range(N):
    s = str(input())
    dic.append(s)

random.shuffle(dic)

ans = 1

while True:
    flag = True

    for i in range(N):
        down = ans
        match = False
        for up in range(0, 10 * ans + 1):
            cstr = f"{(up*1000//down/1000):.3f}"
            if cstr == dic[i]:
                match = True
                break

        if match == False:
            flag = False
            break


    if flag:
        print(ans)
        break
    ans += 1