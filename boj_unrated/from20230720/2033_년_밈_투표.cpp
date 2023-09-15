#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

set<string> s;
int main() {
    s.insert("Never gonna give you up");
    s.insert("Never gonna let you down");
    s.insert("Never gonna run around and desert you");
    s.insert("Never gonna make you cry");
    s.insert("Never gonna say goodbye");
    s.insert("Never gonna tell a lie and hurt you");
    s.insert("Never gonna stop");
    int N; scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; ++i) {
        string a; getline(cin, a);
        if (s.find(a) == s.end()) {
            printf("Yes\n");
            return 0;
        }
    }
    printf("No\n");
    return 0;
}