#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("D_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define R register
typedef unsigned long long ull;
typedef long long ll;

class People {
    public:
        // Note that there is _no_ conversion constructor,
        // everything is done at the template level without
        // intermediate object creation.
        People(int id, int cnt) : id(id), cnt(cnt) {}
        int id;
        int cnt;
};
bool operator<(const People& c, const People& d) {
    return c.cnt < d.cnt;
}
bool operator>(const People& c, const People& d) {
    return c.cnt > d.cnt;
}



MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        set<People, std::less<>> s;
        vector<pair<int, int>> v;
        int n;
        scanf("%d", &n);
        for (R int i = 1; i <= n; i++) {
            int cnt;
            scanf("%d", &cnt);
            s.insert(People(i, cnt));
        }
        
        //   for (const auto& elem : s) {
        //     printd("#%d: %d", elem.id, elem.cnt);
        // }
        while (true) {
            auto most = --s.end();
            printd("MOST - #%d: %d", most->id, most->cnt);
            int mid = most->id;
            int mcnt = most->cnt;

            if (mcnt == 0) break;

            int lid, lcnt;
            auto least = s.begin();

            while (true) {
                least = s.begin();
                printd("LEAST - #%d: %d", least->id, least->cnt);
                lid = least->id;
                lcnt = least->cnt;

                if (lcnt != 0) break;
                s.erase(least);
            }

            // 숫자 감소 시키기
            if (lid == mid) break;
            if (s.size() == 0) break;

            printd("Added! %d, %d", lid, mid);
            v.push_back(make_pair(lid, mid));

            s.erase(most);
            s.erase(least);
            s.insert(People(mid, mcnt - 1));
            s.insert(People(lid, lcnt - 1));

        }

        printf("%d\n", v.size());
        for (const auto& elem : v) {
            printf("%d %d\n", elem.first, elem.second);
        }

    }
MAIN_END
