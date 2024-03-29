#include <stdio.h>

typedef long long ll;
int main() {
    ll N, M;
    scanf("%lld %lld", &N, &M);
    ll r = N - M;
    if (r > 0) {
        printf("%lld\n", r);
    } else {
        printf("%lld\n", r * (-1));
    }

    return 0;
}


/*
사파리월드 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	14538	5818	4995	40.328%
문제
사파리월드는 인터넷으로만 존재하는 미스테리한 나라이다. 사파리월드에는 2개의 서브도메인이 seunghwan.royal.gov.sw와 kyuhyun.royal.gov.sw 이 있는데, 이것이 couple.royal.gov.sw으로 합쳐질 것이다. 그러나 도메인 관리 센터 SWNIC(센터장: 김동규)에는 엄격한 룰이 있다. 두 서브도메인을 합칠 때, 유명도의 차이가 너무 차이나지 않을 경우에만 두 서브도메인을 결혼시키는 것이다. 서브도메인의 유명도는 정수이다. 두 서브도메인의 유명도가 주어졌을 때, 그 차이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 두 도메인의 유명도 N과 M이 주어진다. (-2,000,000,000 ≤ N, M ≤ 2,000,000,000)

출력
첫째 줄에 두 유명도의 차이 (|N-M|)을 출력한다.

예제 입력 1 
-2 5
예제 출력 1 
7
*/
