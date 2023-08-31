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