#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    ll X, Y, W, S; scanf("%lld%lld%lld%lld", &X, &Y, &W, &S);

    if (X == 0 || Y == 0) {
        printf("%lld\n", (X+Y) * W);
    } else {
        if (W * 2 <= S) {
            printf("%lld\n", (X+Y) * W);
        } else if (S <= W) {
            // 모든 이동을 대각선으로 처리하는게 낫다.
        } else {
            // 딱 애매한 정도까지 대각선으로 처리하는게 낫다.
            ll M = min(X,Y);
            ll base = M * S; // 여기까지는 대각선이 무조건 유리
            
        }
    }

    

    return 0;
}