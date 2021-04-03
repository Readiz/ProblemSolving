fib = [0,1]
for i in range(2, 100001):
    fib.append(fib[-1]+fib[-2])
    
mp = {}
for i in range(1, 100001):
    mp[fib[i]] = i

T = int(input())
for _ in range(T):
    n = int(input())
    print(mp[n])