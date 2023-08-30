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
    vector<int> v(3);
    FOR(i,0,3) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    printf("%d\n", v[1]);

    return 0;
}