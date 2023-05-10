#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit(char fbasename[]) {
        char fname[100];
        char* ftailname = "_input.txt";
        int p;
        for (p = 0; fbasename[p] != 0; p++) fname[p] = fbasename[p];
        int t;
        for (t = 0; ftailname[t] != 0; t++) fname[p++] = ftailname[t];
        fname[p] = 0;
        printf("[DEBUG] No Online Judge detected!\n");
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
#define MOD 1'000'000'000
template<class T>
T gcd(T a, T b) {
    while (b != 0) {
        T r = a % b;
        a = b;
        b = r;
    }
    return a;
}

class Matrix {
public:
    ull a, b, c, d;
    Matrix() {
        a = d = 1;
        b = c = 0;
    }
    Matrix mul(Matrix x) {
        Matrix r;
        r.a = (this->a * x.a + this->b * x.c) % MOD;
        r.b = (this->a * x.b + this->b * x.d) % MOD;
        r.c = (this->c * x.a + this->d * x.c) % MOD;
        r.d = (this->c * x.b + this->d * x.d) % MOD;
        return r;
    }
};

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        ull N;
        int dummy;
        scanf("%d %llu", &dummy, &N);

        ull fibR;
        Matrix r, fib;
        r.a = r.d = 1; r.b = r.c = 0;
        fib.a = 0; fib.b = fib.c = fib.d = 1;
        while (N) {
            // 홀수일 때만 res 배열에 곱해주고, 짝수일 때는 참고로 삼는 powfib 배열만 계속해서 shift 한다.
            if (N & 1) {
                r = r.mul(fib);
            }
            N >>= 1;
            fib = fib.mul(fib);
        }
        fibR = r.b;

        printf("%d %llu\n", tc, fibR % MOD);
    }
MAIN_END

/*
Immortal Porpoises 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	80	65	59	88.060%
문제
As everyone knows, immortal porpoises live on the other side of straight lines and eat live seagulls, although Federal Law prohibits transporting the gulls to them (but that's another story).

The well-known scientist Leo O. Pisa studied immortal porpoises at great length, and made a number of interesting discoveries. He found, for example, that a single pair of porpoises brings forth a pod of 2 babies every year, and that it takes a full year for the babies to mature and start producing pods of their own. Therefore, if you start with one pair of newborn porpoises, at the end of the 1st year, you would still have one pair of porpoises (now mature and ready to procreate). At the end of the second year, you would have a nice new pod of newborns. But you would also have a pair of mature adults! Next year, they would have a second pod of newborns, but their 1st pod would be ready to start producing pods of their own.

Each year, all the porpoises that were around last year are still there. But in addition, all the porpoises who were around two years earlier have babies! However, to prevent the world from being overrun with immortal porpoises, whenever their numbers reach one billion (109) pairs or more, one billion of the pairs mysteriously disappear. Strangely enough, some years the population disappears completely. When that happens, in the next year a single pair miraculously appears. In fact, for any given year, Y, the number of living porpoise pairs is fib(Y) mod 109, where fib(Y) is the Yth value in the well-known Fibonacci sequence.

Suppose each picture represents the number of pairs alive at the end of the year. Then our yearto-year Porpoise Population chart would look something like this:

Year	Pair Count	Porpoise Pairs Alive
1	1	
2	1	
3	2	
4	3	
5	5	
6	8	
7	13	
8	21	
…	…	…
43	433494437	…
44	701408733	…
45	134903170	…
46	836311903	…
Your job is to write a program that determines the number of immortal porpoise pairs alive at the end of a given number of years, assuming that you start with a newborn pair at the beginning of the 1st year. Since immortal porpoises believe that the universe will exist for exactly 248 = 281,474,976,710,656 years, you need not deal with years later than that.

입력
The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set should be processed identically and independently.

Each data set consists of a single line of input consisting of two space-separated values. The first value is an integer, K, which is the data set number. The next value Y, (1 ≤ Y ≤ 248), is the number of years the porpoises have been alive.

출력
For each data set there is a single line of output. The line consists of the data set number, K, a single space, and the number of immortal porpoise pairs alive at the end of Y years.
*/
