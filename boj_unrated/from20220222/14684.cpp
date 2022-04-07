#include <stdio.h>

typedef long long ll;
#define R register
int n, q;
int A[1000 + 1];
ll S[1000 + 1];

void update(int idx, int diff) {
    while (idx <= n) {
        S[idx] += diff;
        idx += (idx & -idx);
    }
}

ll get(int idx) {
    ll r = 0LL;
    while (idx > 0) {
        r += S[idx];
        idx -= (idx & -idx);
    }
    return r;
}


int main() {
    scanf("%d %d", &n, &q);
    for (R int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);
        A[i] = tmp;
        update(i, A[i]);
    }
    while (q--) {
        int cmd, a, b, c, d;
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d %d", &a, &b);
            printf("%lld\n", get(b) - get(a - 1));
            int olda = A[a];
            int oldb = A[b];
            int diffa = oldb - olda;
            int diffb = olda - oldb;
            update(a, diffa);
            update(b, diffb);
            A[a] = oldb;
            A[b] = olda;
        } else {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            ll sumab = get(b) - get(a - 1);
            ll sumcd = get(d) - get(c - 1);
            printf("%lld\n", sumab - sumcd);
        }
    }
}

/*
쿼리 맛보기
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
2 초	256 MB	1555	563	468	39.966%
문제
어떤 문제에 비슷한 형태의 질문이 여러 개 주어지는 문제를 쿼리 문제라고 부른다. 쿼리 문제는 쿼리가 주어진 순서대로 실행해서 해결할 수도 있지만, 그것이 불가능하거나 조건이 맞는 경우에는 쿼리의 순서를 임의로 바꿔서 더 편하게 해결할 수도 있다. 우리는 예선 문제에 쿼리에 대한 설명이 등장했기 때문에 본선 문제에 쿼리 문제가 나올 것이라는 예상을 쉽게 해볼 수 있다.

이 문제에서는 길이 n의 수열과 q개의 쿼리가 주어진다. 주어지는 쿼리의 종류는 다음과 같다.

1 a b : [a, b] 구간의 합을 구해서 출력하고, a번째 수와 b번째 수를 서로 스왑(swap) 한다.
2 a b c d : [a, b] 구간의 합에서 [c, d] 구간의 합을 뺀 값을 출력한다.
[a, b] 구간의 합이란, 수열의 a번째 부터 b번째 까지 수를 모두 더한 값을 의미한다.

입력
첫째 줄에 수열의 길이를 뜻하는 n(1 ≤ n ≤ 1,000)과 쿼리의 개수를 뜻하는 q(1 ≤ q ≤ 10,000)가 주어진다. 둘째 줄에 길이 n의 수열이 하나의 공백을 사이에 두고 주어진다. 수열의 각 수는 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 정수이다. 이후 셋째 줄 부터 q개의 줄에 걸쳐 쿼리가 주어진다. 쿼리의 형식은 “1 a b” 또는 “2 a b c d”이다. a, b, c, d는 n보다 작거나 같은 자연수이며, a ≤ b, c ≤ d임이 보장된다.

출력
주어진 쿼리의 출력값을 q개의 줄에 걸쳐 출력한다.

예제 입력 1 
5 2
3 5 -2 3 -12
2 1 3 2 4
1 2 5
예제 출력 1 
0
-6
예제 입력 2 
7 3
12 5 -1 0 -4 3 -10
1 2 7
2 1 4 2 3
2 1 7 3 4
예제 출력 2 
-7
12
6
*/
