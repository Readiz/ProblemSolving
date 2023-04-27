#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

#define R register
#define FOR(i,a,b) for(R int i=(a);((i)^(b)); ++i)
#define _D(...) printf(__VA_ARGS__)


int main() {
    int N;
    int S;
    scanf("%d", &N);
    scanf("%d", &S);
    int A[10];
    A[0] = S;
    FOR(i,1,N) {
        int bS = S;
        scanf("%d", &S);
        A[i] = S - bS;
    }
    FOR(i,0,N) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}