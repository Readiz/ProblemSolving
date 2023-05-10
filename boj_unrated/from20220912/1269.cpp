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

unordered_set<int> A, B, AB, BA;
int NA, NB, t;
int main() {
    scanf("%d %d", &NA, &NB);
    FOR(i,0,NA) {
        scanf("%d", &t);
        A.insert(t);
        AB.insert(t);
    }
    FOR(i,0,NB) {
        scanf("%d", &t);
        B.insert(t);
        BA.insert(t);
    }
    for(auto& item: B) {
        auto it = AB.find(item);
        if (it != AB.end()) {
            AB.erase(it);
        }
    }
    for(auto& item: A) {
        auto it = BA.find(item);
        if (it != BA.end()) {
            BA.erase(it);
        }
    }
    printf("%d\n", AB.size() + BA.size());
}