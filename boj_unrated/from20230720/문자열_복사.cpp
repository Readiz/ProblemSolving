#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct Partial {
    int l, r, len;
    bool operator<(const Partial& t) const {
        if (len != t.len) return len > t.len;
        if (l != t.l) return l < t.l;
        return r < t.r;
    }
};

constexpr int MOD = 100007;
char S[1001], P[1001];
vector<Partial> HT[MOD];
int main() {
    scanf("%s %s", S, P);
    int slen = strlen(S);
    int plen = strlen(P);

    for(int i = 0; i < slen; ++i) {
        int hval = 0;
        for(int j = i; j < slen; ++j) {
            hval = (((hval << 5) | hval) + S[j]) % MOD;
            HT[hval].push_back({i, j, j - i + 1});
        }
    }
    for(int i = 0; i < MOD; ++i) {
        if (HT[i].size() != 0) {
            sort(HT[i].begin(), HT[i].end());
            // printf("[d] %d: num: %ld\n", i, HT[i].size());
            // for(int l = HT[i][0].l; l <= HT[i][0].r; ++l) {
            //     printf("%c", S[l]);
            // }
            // printf("\n");
        }
    }
    
    int ans = 0;
    for(int i = 0; i < plen; ++i) {
        int hval = 0;
        int foundlen = -1;
        for(int j = i; j < plen; ++j) {
            hval = (((hval << 5) | hval) + P[j]) % MOD;
            bool gFound = false;
            for(auto& item: HT[hval]) {
                if (item.len != j - i + 1) continue;
                bool found = true;
                for(int p = item.l, offset = 0; p <= item.r; ++p, ++offset) {
                    if (S[p] != P[i + offset]) {
                        found = false;
                        break;
                    }
                }
                if (found) {
                    foundlen = j - i + 1;
                    gFound = true;
                    // printf("found: ");
                    // for(int p = i; p <=j; ++p) {
                    //     printf("%c", P[p]);
                    // }
                    // printf("\n");
                    break;
                }
            }
            if (gFound == false) break;
        }
        if (foundlen == -1) {
            assert(false && "CANNOT MATCH!");
        }
        i += foundlen - 1;
        ans += 1;
    }

    printf("%d\n", ans);
    return 0;
}