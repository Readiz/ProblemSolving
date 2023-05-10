#include <stdio.h>
#include <set>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
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
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define R register
typedef unsigned long long ull;
typedef long long ll;
// Refer to https://casterian.net/archives/396
ull checker[] = {2ULL, 7ULL, 61ULL};
ull N;

ull addmod(ull x, ull y, ull m) {
    if (x >= m - y) {
        return x - (m - y);
    } else {
        return x + y;
    }
}
ull mulmod(ull x, ull y, ull m) {
    ull r = 0ULL;
    while (y > 0) {
        if (y % 2 == 1)
            r = addmod(r, x, m);
        x = addmod(x, x, m);
        y /= 2;
    }
    return r;
}

// 빠른 거듭제곱.. (2^N) 을 반복해서 곱하는 방식.
ull powmod(ull x, ull y, ull m) {
    ull r = 1ULL;
    // 이진수 연산한다고 생각.. 2^n 꼴은 자리수 올리고.. 아닌 경우 더하고..
    while (y > 0) {
        if (y % 2 == 1) {
            r = mulmod(r, x, m);
        }
        x = mulmod(x, x, m);
        y /= 2;
    }
    return r;
}

// Miller-Rabin checker
// true를 리턴한다고 해서 무조건 소수인 것은 아님. (확률적 소수)
// 그러나 특정 수들에 대해 (checker 배열) 모두 검사한다면, 확정적으로 소수임을 판별가능.
// (log n)^3 알고리즘
bool MR(ull N, ull A) {
    ull d = N - 1;
    while (d % 2 == 0) {
        if (powmod(A, d, N) == N - 1) {
            return true;
        }
        d /= 2;
    }

    ull tmp = powmod(A, d, N);
    if (tmp == N - 1 || tmp == 1) { // a^(d*2^r) mod n = -1 판정 하는 부분임
        return true;
    } else {
        return false;
    }
}

bool isPrime(ull N) {
    if (N <= 1) {
        return false;
    } else if (N == 2) {
        return true;
    } else if (N <= 10000ULL) { // 기존 방법이 빠른 구간 + 밀러라빈 checker 수보다 작은 구간
        if ((N & 1ULL) == 0ULL) {
            return false; // 짝수면, 소수 아님
        }
        for (ull i = 3ULL; i * i <= N; i += 2) { // 홀수만 검사한다.
            if (N % i == 0ULL) return false; // 나누어 떨어지면, 소수 아님
        }
        return true;
    } else {
        for (int i = 0; i < 3; i++) { // 3: checker size
            ull A = checker[i];
            if (MR(N, A) == false) {
                return false;
            }
        }
        return true;
    }
}

int getThird(set<int>& list) {
    int idx = 1;
    for (auto itr = list.rbegin(); itr != list.rend(); itr++) {
        if (idx == 3) {
            return *itr;
        }
        idx++;
    }
    return 1000;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int N;
    scanf("%d", &N);
    printd("Overall Round: %d", N);
    ll scoreA = 0LL, scoreB = 0LL;
    set<int> listA, listB, listOverall;
    int idx = 1;
    for (R int i = 0; i < N; i++) {
        int A, B;
        scanf("%d %d", &A, &B); // A: 대웅, B: 규성
        printd("Round #%d: A - %d / B - %d", i + 1, A, B);
        // 게임은 대웅부터 시작한다.
        if (listOverall.find(A) == listOverall.end()) { // A는 여태까지 나오지 않은 소수여야 함.
            if (isPrime(A)) {
                listOverall.insert(A);
                listA.insert(A);
            } else {
                // 상대방 소수 세번째 수만큼 점수 얻는다.
                printd("%d is not prime! Add score to B...", A);
                scoreB += getThird(listB);
            }
        } else { // 이미 나온 소수면, 패널티.
            printd("%d is already decleared! Subtract score from A...", A);
            scoreA -= 1000LL;
        }
        // 규성이 차례~
        if (listOverall.find(B) == listOverall.end()) { // A는 여태까지 나오지 않은 소수여야 함.
            if (isPrime(B)) {
                listOverall.insert(B);
                listB.insert(B);
            } else {
                // 상대방 소수 세번째 수만큼 점수 얻는다.
                printd("%d is not prime! Add score to A...", B);
                scoreA += getThird(listA);
            }
        } else { // 이미 나온 소수면, 패널티.
            printd("%d is already decleared! Subtract score from B...", B);
            scoreB -= 1000LL;
        }
        printd("currentScore: A - %lld / B - %d", scoreA, scoreB);
    }
    if (scoreA > scoreB) {
        printf("소수의 신 갓대웅\n");
    } else if (scoreA == scoreB) {
        printf("우열을 가릴 수 없음\n");
    } else {
        printf("소수 마스터 갓규성\n");
    }
MAIN_END
