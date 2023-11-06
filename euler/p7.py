def isPrime(v):
    i = 2
    while True:
        if i * i <= v:
            if v % i == 0:
                return False
        else:
            break
        i += 1
    return True

v = 2
k = 0

while True:
    if isPrime(v):
        k += 1
    if k == 10001:
        break
    v += 1
print(v)

