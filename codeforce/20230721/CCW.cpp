#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

struct P {
    int x, y;
    P operator-(const P& t) {
        return P{x - t.x, y - t.y};
    }
};

int cross(P& a, P& b) {
    return a.x * b.y - a.y * b.x;
}

int main() {
    P a, b, c;
    scanf("%d %d %d %d %d %d", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    P ba = b - a;
    P bc = b - c;
    int res = cross(ba, bc);
    if (res > 0) printf("-1\n");
    else if (res < 0) printf("1\n");
    else printf("0\n");

    return 0;
}