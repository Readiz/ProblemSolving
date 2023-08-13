#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y, i;
};
void solve() {
    int N; scanf("%d", &N);
    vector<Point> v;
    int miny = 999999; int minx = 999999;
    int minIdx;
    for(int i = 0; i < N; ++i) {
        int x, y; scanf("%d %d", &x, &y);
        v.push_back({x, y, i});
        if (y < miny) {
            miny = y;
            minx = x;
            minIdx = i;
        } else if (y == miny) {
            if (x < minx) {
                minx = x;
                minIdx = i;
            }
        }
    }
    Point tmp = v[minIdx];
    v[minIdx] = v[0];
    v[0] = tmp;

    sort(v.begin() + 1, v.end(), [&](Point& a, Point& b) {
        int ax = a.x - v[0].x, ay = a.y - v[0].y;
        int bx = b.x - v[0].x, by = b.y - v[0].y;
        int crossproduct = ax * by - ay * bx;
        if (crossproduct != 0) return crossproduct > 0;


        int adist = ax * ax + ay * ay;
        int bdist = bx * bx + by * by;
        return adist < bdist;
    });

    // 마지막 벡터만 뒤집는다.
    int vlastx = v[N - 1].x - v[0].x;
    int vlasty = v[N - 1].y - v[0].y;
    int i;
    for(i = N - 2; i >= 0; --i) {
        int vx = v[i].x - v[0].x;
        int vy = v[i].y - v[0].y;
        if (vlastx * vy - vlasty * vx == 0) continue; // 마지막 벡터랑 각도가 같으면 계속 반복
        break;
    }
    ++i;
    reverse(v.begin() + i, v.end());


    for(auto& item: v) {
        printf("%d ", item.i);
    }
    printf("\n");
}
int main() {
    int TC; scanf("%d", &TC);
    while(TC--) {
        solve();
    }
    return 0;
}