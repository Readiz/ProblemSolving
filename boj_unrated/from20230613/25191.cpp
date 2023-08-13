#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,b; scanf("%d%d%d",&n,&a,&b);
    printf("%d\n", min((a>>1)+b,n),b);
    return 0;
}