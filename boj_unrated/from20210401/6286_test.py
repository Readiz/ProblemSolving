def fibby1():
    a, b = 1, 1
    while True:
        yield str(b)[:9]
        a, b = b, a+b

def fibby2():
    a, b = 1, 1
    div = 1
    while True:
        while True:
            front = b // div
            if front < 10**9:
                break
            div *= 10
        yield str(front)
        a, b = b, a+b

def fibby3():
    a,b = 1,1
    A,B,C = 0,0,1
    while True:
        yield str(b)
        a, b = b, a+b
        A, B = B, A+B
        if B >= C:
            B -= C
            b += 1
        if b >= 10**9:
            A += a%10 * C
            B += b%10 * C
            a //= 10
            b //= 10
            C *= 10

def fibby4():
    from math import log10
    a, b = 1, 1
    while True:
        yield str(b // 10**max(0, int(log10(b) - 8)))
        a, b = b, a+b

def fibby5():
    from decimal import Decimal, getcontext
    getcontext().prec = 7000 # enough for n = 30000
    a, b = Decimal(1), Decimal(1)
    while True:
        yield str(b)[:9]
        a, b = b, a+b

from timeit import timeit
from itertools import islice
from time import time

n = 30000
t0 = time()
list1 = list(islice(fibby1(), n))
t1 = time()
list2 = list(islice(fibby2(), n))
t2 = time()
list3 = list(islice(fibby3(), n))
t3 = time()
list4 = list(islice(fibby4(), n))
t4 = time()
list5 = list(islice(fibby5(), n))
t5 = time()
print('All agree?', list1 == list2 == list3 == list4 == list5)
print('fibby1: %6.3f seconds' % (t1 - t0))
print('fibby2: %6.3f seconds' % (t2 - t1))
print('fibby3: %6.3f seconds' % (t3 - t2))
print('fibby4: %6.3f seconds' % (t4 - t3))
print('fibby5: %6.3f seconds' % (t5 - t4))

print(fibby3())