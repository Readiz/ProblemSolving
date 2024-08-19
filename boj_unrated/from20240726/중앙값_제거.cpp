// 음.. 생각을 해보자
// 중앙값.. 에 시선을 뺏기지 말고
// [1 2 3] 이 있다하면
// 적어도 3개중 2개가 0이 되어야 하는 것
// 몇번만에 큰놈들이 1이 되는가? 를 보면 될듯
// 정렬 이후에.. 파악하면 된다.
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d",&n);
    vector<int> v(n);
    for(auto&i:v) scanf("%d", &i);
    sort(v.begin(),v.end());
    // -> 충분히 1이 되고 나서야.. 결국 가운데가 0이 된다.
    int m=(n+1)/2-1;
    int ans=1;
    for(int i=0;i<=m;++i) {
        while(v[i]>1) {
            v[i]>>=1;
            ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}