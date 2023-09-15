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

int N;
void solve() {
    scanf("%d", &N);
    vector<int> w(N+1);
    int sum = 0;
    FOR(i,1,N+1) {
        scanf("%d", &w[i]);
        sum += w[i];
    }
    int half = N / 2;

    int DPMIN[51]; // 학생이 N명일 때 최소 몸무게
    int DPMAX[51]; // 학생이 N명일 때 최대 몸무게
    memset(DPMIN, 0x3A, sizeof(int) * 51);
    memset(DPMAX, 0x00, sizeof(int) * 51);
    DPMIN[0] = 0;
    DPMAX[0] = 0;

    for(int i = 1; i <= N; ++i) { // i 번째 학생을 본다
        for(int j = 0; j <= i; ++j) {
            DPMIN[i] = min(DPMIN[i], DPMIN[i - 1] + w[i]);
            DPMAX[i] = max(DPMAX[i], DPMAX[i - 1] + w[i]);
        }
    }
    printf("[d] half: %d, %d\n", DPMIN[half], DPMAX[half]);
}

int main() {
    solve();
    return 0;
}