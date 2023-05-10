#include "main.cpp"

// 파티셔닝 풀이
// 천만번 연산 = 0.1초 (1억: 1초)  (천만번 이유: 100 * 10만개 / 100은 로그써서 나온거)
// 473055는 size {22000, 22000, 22000, 22000, 12000} 으로도 나오는 점수.
// 100개 기준 44643313 점 나오게 됨. (돌머갓 풀이 최대치)

// 아래 조건 하에서 가능한 풀이임에 유의.
// 1. user 영역에서 점수를 구할 수 있어야 한다. (점수 구하는 데에 시간이 적게 걸림)
// 2. 시간이 중요한 요소가 아니다.


#define printd(...)     printf(__VA_ARGS__)
#define CNTHOUSE        100000
#define R               register

void test(double const house[], double station[], unsigned int alloc[]) {

    for (R int i = 0; i < 100; i++)
        printd("%lf\n", house[i]);
}

