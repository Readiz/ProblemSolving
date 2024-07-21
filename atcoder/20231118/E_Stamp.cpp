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
#define X first
#define Y second

int N, M;
char S[200010];
char T[10];
void solve() {
    scanf("%d %d", &N, &M);
    scanf("%s", S);
    scanf("%s", T);
    if (S[0] != T[0] || S[N - 1] != T[M - 1]) {
        printf("No\n");
        return;
    }
    int state = 0;
    int invalidcounter = 0;
    for(int i = 0; i < N; ++i) {
        if (S[i] == T[state]) {
            continue;// state++;
        }
        if (state + 1 < M && S[i] == T[state + 1]) {
            ++state;
            continue;
        }
        if (state == M - 1 && S[i] == T[0]) {
            state = 0;
            continue;
        }
        // invalid한 것 발견!
        bool flag = false;
        for(int j = 0; j < M; ++j) {
            if (S[i] == T[j]) {
                state = j;
                flag = true;
                break;
            }
        }
        if (flag) {
            if (state != 0) {
                ++invalidcounter;
            }
            continue;
        } else {
            printf("No\n");
            return;
        }
    }
}

int main() {
    solve();
    return 0;
}