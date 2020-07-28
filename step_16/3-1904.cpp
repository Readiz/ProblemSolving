#include <stdio.h>

int N;
int result = 0;

void solve(int pos) {
    if (pos == N) { 
        result ++;
        return;
    }
    else if (pos == N + 1)
        return;
    
    // 1을 붙이는 case
    solve(pos + 1);
    // 0를 붙이는 case
    solve(pos + 2);

    return;
}

int main() {
    scanf("%d", &N);
    // solve(0);
    // printf("%d\n", result % 15746);
    // 결국 구하면 피보나치이므로 아래처럼 구한다.
    int pprev = 0, prev = 1;
    int cur = 2;
    int pos = 2;
    if (N == 0) printf("0\n");
    else if (N == 1) printf("1\n");
    else if (N == 2) printf("2\n");
    else {
        while (pos < N) {
            int next = cur + prev;
            if (next > 15746) next -= 15746;
            pprev = prev;
            prev = cur;
            cur = next;
            pos++;
        }
        printf("%d\n", cur);
    }
    
    return 0;
}
/*
결과 수열
0 1 2 3 5 8 13 21 34... <-- 피보나치 + 1의 형태
*/

/*
문제
지원이에게 2진 수열을 가르쳐 주기 위해, 지원이 아버지는 그에게 타일들을 선물해주셨다. 그리고 이 각각의 타일들은 0 또는 1이 쓰여 있는 낱장의 타일들이다.

어느 날 짓궂은 동주가 지원이의 공부를 방해하기 위해 0이 쓰여진 낱장의 타일들을 붙여서 한 쌍으로 이루어진 00 타일들을 만들었다. 결국 현재 1 하나만으로 이루어진 타일 또는 0타일을 두 개 붙인 한 쌍의 00타일들만이 남게 되었다.

그러므로 지원이는 타일로 더 이상 크기가 N인 모든 2진 수열을 만들 수 없게 되었다. 예를 들어, N=1일 때 1만 만들 수 있고, N=2일 때는 00, 11을 만들 수 있다. (01, 10은 만들 수 없게 되었다.) 또한 N=4일 때는 0011, 0000, 1001, 1100, 1111 등 총 5개의 2진 수열을 만들 수 있다.

우리의 목표는 N이 주어졌을 때 지원이가 만들 수 있는 모든 가짓수를 세는 것이다. 단 타일들은 무한히 많은 것으로 가정하자.

입력
첫 번째 줄에 자연수 N이 주어진다.(N ≤ 1,000,000)

출력
첫 번째 줄에 지원이가 만들 수 있는 길이가 N인 모든 2진 수열의 개수를 15746으로 나눈 나머지를 출력한다.
*/