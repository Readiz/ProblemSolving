a = 0
b = 0
for i in range(1, 101):
    a += i
    b += i * i

a = a * a

print(a - b)