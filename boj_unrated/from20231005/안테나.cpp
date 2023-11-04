#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; scanf("%d", &N);
    vector<int> v(N);
    for(auto& i: v) scanf("%d", &i);
    sort(v.begin(), v.end());
    printf("%d\n", v[((N+1)>>1)-1]);

    return 0;
}