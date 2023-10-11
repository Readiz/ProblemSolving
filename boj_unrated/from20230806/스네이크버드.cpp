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
    int N, L; scanf("%d %d", &N, &L);
    vector<int> a(N);
    for(auto& item: a) scanf("%d", &item);
    sort(a.begin(), a.end());

    for(auto& i:a) {
        if (i <= L) {
            L += 1;
        } else {
            break;
        }
    }

    printf("%d\n", L);
    
    return 0;
}