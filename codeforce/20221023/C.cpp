#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#define R register
#define FOR(i,a,b) for(R int i=(a); ((i)^(b)); ++i)
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define _D(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;

int N;
void solve() {
    scanf("%d", &N);
    int last, lastp = 1;
    scanf("%d", &last);
    bool zeromode = false;
    if (last == 0) zeromode = true;

    vector<pair<int,int>> fle; // {0, 1, 1, ...}
    vector<pair<int,int>> flo; // {0, 1, 1, ...}
    vector<pair<int,int>> fnle; // {0, -1, -1, ...}
    vector<pair<int,int>> fnlo; // {0, -1, -1, ...}
    vector<pair<int,int>> le; // {1, 1, 1, 1, ...}
    vector<pair<int,int>> lo; // {1, 1, 1, 1, ...}
    vector<pair<int,int>> nle; // {-1, -1, -1, ...}
    vector<pair<int,int>> nlo; // {-1, -1, -1, ...}
    vector<pair<int,int>> z; // {0, 0, 0, ...}
    FOR(i,2,N+1) {
        int c;
        scanf("%d", &c);
        if (last == c) continue;
        // 여기 온건 이제 다르다는 뜻
        if (last == 0) {
            // 0, 0, ... , 0, +-1 <- i
            if (i - 2 >= lastp) {
                z.push_back(make_pair(lastp, i-2));
            }
            lastp = i-1; // 0이 있는 지점
            zeromode = true;
        } else {
            if (c == 1) {
                // -1 -> 1
                if (zeromode) {
                    if ((i - lastp) % 2 == 0) {
                        fnle.push_back(make_pair(lastp, i-1));
                    } else {
                        fnlo.push_back(make_pair(lastp, i-1));
                    }
                } else {
                    if ((i - lastp) % 2 == 0) {
                        nle.push_back(make_pair(lastp, i-1));
                    } else {
                        nlo.push_back(make_pair(lastp, i-1));
                    }
                }
                lastp = i;
                zeromode = false;
            } else if (c == -1) {
                // 1 -> -1
                if (zeromode) {
                    if ((i - lastp) % 2 == 0) {
                        fle.push_back(make_pair(lastp, i-1));
                    } else {
                        flo.push_back(make_pair(lastp, i-1));
                    }
                } else {
                    if ((i - lastp) % 2 == 0) {
                        le.push_back(make_pair(lastp, i-1));
                    } else {
                        lo.push_back(make_pair(lastp, i-1));
                    }
                }
                lastp = i;
                zeromode = false;
            } else {
                if (zeromode) {
                    if (last == 1) {
                        if ((i - lastp + 1) % 2 == 0) {
                            fle.push_back(make_pair(lastp, i-1));
                        } else {
                            flo.push_back(make_pair(lastp, i-1));
                        }
                    } else {
                        if ((i - lastp + 1) % 2 == 0) {
                            fnle.push_back(make_pair(lastp, i-1));
                        } else {
                            fnlo.push_back(make_pair(lastp, i-1));
                        }
                    } 
                } else {
                    if (last == 1) {
                        if ((i - lastp) % 2 == 0) {
                            le.push_back(make_pair(lastp, i-1));
                        } else {
                            lo.push_back(make_pair(lastp, i-1));
                        }
                    } else {
                        if ((i - lastp) % 2 == 0) {
                            nle.push_back(make_pair(lastp, i-1));
                        } else {
                            nlo.push_back(make_pair(lastp, i-1));
                        }
                    } 
                }
                lastp = i;
                zeromode = true;
            }
        }
        last = c;
    }
    if (zeromode) {
        if (last == 1) {
            if ((N - lastp + 1) % 2 == 0) {
                fle.push_back(make_pair(lastp, N));
            } else {
                flo.push_back(make_pair(lastp, N));
            }
        } else if (last == -1) {
            if ((N - lastp + 1) % 2 == 0) {
                fnle.push_back(make_pair(lastp, N));
            } else {
                fnlo.push_back(make_pair(lastp, N));
            }
        } else {
            z.push_back(make_pair(lastp, N));
        }
    } else {
        if (last == 1) {
            if ((N - lastp + 1) % 2 == 0) {
                le.push_back(make_pair(lastp, N));
            } else {
                lo.push_back(make_pair(lastp, N));
            }
        } else if (last == -1) {
            if ((N - lastp + 1) % 2 == 0) {
                nle.push_back(make_pair(lastp, N));
            } else {
                nlo.push_back(make_pair(lastp, N));
            }
        } else {
            z.push_back(make_pair(lastp, N));
        }
    }
    vector<pair<int,int>> ans;
    _D("%d vs %d\n", lo.size() + fnlo.size(), nlo.size() + flo.size());
    while (lo.size() + fnlo.size() > nlo.size() + flo.size()) {
        int diff = lo.size() + fnlo.size() - nlo.size() - flo.size();
        if (diff % 2 == 0) {
            if (fnlo.size() > 0) {
                pair<int,int> p = fnlo[fnlo.size() - 1];
                fnlo.pop_back();
                nlo.push_back({p.first+1, p.second});
                z.push_back({p.first, p.first});
                continue;
            }
            if (le.size() > 0) {
                pair<int,int> p = le[le.size() - 1];
                le.pop_back();
                if (p.second - p.first == 0) {
                    ans.push_back(p);
                } else {
                    lo.push_back({p.first, p.first});
                    lo.push_back({p.first + 1, p.second});
                }
                continue;
            }
            if (lo.size() > 0) {
                pair<int,int> p = lo[lo.size() - 1];
                lo.pop_back();
                if (p.second - p.first == 0) {
                    ans.push_back(p);
                } else {
                    lo.push_back({p.first, p.first});
                    le.push_back({p.first + 1, p.second});
                }
                continue;
            }
            printf("-1\n");
            return;
        } else {
            printf("-1\n");
            return;
        }
    }
    while (nlo.size() + flo.size() > lo.size() + fnlo.size()) {
        int diff = nlo.size() + flo.size() - lo.size() - fnlo.size();
        if (diff % 2 == 0) {
            if (flo.size() > 0) {
                pair<int,int> p = flo[fnlo.size() - 1];
                flo.pop_back();
                lo.push_back({p.first+1, p.second});
                z.push_back({p.first, p.first});
                continue;
            }
            if (nle.size() > 0) {
                pair<int,int> p = nle[nle.size() - 1];
                nle.pop_back();
                if (p.second - p.first == 0) {
                    ans.push_back(p);
                } else {
                    nlo.push_back({p.first, p.first});
                    nlo.push_back({p.first + 1, p.second});
                }
                continue;
            }
            if (nlo.size() > 0) {
                pair<int,int> p = nlo[nlo.size() - 1];
                nlo.pop_back();
                if (p.second - p.first == 0) {
                    ans.push_back(p);
                } else {
                    nlo.push_back({p.first, p.first});
                    nle.push_back({p.first + 1, p.second});
                }
                continue;
            }
            printf("-1\n");
            return;
        } else {
            printf("-1\n");
            return;
        }
    }
    FOR(i,0,z.size()) ans.push_back(z[i]);
    FOR(i,0,lo.size()) ans.push_back(lo[i]);
    FOR(i,0,le.size()) ans.push_back(le[i]);
    FOR(i,0,flo.size()) ans.push_back(flo[i]);
    FOR(i,0,fle.size()) ans.push_back(fle[i]);
    FOR(i,0,nlo.size()) ans.push_back(nlo[i]);
    FOR(i,0,nle.size()) ans.push_back(nle[i]);
    FOR(i,0,fnlo.size()) ans.push_back(fnlo[i]);
    FOR(i,0,fnle.size()) ans.push_back(fnle[i]);
    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    FOR(i,0,ans.size()) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}

MAIN_START
    _D("--------------------------\n");
    _D("TEST START!!!\n");
    _D("--------------------------\n");
    int tc;
    scanf("%d", &tc);
    FOR(TC,0,tc) {
        solve();
    }
MAIN_END
