y, m, d = map(int,(input().split('-')))
delta = int(input())
d = d + delta
while d > 30:
    d -= 30
    m += 1
while m > 12:
    m -= 12
    y += 1
print("{:04d}".format(y) + "-{:02d}".format(m) + "-{:02d}".format(d))