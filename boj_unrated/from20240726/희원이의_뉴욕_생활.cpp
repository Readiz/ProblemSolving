#include <stdio.h>
#include <math.h>

struct Point {
    double x, y;

    double operator-(Point& t) {
        double dist2 = (x - t.x) * (x - t.x) + (y - t.y) * (y - t.y);
        return sqrt(dist2);
    }
};

template<typename T>
T abs(T a) {
    return a < 0 ? -a: a;
}

template<typename T>
void zwap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
double min(T a, T b, T c, T d, T e) {
    T min = a < b ? a : b;
    min = min < c ? min : c;
    min = min < d ? min : d;
    min = min < e ? min : e;
    return min;
}

int main() {
    Point a, b;
    double p, q, r;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y, &p, &q, &r);

    Point p1, p2;
    double d0 = abs(a.x - b.x) + abs(a.y - b.y);
    double d1 = 1e10, d2 = 1e10, d3 = 1e10, d4 = 1e10;
    // 4가지 케이스에 대해서 제일 가까운 거리를 측정한다.
    auto f1 = [&] () {
        // x, x
        if (p == 0) return;
        p1 = {a.x, (r - p * a.x) / q};
        p2 = {b.x, (r - p * b.x) / q};
        d1 = (p1 - p2) + (a - p1) + (b - p2);
    };
    auto f2 = [&] () {
        // x, y
        if (p == 0) return;
        if (q == 0) return;
        p1 = {a.x, (r - p * a.x) / q};
        p2 = {(r - q * b.y) / p, b.y};
        d2 = (p1 - p2) + (a - p1) + (b - p2);
    };
    auto f3 = [&] () {
        // y, x
        if (p == 0) return;
        if (q == 0) return;
        p1 = {(r - q * a.y) / p, a.y};
        p2 = {b.x, (r - p * b.x) / q};
        d3 = (p1 - p2) + (a - p1) + (b - p2);
    };
    auto f4 = [&] () {
        // y, y
        if (q == 0) return;
        p1 = {(r - q * a.y) / p, a.y};
        p2 = {(r - q * b.y) / p, b.y};
        d4 = (p1 - p2) + (a - p1) + (b - p2);
    };
    f1(); f2(); f3(); f4();
    printf("%.12lf\n", min(d0, d1, d2, d3, d4));
    return 0;
}