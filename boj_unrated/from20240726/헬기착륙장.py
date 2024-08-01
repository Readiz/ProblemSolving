# 휴리스틱 연습 + 최소외접원
from math import sqrt

N = int(input())
points = []
center_x, center_y = 0, 0
for _ in range(N):
    x, y = map(int, input().split())
    points.append((x,y))
    center_x += x
    center_y += y

center_x /= N
center_y /= N

def getDist(p1, p2):
    return (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2

def findFar(o):
    maxdist = 0
    maxp = (0,0)
    for p in points:
        cdist = getDist(o, p)
        if cdist > maxdist:
            maxdist = cdist
            maxp = p
    return maxp

alpha = 0.999

for _ in range(5000):
    cp = (center_x, center_y)
    farp = findFar(cp)
    mv = ((farp[0] - cp[0]) * alpha, (farp[1] - cp[1]) * alpha) # 이동거리
    center_x += mv[0]
    center_y += mv[1]
    alpha *= 0.99
    # print(center_x, center_y)
#print(alpha)
cp = (center_x, center_y)
farp = findFar(cp)
dist = getDist(cp, farp)

print(f'{center_x+0.0:.3f}' + ' ' + f'{center_y+0.0:.3f}')
print(f'{sqrt(dist)+0.0:.3f}')
