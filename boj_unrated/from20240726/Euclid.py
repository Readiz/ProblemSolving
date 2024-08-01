import random
from decimal import Decimal, getcontext
from math import dist

# 소수점 이하 자릿수를 설정합니다.
getcontext().prec = 30

def total_distance(x, y, z, points):
    return sum((Decimal(x - px)**2 + Decimal(y - py)**2 + Decimal(z - pz)**2).sqrt() for px, py, pz in points)

def gradient_descent(points, x, y, z, initial_learning_rate=Decimal('1000000000'), tolerance=Decimal('1e-5'), max_iterations=750):
    learning_rate = initial_learning_rate
    
    for iteration in range(max_iterations):
        distances = [(Decimal(x - px)**2 + Decimal(y - py)**2 + Decimal(z - pz)**2).sqrt() + Decimal('1e-6') for px, py, pz in points]

        grad_x = sum((Decimal(x) - Decimal(px)) / d for (px, py, pz), d in zip(points, distances))
        grad_y = sum((Decimal(y) - Decimal(py)) / d for (px, py, pz), d in zip(points, distances))
        grad_z = sum((Decimal(z) - Decimal(pz)) / d for (px, py, pz), d in zip(points, distances))

        new_x = x - learning_rate * grad_x
        new_y = y - learning_rate * grad_y
        new_z = z - learning_rate * grad_z

        if (Decimal(new_x - x)**2 + Decimal(new_y - y)**2 + Decimal(new_z - z)**2).sqrt() < tolerance:
            break

        x, y, z = new_x, new_y, new_z
        
        # 학습률 감소
        learning_rate *= Decimal('0.95')

    return x, y, z

ax,ay,az=map(int,input().split())
bx,by,bz=map(int,input().split())
cx,cy,cz=map(int,input().split())
points = [(Decimal(ax), Decimal(ay), Decimal(az)), (Decimal(bx), Decimal(by), Decimal(bz)), (Decimal(cx), Decimal(cy), Decimal(cz))]

candis = [((ax+bx+cx)/3,(ay+by+cy)/3,(az+bz+cz)/3), (ax,ay,az), (bx,by,bz), (cx,cy,cz)]
weights = [(2,1,1), (1,2,1), (1,1,2)]

for v in range(3,10):
    weights.append((v,1,1))
    weights.append((1,v,1))
    weights.append((1,1,v))

minx=min(ax,bx,cx)
maxx=max(ax,bx,cx)
miny=min(ay,by,cy)
maxy=max(ay,by,cy)
minz=min(az,bz,cz)
maxz=max(az,bz,cz)

# rnd
for _ in range(50):
    candis.append((random.uniform(minx,maxx),random.uniform(miny,maxy),random.uniform(minz,maxz)))


for w in weights:
    candis.append(((ax*w[0]+bx*w[1]+cx*w[2])/(w[0]+w[1]+w[2]),(ay*w[0]+by*w[1]+cy*w[2])/(w[0]+w[1]+w[2]),(az*w[0]+bz*w[1]+cz*w[2])/(w[0]+w[1]+w[2])))

min_total_distance = Decimal('Infinity')

for c in candis:
    # 최소 거리 위치 계산
    optimal_x, optimal_y, optimal_z = gradient_descent(points, Decimal(c[0]), Decimal(c[1]), Decimal(c[2]))
    # 최소 총 거리 계산
    cur_total_distance = total_distance(optimal_x, optimal_y, optimal_z, points)
    if cur_total_distance < min_total_distance:
        min_total_distance = cur_total_distance

#print(min_total_distance)

print(min([dist(points[0], points[1])+dist(points[1], points[2]), dist(points[1], points[2])+dist(points[0], points[2]), dist(points[0], points[1])+dist(points[0], points[2]), min_total_distance]))