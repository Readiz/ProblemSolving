#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N; scanf("%d", &N);
    vector<int> v(N);
    for(auto& i: v) scanf("%d", &i);
    sort(v.begin(), v.end());
    for(auto& i: v) printf("%d ", i);

    return 0;
}