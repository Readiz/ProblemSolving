#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

int main() {
    int N; scanf("%d", &N);

    set<pii> S;
    bool xp = false;
    bool xn = false;
    bool yp = false;
    bool yn = false;
    for(int i = 0; i < N; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        if (x != 0 && y != 0) {
            int g = __gcd(abs(x), abs(y));
            x = x / g;
            y = y / g;
            S.insert({x, y});
        } else {
            if (x == 0) {
                if (y > 0) yp = true;
                else yn = true;
            } else {
                if (x > 0) xp = true;
                else xn = true;
            }
        }
    }
    printf("%d\n", S.size() + xp + xn + yp + yn);


    return 0;
}