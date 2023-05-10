// sort로 푸는 방법도 있음

#include <stdio.h>
#include <set>
using namespace std;
typedef long long ll;

set<ll> s;
int main() {
    int N;
    scanf("%d", &N);
    for (register int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        s.insert(t);
    }
    scanf("%d", &N);
    for (register int i = 0; i < N; i++) {
        int t;
        scanf("%d", &t);
        if (s.find(t) != s.end()) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}