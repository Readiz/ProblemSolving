A,B,C=map(int,input().split(' '))
x1,x2,y1,y2=map(int,input().split(' '))

def assign(x, y):
    return A*x+B*y+C

p1=assign(x1,y1)
p2=assign(x1,y2)
p3=assign(x2,y2)
p4=assign(x2,y1)

if p1 >= 0 and p2 >= 0 and p3 >= 0 and p4 >= 0:
    print("Lucky")
elif p1 <= 0 and p2 <= 0 and p3 <= 0 and p4 <= 0:
    print("Lucky")
else:
    print("Poor")
