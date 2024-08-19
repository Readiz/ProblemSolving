a,b,c,d,n=map(int,input().split())
x=0
while True:
    m=(a+b+c+d+x)/4
    if m>=n:
        break
    x+=1
print(x)