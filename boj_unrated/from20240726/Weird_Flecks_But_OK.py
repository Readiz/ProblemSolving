# 휴리스틱 연습 + 최소외접원
from math import sqrt

N = int(input())
cache = []
for _ in range(N):
    x, y, z = map(float, input().split())
    cache.append((x,y,z))

ans = float('Infinity')

def sol(v1, v2):
    points = []
    center_x, center_y = 0, 0
    for p in cache:
        points.append((p[v1],p[v2]))
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

    for _ in range(2500):
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

    #print(f'{center_x+0.0:.3f}' + ' ' + f'{center_y+0.0:.3f}')
    return dist

ans = min(ans, sol(0,1))
ans = min(ans, sol(0,2))
ans = min(ans, sol(1,2))
print(f'{sqrt(ans)*2+0.0:.10f}')
