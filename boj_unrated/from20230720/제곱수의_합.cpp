#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N; scanf("%d", &N);

    int dp[100001];

    for(int i = 0; i <= N; ++i) dp[i] = i;
    for(int i = 0; i <= N; ++i) {
        for(int j = 2; j * j <= N; ++j) {
            int s = j * j;
            if (i + s <= N) {
                if (dp[i + s] > dp[i] + 1) {
                    dp[i + s] = dp[i] + 1;
                }
            } else {
                break;
            }
        }
    }
    printf("%d\n", dp[N]);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef unsigned long long ull;

// int main() {
//     int N; scanf("%d", &N);

//     vector<int> v; v.resize(N + 1);
//     fill(v.begin(), v.end(), 100000);
//     vector<int> squares;
//     vector<int> tmp; tmp.resize(N + 1);
//     set<int> S;
//     for(int i = 1; i <= N; ++i) S.insert(i);
//     for(int i = 1; i * i <= N; ++i) {
//         v[i*i] = 1;
//         squares.push_back(i*i);
//         S.erase(i*i);
//     }
//     while(S.size() > 0) {
//         for(int i = 1; i <= N; ++i) {
//             for(auto& s: squares) {
//                 if (i + s <= N) {
//                     if (v[i + s] > v[i] + 1) {
//                         v[i + s] = v[i] + 1;
//                         S.erase(i + s);
//                     }
//                 } else {
//                     break;
//                 }
//             }
//         }
//     }
//     printf("%d\n", v[N]);

//     return 0;
// }