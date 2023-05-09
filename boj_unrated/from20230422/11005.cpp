#include <bits/stdc++.h>
using namespace std;

int main() {
    char buf[1000];
    int N;
    int oval;
    scanf("%d %d", &oval, &N);

    int p = 0;
    for(; oval > 0; ++p, oval /= N) {
        int cv = oval % N;
        if (cv < 10) {
            buf[p] = cv + '0';
        } else {
            buf[p] = cv - 10 + 'A';
        }
    }
    
    for(--p; p >= 0; --p) {
        printf("%c", buf[p]);
    }
    printf("\n");
    
    return 0;
}