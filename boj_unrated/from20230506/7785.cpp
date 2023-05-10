#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; scanf("%d", &N);
    unordered_set<string> S;
    for(int i = 0; i < N; ++i) {
        string a, b;
        cin >> a >> b;
        if (b == "enter") {
            S.insert(a);
        } else {
            if (S.find(a) != S.end()) {
                S.erase(a);
            }
        }
    }
    vector<string> v;
    for(auto& item: S) {
        v.push_back(item);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for(auto& item: v) {
        cout << item << '\n';
    }

    return 0;
}