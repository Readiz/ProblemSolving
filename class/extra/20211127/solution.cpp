#include "main.cpp"
#define printd(...) printf(__VA_ARGS__)
#define R register
#define MAP_MAX 10000

// ushort를 생각해서, 맨 앞자리를 signal로 사용한다.
// ushort: 0x0000 ~ 0xFFFF
#define XFLAG 0x8000
#define YADDFLAG 0x4000
#define ENDFLAG 0xFFFF

void encode(char map[10000][10000], char data[150000]) {
    unsigned short* sdata = (unsigned short*) &data[0]; // sdata: 75000 까지 사용가능
    bool init = false;
    int lasty;

    for (register int y = 0; y < MAP_MAX; y++) {
        for (register int x = 0; x < MAP_MAX; x++) {
            if (map[y][x] != 1) continue;
            // 시작 줄이 0이 아닐수도 있을 것에 대비한 코드..
            if (!init) {
                init = true;
                *(sdata++) = y;
                lasty = y;
            }
            if (y - lasty >= 1) {
                *(sdata++) = (YADDFLAG | (y - lasty));
                // printd("MOVE LINE CASE at %d, for OFFSET: %d\n", y, y - lasty);
            }
            lasty = y;

            *(sdata++) = (XFLAG | x);
            register int dx = x;
            for (; dx < MAP_MAX && map[y][dx] != 0; dx++);
            *(sdata++) = dx;
            // printd("LINE: %d ~ %d[LEN: %d] (y: %d)\n", x, dx, dx - x, y);

            register int dy = y;
            for (; dy < MAP_MAX && map[dy][x] != 0; dy++);
            if (dy - y > 1) { // 임계값 2로 설정 (실 데이터 보면 2 미만 굉장히 많음)
                dy = y;
                for (; dy < MAP_MAX && map[dy][x] != 0; dy++)
                    map[dy][x] = 2;
                *(sdata++) = y + 1;
                *(sdata++) = dy;
                // printd("LINE: %d ~ %d[LEN: %d] (x: %d)\n", y, dy, dy - y, x);
            }
            x = dx;
        }
    }
    *sdata = ENDFLAG;
    printd("SHORT CMD SIZE: %d\n", sdata - ((unsigned short*) &data[0]));
}

void decode(char map[10000][10000], char data[150000]) {
    unsigned short* sdata = (unsigned short*) &data[0]; // sdata: 75000 까지 사용가능
    register int y = *(sdata++); // 시작 y 줄

    int xdecoded = 0;
    int ydecoded = 0;

    while (*sdata != ENDFLAG) {
        if (*sdata & YADDFLAG) { // check offset
            unsigned short offset = *(sdata++) & 0x3FFF;
            y += offset;
        }
        if (*sdata & XFLAG) { // x line case
            unsigned short xstart = *(sdata++) & 0x7FFF;
            unsigned short xend = *(sdata++);
            for (register int dx = xstart; dx < xend; dx++) {
                map[y][dx] = 1;
            }
            xdecoded++;
            // printd("LINE: %d ~ %d[LEN: %d] (y: %d)\n", xstart, xend, xend - xstart, y);
            if (!(*sdata & XFLAG) && !(*sdata & YADDFLAG)) { // y line case
                unsigned short ystart = *(sdata++);
                unsigned short yend = *(sdata++);
                for (register int dy = ystart; dy < yend; dy++) {
                    map[dy][xstart] = 1;
                }
                ydecoded++;
                // printd("LINE: %d ~ %d[LEN: %d] (x: %d)\n", ystart, yend, yend- ystart, xstart);
            }
        }
    }
    printd("DECODE COUNT X: %d / Y: %d\n", xdecoded, ydecoded);
    printd("SHORT CMD SIZE: %d\n", sdata - ((unsigned short*) &data[0]));
}