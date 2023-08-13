#include <bits/stdc++.h>
 
std::mt19937 rng(20200116);
 
std::uniform_int_distribution<int> genbinary(0, 1);
 
using lint = long long;
 
 
lint gcd(lint a, lint b) {
    return b ? gcd(b, a%b) : a;
}
 
struct Fraction {
    lint j, m;
    Fraction(lint j_ = 0, lint m_ = 1) { 
        lint g = gcd(j_, m_);
        j = j_ / g;
        m = m_ / g;
    }
 
    Fraction operator+ (const Fraction &other) const {
        return Fraction(j * other.m + m * other.j, m * other.m);
    }
    Fraction operator- (const Fraction &other) const {
        return Fraction(j * other.m - m * other.j, m * other.m);
    }
    bool operator< (const Fraction &other) const {
        return j * other.m - m * other.j < 0;
    }
    Fraction operator* (const Fraction &other) const {
        return Fraction(j * other.j, m * other.m);
    }
};
 
void solve() {
    int N; scanf("%d", &N);
 
    std::vector<std::vector<int>> gph(N);
    std::vector<bool> decided(N);
    std::vector<Fraction> ans(N);
    std::vector<int> indeg(N);
    {
        int M; scanf("%d", &M);
        while(M--) {
            int u, v; scanf("%d%d", &u, &v);
            u -= 1;
            v -= 1;
            gph[u].push_back(v);
            indeg[v] += 1;
        }
    }
 
    decided.front() = true; ans.front() = Fraction(0, 1);
    decided.back() = true;  ans.back() = Fraction(1, 1);
 
    while(!*std::min_element(decided.begin(), decided.end())) {
        std::vector<int> new_path;
        Fraction new_diff((long long)1e9, 1);
 
        for(int st = 0; st < N; st++) if(decided[st]) {
            std::vector<int> len_path(N, -1);
            std::vector<int> par_path(N, -1);
 
            len_path[st] = 0;
            for(int u = st; u < N; u++) {
                if(len_path[u] >= 0 && (u == st || !decided[u])) {
                    for(int v : gph[u]) if(len_path[v] < len_path[u]+1) {
                        len_path[v] = len_path[u]+1;
                        par_path[v] = u;
                    }
                }
            }
 
            for(int u = st+1; u < N; u++) {
                if(len_path[u] >= 2 && decided[u]) {
                    Fraction diff = (ans[u] - ans[st]) * Fraction(1, len_path[u]);
                    if(diff < new_diff) {
                        new_diff = diff;
                        new_path.clear();
                        for(int i = u; i != -1; i = par_path[i]) new_path.push_back(i);
                        std::reverse(new_path.begin(), new_path.end());
                    }
                } 
            }
        }
 
        assert(!new_path.empty());
        for(int i = 1; i+1 < new_path.size(); i++) {
            ans[new_path[i]] = ans[new_path[i-1]] + new_diff;
            decided[new_path[i]] = true;
        }
    }
 
    bool first = true;
 
    for(const Fraction &frac : ans) {
        if(!first) putchar(' ');
        printf("%lld %lld", frac.j, frac.m);
        first = false;
    }
    puts("");
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
 
    int Test, test_case = 1;
    scanf("%d", &Test);
    while (Test--) {
        printf("#%d ", test_case++);
        solve();
    }
 
    return 0;
}