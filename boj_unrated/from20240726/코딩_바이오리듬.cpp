#include <bits/stdc++.h>
using namespace std;

struct Info {
    int priority;
    string str;
    bool operator<(const Info& t) const {
        if (priority != t.priority) return priority > t.priority;
        return str < t.str;
    }
};

int getScore(string a, string b) {
    int aa = 0, bb = 0, cc = 0;
    for(int i=0;i<4;++i) {
        aa += (a[i] - b[i]) * (a[i] - b[i]);
    }
    for(int i=4;i<6;++i) {
        bb += (a[i] - b[i]) * (a[i] - b[i]);
    }
    for(int i=6;i<8;++i) {
        cc += (a[i] - b[i]) * (a[i] - b[i]);
    }
    return aa*bb*cc;
}

char buf[10];
int main() {
    string origin;
    scanf("%s", buf);
    origin = buf;

    int N; scanf("%d", &N);
    vector<Info> v(N);
    for(int i=0;i<N;++i) {
        scanf("%s", buf);
        string cur = buf;
        int score = getScore(origin, buf);
        v[i].priority = score;
        v[i].str = cur;
    }
    sort(v.begin(),v.end());
    printf("%s\n", v[0].str.c_str());
    return 0;
}