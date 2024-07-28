#include <bits/stdc++.h>
using namespace std;


char buf[100010];
void solve() {
    int N; scanf("%d", &N);
    scanf("%c", &buf[0]);
    vector<pair<string, string>> v;
    for(int i=0;i<N;++i) {
        scanf("%[^\n]", buf);
        string ori = buf;
        string upper = ori;
        for(auto& c: upper) {
            if (c >= 'a' && c <= 'z')
                c = c - 'a' + 'A';
        }
        v.push_back({ori, upper});
        scanf("%c", &buf[0]);
    }

    // for(auto& i: v) {
    //     printf("%s\n", i.first.c_str());
    // }
    // return;
    // scanf("%c", &buf[0]);
    char t[100010]; scanf("%s", t);
    int tlen;
    for(int i = 0; i < 100000; ++i) {
        auto& c = t[i];
        if (c == 0) {
            tlen = i;
            break;
        }
        if (c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';
    }
    for(auto& s: v) {
        string& ori = s.first;
        string& upper = s.second;

        int pos = 0;
        for(auto& c: upper) {
            if (c == t[pos]) ++pos;
        }
        // printf("checking %s vs %s / %d\n", upper.c_str(), t, pos);

        if(pos != tlen) continue;

        printf("%s\n", ori.c_str());
    }
    printf("\n");
}

int main() {
    int TC; scanf("%d", &TC);

    for(int i = 1; i <= TC; ++i) {
        printf("Data Set %d:\n", i);
        solve();
    }

    return 0;
}