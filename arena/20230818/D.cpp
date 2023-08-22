#include <bits/stdc++.h>
using namespace std;

#define _D(...) // printf(__VA_ARGS__)

typedef long long ll;
typedef unsigned long long ull;

struct Data {
    ll first;
    ll second;
    bool operator<(const Data& t) const {
        if (first != t.first) return first < t.first;
        return second < t.second;
    }
};
int main() {
    int N;
    scanf("%d", &N);

    vector<ll> v;
    for(int i = 0; i < N; ++i) {
        ll tmp; scanf("%lld", &tmp); v.push_back(tmp);
    }
    reverse(v.begin(), v.end());

    ll gBase = 0;

    vector<ll> pSum; pSum.resize(N);
    pSum[0] = v[0];
    for(int i = 1; i < N; ++i) {
        pSum[i] = pSum[i - 1] + v[i];
    }

    vector<Data> candi; candi.resize(N);
    candi[0] = {v[0], 0};
    for(int i = 1; i < N; ++i) {
        candi[i] = {v[i], i};
    }
    sort(candi.begin(), candi.end());
    reverse(candi.begin(), candi.end());

    ll A = 0, B = 0;
    int lsel = -1;
    bool isAturn = true;
    for(int i = 0; i < N;) {
        if (candi[i].second <= lsel) {
            ++i; // 그리디 전략에서 이미 튀어 나갔음
            continue;
        }

        _D("cur profit: %lld\n", candi[i].first);
        if (candi[i].first > 0) {
            _D("isA = %d / sel: %d / profit: %lld\n", isAturn, lsel, candi[i].first);
            if (isAturn) {
                A += v[candi[i].second];
                B += pSum[candi[i].second] - v[candi[i].second] - gBase;
                isAturn = false;
            } else {
                B += v[candi[i].second];
                A += pSum[candi[i].second] - v[candi[i].second] - gBase;
                isAturn = true;
            }
            lsel = candi[i].second;
            gBase = pSum[candi[i].second];
        } else {
            // 기권하는게 낫다
            if (isAturn) {
                B += pSum[N - 1] - gBase;
            } else {
                A += pSum[N - 1] - gBase;
            }
            break;
        }
    }

    printf("%d\n", A);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// typedef unsigned long long ull;

// int main() {
//     int N;
//     scanf("%d", &N);

//     vector<ll> v;
//     for(int i = 0; i < N; ++i) {
//         ll tmp; scanf("%lld", &tmp); v.push_back(tmp);
//     }
//     reverse(v.begin(), v.end());

//     vector<ll> pSum; pSum.resize(N);
//     pSum[0] = v[0];
//     for(int i = 1; i < N; ++i) {
//         pSum[i] = pSum[i - 1] + v[i];
//     }

//     ll ans = 0;
//     int lsel = -1;
//     int turn = 1;
//     while(true) {
//         ll max = -1;
//         int maxIdx = -1;
//         for(int i = 0; i < N; ++i) {
//             if (i <= lsel) continue;
//             ll cur = pSum[i];
//             if (i != 0) cur -= pSum[i - 1];
//             if (lsel != -1) cur -= pSum[lsel];
//             if (cur > max) {
//                 cur = max;
//                 maxIdx = i;
//             }
//         }
//         printf("max:%lld\n", max);
//         if (max == -1) break;
//         if (turn % 2 == 1) ans += max;
//         lsel = maxIdx;
//         ++turn;
//     }
//     printf("%lld\n", ans);

//     return 0;
// }


