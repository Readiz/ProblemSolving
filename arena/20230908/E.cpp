#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N,M,K; scanf("%d%d%d", &N,&M,&K);
    int hero[201] = {0, }; // 레벨이 i인 영웅의 수
    int hero2[201] = {0, }; // 레벨이 i인 영웅의 수
    for(int i = 0; i < N; ++i) {
        int tmp; scanf("%d", &tmp);
        hero[tmp]++;
        hero2[tmp]++;
    }
    vector<pair<int,int>> v;
    for(int i = 1; i <= M; ++i) {
        int tmp; scanf("%d", &tmp);
        v.push_back({tmp, i});
    }
    sort(v.begin(), v.end());
    int mintowerlevel[201] = {0, }; // 레벨 i의 몬스터의 층수
    int mintowerlevel2[201] = {0, }; // 레벨 i의 몬스터의 층수
    for(int i = 1; i <= 200; ++i) {
        int l = 0, r = M - 1, m = M / 2, ans = -1;
        for(;l<=r; m = (l+r)/2) {
            if (v[m].first <= i) {
                ans = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        assert(ans != -1);
        mintowerlevel2[i] = mintowerlevel[i] = v[ans].second;
        mintowerlevel[i]--;
    }
    // for(int i = 1; i<= 200; ++i) {
    //     printf("[t] %d\n", mintowerlevel[i]);
    // }
    // K일동안 반복한다.
    ll otime = 0;
    for(int k = 0; k < K; ++k) {
        for(int c = 199; c >= 1; --c) {
            if (hero[c] == 0) continue;
            otime += (ll)mintowerlevel[c] * hero[c];
            hero[c+1] += hero[c];
            hero[c] = 0;
        }
    }
    // printf("[d] %lld\n", otime);
    // for(int i = 1; i<= 200; ++i) {
    //     if(hero[i] != 0)
    //     printf("[d] lv%d: %d\n", i, hero[i]);
    // }

    // 2. 수정을 완탐으로 위치시켜서 확인한다.
    ll mintime = 0x7FFFFFFFFFFFFFFFLL;
    int minx = -1, miny = -1;
    for(int x = 1; x <= M; ++x) {
        for(int y = x + 1; y <= M; ++y) {
            // 거리가 바뀐다.
            for(int i = 1; i <= 200; ++i) {
                int time1 = mintowerlevel2[i] - 1;
                int time2 = x - 1 + abs(y - mintowerlevel2[i]); // 포탈까지 가서 이동하는데 걸리는 시간
                mintowerlevel[i] = min(time1, time2);
            }
            for(int i = 1; i <= 200; ++i) {
                hero[i] = hero2[i];
            }
            // K일동안 반복한다.
            ll ntime = 0;
            for(int k = 0; k < K; ++k) {
                for(int c = 199; c >= 1; --c) {
                    if (hero[c] == 0) continue;
                    ntime += (ll)mintowerlevel[c] * hero[c];
                    hero[c+1] += hero[c];
                    hero[c] = 0;
                }
            }
            if (ntime < mintime) {
                mintime = ntime;
                minx = x;
                miny = y;
            }
        }
    }

    if (otime - mintime >= 0) {
        printf("%d %d\n", minx, miny);
        printf("%d\n", otime - mintime);
    } else {
        printf("%d %d\n", M, 1);
        printf("%d\n", 0);
    }

    return 0;
}