import random
#from float import float, getcontext
from math import sqrt

# 소수점 이하 자릿수를 설정합니다.
#getcontext().prec = 10
acceptance_ratio = 0.5

def total_distance(x, y, z, points):
    return sum(sqrt((x - px)**2 + (y - py)**2 + (z - pz)**2) for px, py, pz in points)

def gradient_descent(points, x, y, z, learning_rate=5000000):
    grad_x, grad_y, grad_z = 0, 0, 0
    for _ in range(1000):
        for _ in range(100):
            distances = [sqrt(float(x - px)**2 + float(y - py)**2 + float(z - pz)**2) + float('1e-20') for px, py, pz in points]
            grad_x = sum((float(x) - float(px)) / d for (px, py, pz), d in zip(points, distances)) * (1 - acceptance_ratio) + grad_x * acceptance_ratio
            new_x = x - learning_rate * grad_x
            x = new_x
        for _ in range(100):
            distances = [sqrt(float(x - px)**2 + float(y - py)**2 + float(z - pz)**2) + float('1e-20') for px, py, pz in points]
            grad_y = sum((float(y) - float(py)) / d for (px, py, pz), d in zip(points, distances)) * (1 - acceptance_ratio) + grad_y * acceptance_ratio
            new_y = y - learning_rate * grad_y
            y = new_y
        for _ in range(100):
            distances = [sqrt(float(x - px)**2 + float(y - py)**2 + float(z - pz)**2) + float('1e-20') for px, py, pz in points]
            grad_z = sum((float(z) - float(pz)) / d for (px, py, pz), d in zip(points, distances)) * (1 - acceptance_ratio) + grad_z * acceptance_ratio
            new_z = z - learning_rate * grad_z
            z = new_z
        learning_rate *= float('0.975')
    #print(learning_rate)
    return x, y, z

ax,ay,az=map(int,input().split())
bx,by,bz=map(int,input().split())
cx,cy,cz=map(int,input().split())
points = [(float(ax), float(ay), float(az)), (float(bx), float(by), float(bz)), (float(cx), float(cy), float(cz))]

candis = [((ax+bx+cx)/3,(ay+by+cy)/3,(az+bz+cz)/3)] #, (ax,ay,az), (bx,by,bz), (cx,cy,cz)]
# weights = [(2,1,1), (1,2,1), (1,1,2)]
weights = []

# for v in range(3,10):
#     weights.append((v,1,1))
#     weights.append((1,v,1))
#     weights.append((1,1,v))

minx=min(ax,bx,cx)
maxx=max(ax,bx,cx)
miny=min(ay,by,cy)
maxy=max(ay,by,cy)
minz=min(az,bz,cz)
maxz=max(az,bz,cz)

# rnd
# for _ in range(10):
#     candis.append((random.uniform(minx,maxx),random.uniform(miny,maxy),random.uniform(minz,maxz)))


for w in weights:
    candis.append(((ax*w[0]+bx*w[1]+cx*w[2])/(w[0]+w[1]+w[2]),(ay*w[0]+by*w[1]+cy*w[2])/(w[0]+w[1]+w[2]),(az*w[0]+bz*w[1]+cz*w[2])/(w[0]+w[1]+w[2])))

min_total_distance = float('Infinity')

for c in candis:
    # 최소 거리 위치 계산
    optimal_x, optimal_y, optimal_z = gradient_descent(points, float(c[0]), float(c[1]), float(c[2]))
    # 최소 총 거리 계산
    cur_total_distance = total_distance(optimal_x, optimal_y, optimal_z, points)
    if cur_total_distance < min_total_distance:
        min_total_distance = cur_total_distance
        #print(optimal_x,optimal_y,optimal_z)

#print(min_total_distance)
print(f'{min_total_distance:.6f}')
