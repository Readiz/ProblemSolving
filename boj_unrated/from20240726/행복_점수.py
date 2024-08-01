from decimal import Decimal, getcontext
import decimal

# 소수점 이하 자릿수를 설정합니다.
getcontext().prec = 10000
getcontext().rounding = decimal.ROUND_HALF_UP # 없으면 틀림!!!!!!!!!!!!

line=str(input())
h, g = 0, 0

for _ in line:
    if _ == 'A':
        h += 1
        g += 1
    elif _ == 'H':
        h += 1
    elif _ == 'P':
        h += 1
    elif _ == 'Y':
        h += 1
    elif _ == 'S':
        g += 1
    elif _ == 'D':
        g += 1

if h == 0 and g == 0:
    h, g = 1, 1

print(f"{Decimal((Decimal(h*100)/Decimal(h+g))):.2f}")

# a = h*10000 // (h + g)
# b = h*10000 % (h + g)
# half = (h + g) // 2
# even = (h + g) % 2

# if even == 0 and b >= half:
#     a += 1
# elif even == 1 and b > half:
#     a += 1

# print(f"{a//100}.{a%100:02}")
