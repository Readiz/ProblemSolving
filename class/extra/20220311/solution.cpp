#include "main.cpp"

#define printd(...) printf(__VA_ARGS__)
#define getz(x,y) (unsigned int)(((x)<<16)|(y))
#define getx(z) ((unsigned int)(z)>>16)
#define gety(z) ((unsigned int)(z)&0xFFFF)
#define R register
#define CHK 0b100
#define DES 40000
#define THR (DES / 40 + 1000)

typedef unsigned int P;
#define QS 0x3FFF // 약 1.6만
struct CQ { // Circular Queue
    P d[QS + 1]; // data
    int f, r; // front, rear
    CQ() {
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
CQ q;


int test(char map[40000][40000]) {
    register int x, y, v, d;
    register unsigned int xy;

    q.en(getz(0,0));
    map[0][0] |= CHK;

    int dist = 0;
    bool hasPath = false;
    while (!q.isEmpty()) {
        dist++;
        int phaseRear = q.r;
        while (q.f != phaseRear) {
            xy = q.de();
            if (xy == getz(39999, 39999)) {
                hasPath = true;
                break;
            }

            x = getx(xy);
            y = gety(xy);
            d = x - y;
            if (d < -THR || d > THR) {
                continue;
            }

            v = map[y][x] & 0b11;
            if (x<DES-1 && !(map[y][x+1]&CHK)) {
                d = map[y][x+1] - v;
                if (d >= -1 && d <= 1) {
                    map[y][x+1] |= CHK;
                    q.en(getz(x+1,y));
                }
            }
            if (x>=1 && !(map[y][x-1]&CHK)) {
                d = map[y][x-1] - v;
                if (d >= -1 && d <= 1) {
                    map[y][x-1] |= CHK;
                    q.en(getz(x-1,y));
                }
            }
            if (y<DES-1 && !(map[y+1][x]&CHK)) {
                d = map[y+1][x] - v;
                if (d >= -1 && d <= 1) {
                    map[y+1][x] |= CHK;
                    q.en(getz(x,y+1));
                }
            }
            if (y>=1 && !(map[y-1][x]&CHK)) {
                d = map[y-1][x] - v;
                if (d >= -1 && d <= 1) {
                    map[y-1][x] |= CHK;
                    q.en(getz(x,y-1));
                }
            }
        }
        if (hasPath) {
            break;
        }
    }
    if (!hasPath) dist = 0;
    return dist;
}

#define QSV 0x3FFFF // 약 26만
struct CQV { // Circular Queue for Verification
    P d[QSV + 1]; // data
    int f, r; // front, rear
    CQV() {
        f = 0;
        r = 0;
    }
    void en(P md) {
        d[r++] = md;
        r &= QSV;
    }
    P de() {
        P re = d[f++];
        f &= QSV;
        return re;
    }
    bool isEmpty() {
        return f == r;
    }
    int size() {
        int s = r - f;
        if (s < 0) s += QSV;
        return s;
    }
};
CQV vq;

int test_verify(char map[40000][40000]) {
    register int x, y, v, d;
    register unsigned int xy;

    vq.en(getz(0,0));
    map[0][0] |= CHK;

    int dist = 0;
    bool hasPath = false;
    while (!vq.isEmpty()) {
        dist++;
        int phaseRear = vq.r;
        while (vq.f != phaseRear) {
            xy = vq.de();
            if (xy == getz(39999, 39999)) {
                hasPath = true;
                break;
            }

            x = getx(xy);
            y = gety(xy);

            v = map[y][x] & 0b11;
            if (x<DES-1 && !(map[y][x+1]&CHK)) {
                d = map[y][x+1] - v;
                if (d >= -1 && d <= 1) {
                    map[y][x+1] |= CHK;
                    vq.en(getz(x+1,y));
                }
            }
            if (x>=1 && !(map[y][x-1]&CHK)) {
                d = map[y][x-1] - v;
                if (d >= -1 && d <= 1) {
                    map[y][x-1] |= CHK;
                    vq.en(getz(x-1,y));
                }
            }
            if (y<DES-1 && !(map[y+1][x]&CHK)) {
                d = map[y+1][x] - v;
                if (d >= -1 && d <= 1) {
                    map[y+1][x] |= CHK;
                    vq.en(getz(x,y+1));
                }
            }
            if (y>=1 && !(map[y-1][x]&CHK)) {
                d = map[y-1][x] - v;
                if (d >= -1 && d <= 1) {
                    map[y-1][x] |= CHK;
                    vq.en(getz(x,y-1));
                }
            }
        }
        if (hasPath) {
            break;
        }
    }
    if (!hasPath) dist = 0;
    return dist;
}