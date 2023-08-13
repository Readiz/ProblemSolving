#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
#define _D(...)
#else
#define _D(...) printf(__VA_ARGS__)
#endif

typedef long long ll;
ll h[100010];
int N;
int s[100010]; // 현재 스택에 들어있는 index는 w의 index
int sp;
int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &h[i]);
    }
    s[sp++] = 0; // 0번을 넣고 시작한다.
    ll maxVal = 0;
    for(int i = 1; i <= N + 1; ++i) { // N + 1: 마지막에 다 뺀 것을 생각하기 위한 트릭
        ll& cur = h[i];
        // 이 경우 더 작은 애가 새로 추가되려고 하는 것, 로직 시작
        while (h[s[sp-1]] > cur) {
            --sp; // stack pop

            int width = i - s[sp-1] - 1;
            ll height = h[s[sp]];
            ll area = height * width;
            _D("cur area: %lld\n", area);
            if (area > maxVal) maxVal = area;
        }
        s[sp++] = i; // 현재 보고 있는 녀석을 스택에 추가 한다. case 1) 그냥 추가, case 2) 위에서 뺀 뒤에 추가.
    }
    printf("%lld\n", maxVal);
    return 0;
}
