#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

int main() {
    int N, M, tmp; scanf("%d %d", &N, &M);
    for(int i = 0; i < 8; ++i) scanf("%d", &tmp);

    // Solution explained by lighter
    // 유일하게 1 * 2 와 2 * 1만 후공이 이길 수 있다. 곰곰이는 1*1 블럭만 사용할 수 있는데, 후공이 남은 1칸을 채우면서 승리하기 떄문.
    // 다만, 다른 경우들에는 모든 경우에 대해 베스킨라벤스 게임을 하듯 곰곰이가 무조건 따라두기 전략으로 남은 턴수를 짝수번으로 유지할 수 있다.

    if (N * M == 2) printf("ChongChong\n");
    else printf("GomGom\n");
    return 0;
}