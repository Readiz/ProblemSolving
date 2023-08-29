N=int(input())
minX=999999999999999999999999
maxX=-999999999999999999999999
minY=999999999999999999999999
maxY=-999999999999999999999999
for _ in range(N):
    x,y,d=input().split()
    x=int(x)
    y=int(y)
    if d == 'L':
        maxX = max(maxX,x-1)
    elif d == 'D':
        maxY = max(maxY,y-1)
    elif d == 'U':
        minY = min(minY,y+1)
    elif d == 'R':
        minX = min(minX,x+1)
if minX == 999999999999999999999999 or minY == 999999999999999999999999 or maxX == -999999999999999999999999 or maxY == -999999999999999999999999:
    print('Infinity')
else:
    if ((maxX - minX + 1) * (maxY - minY + 1)) > 0:
        print((maxX - minX + 1) * (maxY - minY + 1))
    else:
        print('Infinity')