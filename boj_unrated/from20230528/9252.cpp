#include <bits/stdc++.h>
using namespace std;

// ACAYKP
// CAPCAK
// -> 4 ACAK
char A[1010];
char B[1010];
int DP[1010][1010];
int main() {
    scanf("%s %s", &A[1], &B[1]);
    A[0] = B[0] = 0;
    int alen = 0, blen = 0;
    for(char* p = &A[1]; *p != 0; ++p) ++alen;
    for(char* p = &B[1]; *p != 0; ++p) ++blen;

    // LCS 어렵다...
    for (int ap = 1; ap <= alen; ++ap) {
        for(int bp = 1; bp <= blen; ++bp) {
            if (A[ap] == B[bp]) {
                DP[bp][ap] = DP[bp-1][ap-1] + 1;
            } else {
                DP[bp][ap] = max(DP[bp][ap-1], DP[bp-1][ap]);
            }
        }
    }
    int ans = DP[blen][alen];
    printf("%d\n", ans);
    vector<char> word;
    int ap = alen, bp = blen;
    while(ap != 0 && bp != 0) {
        if (DP[bp][ap] == DP[bp][ap-1]) {
            ap--;
            continue;
        }
        if (DP[bp][ap] == DP[bp-1][ap]) {
            bp--;
            continue;
        }
        word.push_back(A[ap]);
        ap--;
        bp--;
    }

    if (word.size()) {
        for(auto it = word.rbegin(); it != word.rend(); ++it){  
            printf("%c", *it);
        }
        printf("\n");
    }
    return 0;
}