#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char buf[1000];
int main() {
    int N, M;
    scanf("%d", &N);

    vector<string> v;
    set<string> words;
    int idx = -1;
    for(int i = 0; i < N; ++i) {
        scanf("%s", buf);
        string s = buf;
        v.push_back(s);
        words.insert(s);
        if (s == "?") idx = i;
    }

    set<string> can;
    scanf("%d", &M);
    for(int i = 0; i < M; ++i) {
        scanf("%s", buf);
        string s = buf;

        if (N == 1 && M == 1) {
            printf("%s\n", s.c_str());
            return 0;
        }

        if (words.find(s) == words.end()) {
            if (idx > 0 && idx < N - 1) {
                if (s[0] == v[idx-1][v[idx-1].size() - 1] && 
                    s[s.size() - 1] == v[idx+1][0]) {
                    can.insert(s);
                }
            } else if (idx > 0) {
                if (s[0] == v[idx-1][v[idx-1].size() - 1])
                    can.insert(s);
            } else if (idx < N - 1) {
                if (s[s.size() - 1] == v[idx+1][0])
                    can.insert(s);
            }
        }
    }

    printf("%s\n", (*can.begin()).c_str());

    return 0;
}