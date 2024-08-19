n=int(input())
a=list(map(int,input().split()))

ptr=0
ans=1
cur=1
for i in range(1,n):
    if a[i] > a[i-1]:
        cur+=1
    else:
        cur=1
    ans+=cur

print(ans)