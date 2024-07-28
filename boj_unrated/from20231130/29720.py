n,m,k=map(int,input().split(' '))
a=n-(m*k)
b=n-(m*(k-1))-1
if a<0:
    a=0
if b<0:
    b=0
print(str(a) + ' ' + str(b))