#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K; scanf("%d %d", &N, &K);
    vector<int> A(N);
    for(auto& i: A) scanf("%d", &i);

    vector<pair<pair<int,int>,int>> v;
    int acc = 0;
    for(int i = 0; i < N; ++i) {
        v.push_back({{acc, acc + A[i]}, i + 1});
        acc += A[i];
    }
    int full = acc;
    for(int i = N - 1, j = N; i >= 0; --i, --j) {
        v.push_back({{acc, acc + A[i]}, j});
        acc += A[i];
    }
    for(auto& i: v) {
        auto range = i.first;
        auto idx = i.second;
        if (K >= range.first && K < range.second) {
            printf("%d\n", idx);
        }
        // printf("[%d ~ %d]: %d\n", range.first, range.second, idx);
    }
    return 0;

}

