#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

ll N, X, Y;
void solve() {
    scanf("%lld %lld %lld", &N, &X, &Y);
    vector<ll> dx, dy;
    for(int i = 0; i < N; ++i) {
        ll tmp; scanf("%lld", &tmp);
        if (i % 2 == 0) {
            dy.push_back(tmp);
        } else {
            dx.push_back(tmp);
        }
    }
    int dxsz1 = dx.size() / 2;
    int dysz1 = dy.size() / 2;
    int dxsz2 = dx.size() - dxsz1;
    int dysz2 = dy.size() - dysz1;

    // 1. 원점에서 출발하기
    map<ll, int> px, py;
    int end = 1 << dxsz1;
    for(int cur = 0; cur < end; ++cur) { // 선택된 좌표들
        ll cx = 0;
        for(int i = 0, p = 1; i < dxsz1; ++i, p <<= 1) {
            if (cur & p) {
                cx += dx[i];
            } else {
                cx -= dx[i];
            }
        }
        px.insert({cx, cur});
    }
    end = 1 << dysz1;
    for(int cur = 0; cur < end; ++cur) { // 선택된 좌표들
        ll cy = 0;
        for(int i = 0, p = 1; i < dysz1; ++i, p <<= 1) {
            if (cur & p) {
                cy += dy[i];
            } else {
                cy -= dy[i];
            }
        }
        py.insert({cy, cur});
    }

    // 2. 뒤에서 출발하기
    end = 1 << dxsz2;
    bool xflag = false;
    int x1, x2;
    for(int cur = 0; cur < end; ++cur) { // 선택된 좌표들
        ll cx = X;
        for(int i = 0, p = 1; i < dxsz2; ++i, p <<= 1) {
            if (cur & p) {
                cx -= dx[dxsz1 + i];
            } else {
                cx += dx[dxsz1 + i];
            }
        }
        if (px.find(cx) != px.end()) {
            xflag = true;
            x1 = px[cx];
            x2 = cur;
            break;
        }
    }

    end = 1 << dysz2;
    bool yflag = false;
    int y1, y2;
    for(int cur = 0; cur < end; ++cur) { // 선택된 좌표들
        ll cy = Y;
        for(int i = 0, p = 1; i < dysz2; ++i, p <<= 1) {
            if (cur & p) {
                cy -= dy[dysz1 + i];
            } else {
                cy += dy[dysz1 + i];
            }
        }
        if (py.find(cy) != py.end()) {
            yflag = true;
            y1 = py[cy];
            y2 = cur;
            break;
        }
    }
    if (xflag && yflag) {
        printf("Yes\n");
        // x1: 2진수, dxsz1
        // x2: 2진수, dxsz2, 거꾸로
        vector<int> x, y;
        for(int i = 0, p = 1; i < dxsz1; ++i, p <<= 1) {
            if (p & x1) x.push_back(1);
            else x.push_back(-1);
        }
        for(int i = 0, p = 1; i < dysz1; ++i, p <<= 1) {
            if (p & y1) y.push_back(1);
            else y.push_back(-1);
        }
        for(int i = 0, p = 1; i < dxsz2; ++i, p <<= 1) {
            if (p & x2) x.push_back(1);
            else x.push_back(-1);
        }
        for(int i = 0, p = 1; i < dysz2; ++i, p <<= 1) {
            if (p & y2) y.push_back(1);
            else y.push_back(-1);
        }

        _D("X: ");
        for(auto& item: x) _D("%d ", item);
        _D("\n");
        _D("Y: ");
        for(auto& item: y) _D("%d ", item);
        _D("\n");

        int last = 1;
        string ans = "";
        bool isY = true;
        int cy = 0, cx = 0;
        for(int i = 0; i < N; ++i) {
            if (isY) {
                // y
                if (last > 0 && y[cy] > 0) { ans += "L"; last = 1; }
                else if (last > 0 && y[cy] < 0) { ans += "R"; last = -1; }
                else if (last < 0 && y[cy] > 0) { ans += "R"; last = 1; }
                else if (last < 0 && y[cy] < 0) { ans += "L"; last = -1; }
                ++cy;
                isY = false;
            } else {
                // x
                if (last > 0 && x[cx] > 0) { ans += "R"; last = 1; }
                else if (last > 0 && x[cx] < 0) { ans += "L"; last = -1; }
                else if (last < 0 && x[cx] > 0) { ans += "L"; last = 1; }
                else if (last < 0 && x[cx] < 0) { ans += "R"; last = -1; }
                ++cx;
                isY = true;
            }
        }
        printf("%s\n", ans.c_str());
    } else {
        printf("No\n");
    }
}

int main() {
    solve();
    return 0;
}