N,M=map(int,input().split(' '))
if M == 0:
    inc=[]
else:
    inc=[int(number) for number in input().split(' ')]
last=10**N

def checker(cur):
    cpy=set(inc)

    for l in range(N):
        c=cur%10
        if c in cpy:
            cpy.remove(c)
        cur//=10
    if len(cpy) == 0:
        return True
    return False

ans = 0
for cur in range(last):
    ret = checker(cur)
    if ret:
        ans += 1

print(ans)