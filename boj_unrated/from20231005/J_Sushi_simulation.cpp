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
#define X first
#define Y second

// 상상을 해보자
// 1 1 1
// 1 * 1 
// -> 첫번째 주사위에서는 뭐가 나오든 1개 줄어짐 -> 기대값 1
// 0 1 1
// -> 두번째 주사위에서는 2/3 확률로 줄어듬
// 1/3 * 0 + 1/3 * 1 + 1/3 * 1 = 2/3 -> 몇번 던지냐니까 역수임. -> 1.5
// 0 0 1
// 0 * 3 + 0 * 3 + 1 * 3 = 1
// ---------------------------
// 1개씩 있는건 그렇다 치고.. 2개씩 있으면???

// 2 2 2
// 1 2 2
// 0 2 2 or 1 1 2
// 줄어들 확률 달라짐 ㅡㅡ

// # TC 1
// ----------------------------
// 거꾸로 생각하기
// 0 0 0 부터 시작하자.
// 1 0 0  (100% 확률)   1
// 1 1 0  (2/3 확률)    1.5
// 1 1 1  (1/3 확률)    3

// # TC 2
// ----------------------------
// 0
// 1  (100%)  1
// 2  (100%)  1
// 3  (100%)  1
// -> 3

// # TC 3
// ----------------------------
// 0 0
// 1 0   (100%)
// 1 1   (50%)  or    2 0   (50%)  ->  (합 100%)
// 2 1   (50%)

// 시뮬레이션 (미친짓)
unsigned int seed = 5;
int mrand() {
    seed = 214013 * seed + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int N;
void solve() {
    scanf("%d", &N);
    vector<int> v(N);
    for(auto& i : v) scanf("%d", &i);

    double ans = 0;
    int cntTest = 100000;
    for(int numcnt = 0; numcnt < cntTest; ++numcnt) {
        vector<int> cur = v;
        int zeroCnt = 0;
        int numRoll = 0;
        while(zeroCnt != N) {
            int k = mrand() % N;
            ++numRoll;
            if (cur[k] == 0) continue;
            else {
                cur[k]--;
                if (cur[k] == 0) ++zeroCnt;
            }
        }
        ans += numRoll;
    }
    printf("%.15lf\n", ans / (double)cntTest);
}

int main() {
    solve();
    return 0;
}