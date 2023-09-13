#include <bits/stdc++.h>
using namespace std;

void solve() {
    int rank; scanf("%d", &rank);
    if (rank > 4500) printf("Round 1\n");
    else if (rank > 1000) printf("Round 2\n");
    else if (rank > 25) printf("Round 3\n");
    else printf("World Finals\n");
}
int main() {
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; ++tc) {
        printf("Case #%d: ", tc); solve();
    }

    return 0;
}