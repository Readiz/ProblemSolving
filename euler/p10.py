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

ans = 0

for v in range(2, 2000000):
    if isPrime(v):
        ans += v
print(ans)

