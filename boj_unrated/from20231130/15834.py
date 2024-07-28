# Python Gosu project
db = [0] * 77
db[3] = 1
db[4] = 2
db[5] = 2

for i in range(6, 77):
    db[i] = db[i - 2] + db[i - 3]

id = 1
while True:
    N = int(input())
    if N == 0:
        break
    print("Case #" + str(id) + ": " + str(db[N] + db[N - 1]))
    id += 1
