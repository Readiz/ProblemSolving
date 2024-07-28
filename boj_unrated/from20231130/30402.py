
def solve():
    for _ in range(15):
        l = map(str,input().split(' '))
        for c in l:
            if c == 'w':
                print('chunbae')
                return
            if c == 'b':
                print('nabi')
                return
            if c == 'g':
                print('yeongcheol')
                return

solve()