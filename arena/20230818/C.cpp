#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char buf[400];
int main() {
    int N, M, K; scanf("%d %d %d", &N, &M, &K);
    vector<string> v;
    for(int i = 0; i < N; ++i) {
        scanf("%s", buf);
        int cnt[300] = {0,};
        for(int p = 0; buf[p] != 0; ++p) {
            cnt[buf[p]]++;
        }
        string tmp = "";
        for(int p = 'A'; p <= 'Z'; ++p) {
            for(int c = 0; c < cnt[p]; ++c) {
                tmp += p;
            }
        }
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    int cnt[300] = {0,};
    for(int k = 0; k < K; ++k) {
        const char* cur = v[k].c_str();
        for(int i = 0; i < M; ++i) {
            cnt[cur[i]]++;
        }
    }
    string tmp = "";
    for(int p = 'A'; p <= 'Z'; ++p) {
        for(int c = 0; c < cnt[p]; ++c) {
            tmp += p;
        }
    }
    printf("%s\n", tmp.c_str());


    return 0;
}