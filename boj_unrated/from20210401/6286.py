import math
import sys
fib = [1,1]
fibStr = []
for i in range(0, 10000):
    fibStr.append([])
fibStr[1].append(['1', 0])
fibStr[1].append(['1', 1])

for i in range(2, 100000):
    n = fib[-1] + fib[-2]
    length = int(math.log10(n))
    if (length > 100):
        n = n // 10
        fib[-1] = fib[-1] // 10
    fib.append(n)
    strtrimmed = str(n)[:40]
    bucketIdx = int(strtrimmed[:4])
    fibStr[bucketIdx].append([strtrimmed, i])
    fibStr[bucketIdx // 10].append([strtrimmed, i])
    fibStr[bucketIdx // 100].append([strtrimmed, i])
    fibStr[bucketIdx // 1000].append([strtrimmed, i])
    fibStr[bucketIdx // 10000].append([strtrimmed, i])

# for i in range(0, 10000):
#     print(fibStr[i])

IO = sys.stdin.read().split('\n')
T = int(IO[0])
del IO[0]
for tc in range(T):
    compare = IO[tc]
    length = len(compare)
    bucketIdx = int(compare[:4])
    found = False
    for item in fibStr[bucketIdx]:
        if (compare == str(item[0])[:length]):
            IO[tc] = ('Case #' + str(tc + 1) + ': ' + str(item[1]) + '\n')
            found = True
            break
    if (found == False):
        IO[tc] = ('Case #' + str(tc + 1) + ': -1\n')
sys.stdout.write(''.join(IO))


# 리벤지 오브 피보나치 출처다국어분류
# 시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
# 5 초	128 MB	49	9	8	32.000%
# 문제
# 피보나치 수열의 정의는 다음과 같다.

# F(0) = F(1) = 1
# F(n) = F(n-1) + F(n-2) (n ≥ 2)

# n은 피보나치 숫자 F(n)의 인덱스라고 한다.

# 피보나치의 책 Liber Abaci가 출판된 이후에 많은 사람들은 피보나치 수열에 대해서 많은 연구를 했다. 현재, 많은 성질들이 알려져 있다.

# 선영이가 코딩보다 좋아하는 것이 바로 피보나치 수를 연구하는 것이다. 피보나치 수에 대한 많은 논문을 읽은 결과 이제 더 이상 밝혀지지 않은 성질은 없다고 생각했다.

# 그날 밤 이었다. 피보나치가 선영이의 꿈에 나타났다. "멍청하군... 아직 피보나치 수에 대해 중요한 성질이 밝혀지지 않았다고. 예를 들면, 피보나치 숫자 347746739..."

# 선영이는 잠에서 깨어나 나머지 숫자를 기억하려고 했지만, 기억하지 못했다. 선영이는 피보나치 수에 대한 연구를 계속 하기 위해서 이 숫자를 알아내는 프로그램을 작성하려고 한다.

# 한 피보나치 숫자의 앞 부분 일부가 주어졌을 때, 이 숫자로 시작하는 피보나치 숫자의 가장 작은 인덱스를 찾는 프로그램을 작성하시오.

# 입력
# 첫째 줄에 테스트 케이스의 개수 T가 주어진다. (T ≤ 50,000)

# 각 테스트 케이스는 한 줄로 이루어져 있고, 피보나치 수의 앞 부분 일부가 주어진다. 이 수는 40자리는 넘지 않으며, 불필요한 0이 숫자의 앞에 없다.

# 출력
# 각 테스트 케이스에 대해서, 입력으로 주어진 숫자로 시작하는 피보나치 수의 가장 작은 인덱스를 출력한다. 만약, 인덱스가 100,000보다 작은 피보나치 숫자 중 그러한 숫자로 시작하는 피보나치 숫자가 없는 경우에는 -1을 출력한다.

# 예제 입력 1 
# 15
# 1
# 12
# 123
# 1234
# 12345
# 9
# 98
# 987
# 9876
# 98765
# 89
# 32
# 51075176167176176176
# 347746739
# 5610
# 예제 출력 1 
# Case #1: 0
# Case #2: 25
# Case #3: 226
# Case #4: 1628
# Case #5: 49516
# Case #6: 15
# Case #7: 15
# Case #8: 15
# Case #9: 43764
# Case #10: 49750
# Case #11: 10
# Case #12: 51
# Case #13: -1
# Case #14: 1233
# Case #15: 22374