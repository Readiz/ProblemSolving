#include "main.cpp"

#define printd(...) printf(__VA_ARGS__)
#define R register
#define CHK 0b100
#define DES 40000
#define THR (DES / 40 + 500)
struct P {
    int x;
    int y;
    int dep;
};

#define QS 0x3FFFF // 약 26만
struct Q { // Circular Queue
    P d[QS + 1]; // data
    int f, r; // front, rear
    Q() {
        f = 0;
        r = 0;
    }
    void en(P md) {
        d[r++] = md;
        r &= QS;
    }
    P de() {
        P re = d[f++];
        f &= QS;
        return re;
    }
    bool isEmpty() {
        return f == r;
    }
    int size() {
        int s = r - f;
        if (s < 0) s += QS;
        return s;
    }
};

Q q;

// 원칙: 간단한 솔루션부터 확인할 것!
int test(char map[40000][40000]) {
    printd("---IN---\n");
    q.en({0, 0, 1});
    map[0][0] |= CHK;
    int rd = 0;
    while (!q.isEmpty()) {
        P c = q.de(); // current
        int x = c.x;
        int y = c.y;
        int d = c.dep;
        if (x == DES - 1 && y == DES - 1) {
            printd("x: %d, y: %d, EXIT loop! d: %d\n", x, y, d);
            rd = d;
            break;
        }
        int xydiff = x - y;
        if (xydiff < -THR || xydiff > THR) {
            continue;
        }
        int v = map[y][x] & 0b11;
        if (y>=0 && y<DES) {
            if (x+1<DES && (map[y][x+1]&CHK) == 0) {
                int nv = map[y][x+1];
                int diff = nv - v;
                if (diff >= -1 && diff <= 1) {
                    map[y][x+1] |= CHK;
                    q.en({x+1,y,d+1});
                }
            }
            if (x-1>=0 && (map[y][x-1]&CHK) == 0) {
                int nv = map[y][x-1];
                int diff = nv - v;
                if (diff >= -1 && diff <= 1) {
                    map[y][x-1] |= CHK;
                    q.en({x-1,y,d+1});
                }
            }
        }
        if (x>=0 && x<DES) {
            if (y+1<DES && (map[y+1][x]&CHK) == 0) {
                int nv = map[y+1][x];
                int diff = nv - v;
                if (diff >= -1 && diff <= 1) {
                    map[y+1][x] |= CHK;
                    q.en({x,y+1,d+1});
                }
            }
            if (y-1>=0 && (map[y-1][x]&CHK) == 0) {
                int nv = map[y-1][x];
                int diff = nv - v;
                if (diff >= -1 && diff <= 1) {
                    map[y-1][x] |= CHK;
                    q.en({x,y-1,d+1});
                }
            }
        }
    }
    printd("Q f: %d r: %d\n", q.f, q.r);
    printd("D: %d\n", rd);
    printd("---OUT---\n");
    return rd;
}