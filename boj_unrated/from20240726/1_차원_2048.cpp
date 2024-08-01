#include <bits/stdc++.h>
using namespace std;

map<unsigned long long,int> M;

int main() {
    int N; scanf("%d", &N);
    for(int i=0;i<N;++i) {
        unsigned long long c; scanf("%llu", &c);
        if (c == 0) continue;
        if (M.find(c) == M.end()) M[c] = 1;
        else M[c] += 1;
    }

    while (true) {
        bool flag = false;
        for(auto it = M.begin(); it != M.end();) {
            if (it->second >= 2) {
                flag = true;
                int half = it->second / 2;
                M[it->first << 1] += half;
                it->second -= half * 2;
                if (it->second == 0) it = M.erase(it);
                else ++it;
            } else ++it;
        }
        if (!flag) break;
    }
    printf("%llu\n", M.rbegin()->first);

    return 0;
}