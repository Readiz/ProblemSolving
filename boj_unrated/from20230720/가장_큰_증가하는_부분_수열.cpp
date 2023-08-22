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
    int N; scanf("%d", &N);
    vector<ll> A(N+1);
    vector<ll> DP(N+1);

    for(int i = 1; i <= N; ++i) scanf("%lld", &A[i]);

    // DP[i] -> i에서의 증가하는 부분 수열의 최대 합
    // N^2 알고리즘으로 점점 채워 나간다.
    DP[1] = A[1]; // 1: 1까지의 최대 합
    ll maxval; maxval = A[1];

    // 상태 전이 식은 아래와 같이 정의할 수 있다.
    // DP[i] = max(DP[i], DP[j] + A[i]) (Only A[j] < A[i] 인 경우에만)
    for(int i = 2; i <= N; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(A[j] < A[i]) {
                DP[i] = max(DP[i], DP[j] + A[i]);
            }
        }
        if (DP[i] > maxval) maxval = DP[i];
    }

    printf("%lld\n", maxval);

    return 0;
}


#if 0
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

map<int, int> pos;
int main() {
    int N; scanf("%d", &N);
    vector<int> A; A.resize(N + 1);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &A[i]);
        if (pos.find(A[i]) == pos.end()) pos[A[i]] = i;
    }

    while (true) {
        bool isUpdated = false;
        for(auto it = pos.begin(); it != pos.end();) {
            bool isPartialUpdated = false;
            auto& item = *it;
            int csum = item.first;
            int lpos = item.second;
            for(int i = lpos + 1; i <= N; ++i) {
                if (A[lpos] < A[i]) {
                    int nsum = csum + A[i];
                    if (pos.find(nsum) == pos.end()) {
                        isPartialUpdated = isUpdated = true;
                        pos[nsum] = i;
                    } else {
                        if (pos[nsum] > i) { // 더 빠르게 도달 가능한 합을 찾음
                            isPartialUpdated = isUpdated = true;
                            pos[nsum] = i;
                        }
                    }
                }
            }
            if (isPartialUpdated) {
                it = pos.begin();
                continue;
            } else {
                ++it;
            }
        }
        if (!isUpdated) break;
    }

    printf("%d\n", pos.rbegin()->first);

    // for(auto& item: pos) {
    //     _D("%d: last: %d\n", item.first, item.second);
    // }


    return 0;
}
#endif