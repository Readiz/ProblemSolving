#include <bits/stdc++.h>
using namespace std;

int getlen(long long v) {
    int ret=0;
    while(v) {
        ++ret;
        v/=10;
    }
    return ret;
}
int main() {
    long long n;scanf("%lld", &n);
    int len=min(getlen(n),10);
    long long sunit=1; for(int i=1;i<len;++i) sunit*=10;
    int db[10];for(int i=0;i<10;++i) db[i]=i;

    long long ans=-1;
    long long diff=1e15;
    do {
        long long cur=0;
        for(long long i=0,unit=sunit;i<len;++i,unit/=10) {
            cur+=db[i]*unit;
        }
        if (abs(cur - n) < diff) {
            ans = cur;
            diff = abs(cur - n);
        }
    } while(next_permutation(db,db+10));
    printf("%lld\n", ans);
    return 0;
}