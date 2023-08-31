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
    int x, N; scanf("%d %d", &x, &N);
    for(int i = 0; i < N; ++i) {
        if (x % 2 == 0) {
            x = (x / 2 + x % 2) ^ 6;
        } else {
            x = (2 * x) ^ 6;
        }
    }
    printf("%d\n", x);

    return 0;
}

/*
NLCS에는 분수가 많다.

분수에서 나오는 물의 높이는 특정한 규칙에 따라 변화하는데, 어떤 정수 시각 
$t$에서의 분수의 높이가 정수 
$x_t$일 때, 
$x_{t+1}$는 
$x_t$가 짝수라면 
 
$\lfloor \frac{x_t}{2} \rfloor \oplus 6$, 
$x_t$가 홀수라면 
$(2 \cdot x_t) \oplus 6$과 같다.

 
$0$초에서의 분수의 높이가 주어졌을 때, 
$N$초에서의 분수의 높이를 구하는 프로그램을 작성하시오.
*/