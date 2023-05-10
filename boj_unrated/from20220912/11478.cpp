#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif
#define FOR(i,a,b) for(R int i=(a);((i)^(b));++i)

#include <bits/stdc++.h>
using namespace std;

unordered_set<string> strs;
char buf[1010];
int main() {
    scanf("%s", buf);
    int len = strlen(buf);

    FOR(i,0,len) {
        FOR(j,i+1,len+1) {
            char t = buf[j];
            buf[j] = 0;
            strs.insert(&buf[i]);
            buf[j] = t;
        }
    }
    printf("%d\n", strs.size());

    // for(auto& item: strs) {
    //     printf("%s\n", item.c_str());
    // }
}