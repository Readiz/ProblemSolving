# 예제 데이터
x = []
y = []

N = int(input())
for _ in range(N):
    cx, cy = map(int, input().split())
    x.append(cx)
    y.append(cy)

# 평균 계산
def mean(values):
    return sum(values) / len(values)

x_mean = mean(x)
y_mean = mean(y)

# 기울기 m 계산
numerator = 0
denominator = 0
for i in range(len(x)):
    numerator += (x[i] - x_mean) * (y[i] - y_mean)
    denominator += (x[i] - x_mean) ** 2

m = numerator / denominator

# y-절편 b 계산
b = y_mean - m * x_mean

# 결과 출력
print(f"{m:.3f}")
print(f"{b:.3f}")

# 예측 값 계산 및 그래프 그리기 (matplotlib 사용)
# import matplotlib.pyplot as plt

# y_pred = [m * xi + b for xi in x]

# plt.scatter(x, y, color='blue', label='Data points')
# plt.plot(x, y_pred, color='red', label='Best fit line')
# plt.xlabel('x')
# plt.ylabel('y')
# plt.legend()
# plt.show()
