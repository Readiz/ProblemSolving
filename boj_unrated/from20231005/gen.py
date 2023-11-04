import random
random.seed("Wormhole")
n = 50

def block1(i, m2, m3):
    print(4*i+1, 4*i+m2, 10)
    print(4*i+1, 4*i+m3, 20)

def block2(i, m2, m3):
    print(4*i+m3, 4*i+m2, 18 + (i == 0))
    print(4*i+m2, 4*i+4, 1)
    print(4*i+m3, 4*i+4, 1)
    print(4*i+4, 4*(i+1 if i!=n-1 else 0)+1, 1)    

print(5)
for TEST in range(5):
    print(4*n, 2*n, 4*n)
    for i in range(n):
        if random.random() < 0.5: block1(i, 3, 2)
        else: block1(i, 2, 3)
    for i in range(n):
        if random.random() < 0.5: block2(i, 3, 2)
        else: block2(i, 2, 3)