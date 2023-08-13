tc=int(input())
for i in range(tc):
    a,b,c=map(float,input().split())
    print("${:.2f}".format(a*b*c))