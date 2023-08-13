#include <stdio.h>

struct Person {
    int h;
    int size;
};
int S[500001];
Person P[500001];
int main() {
    int N; scanf("%d", &N);
    int sp = 0;
    long long ans = 0;
    
    for(int i = 0; i < N; ++i) {
        int height; scanf("%d", &height);
        P[i] = {height, 1};
    }
    for(int i = 0; i < N;) {
        if (sp == 0) {
            // 비어있으면 얌전히 넣는다.
            S[sp++] = i;
            ++i;
            continue;
        }
        if (P[S[sp-1]].h > P[i].h) { // 스택에 얌전히 넣는 case
            // 1. 그 이전 애와 1개의 쌍이 무조건 생긴다.
            ++ans;
            S[sp++] = i; // 현재 index를 stack에 추가한다.
            ++i; // 다음 index 탐색 지속
            continue;
        } else if (P[S[sp-1]].h == P[i].h) {
            P[i].size += P[S[sp-1]].size;
            ans += P[S[sp-1]].size;
            --sp;
            // index 탐색은 계속 하지 않고 현재 i를 계속 들고 비교한다.
        } else {
            ans += P[S[sp-1]].size;
            --sp;
        }
    }
    printf("%lld\n", ans);
    return 0;
}