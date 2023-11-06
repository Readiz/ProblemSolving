for i in range(1, 1000):
    for j in range(1, 1000):
        k = 1000 - i - j
        if k < 0:
            continue
        if i * i + j * j == k * k:
            print(i*j*k)
            print(i)
            print(j)
            print(k)