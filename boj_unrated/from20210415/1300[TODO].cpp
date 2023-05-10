#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
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
ull N, k;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%llu %llu", &N, &k);
    printd("N: %llu", N);
    printd("k: %llu", k);

    // 아래 솔루션은 N이 너무 커서 N^2의 솔루션이라 시간초과가 난다.
    // vector<ull> v;
    // for (ull i = 1ULL; i <= N; i++) {
    //     for (ull j = 1ULL; j <= N; j++) {
    //         v.push_back(i * j);
    //     }
    // }
    // sort(v.begin(), v.end());
    // int idx = 1;
    // for (ull e: v) {
    //     printd("[%2d] %llu", idx++, e);
    // }
    // printf("%llu\n", v[k - 1]);
    
    // 각 줄별로 구하는 솔루션.. 각 row는 이분탐색으로 구하면 log k 만큼의 시간에 몇개 있는지 구할 수 있다.
    // 줄은 n개가 있으므로 총 시간복잡도는 O(n * log k) 이다.
    ull ans = 0ULL; // k 보다 작은 수들의 개수
    for (R ull i = 1ULL; i <= N; i++) {
        ull p = N / 2;
        ull step = N / 2;
        if (p * i < k )
    }

MAIN_END


/*문제
세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. B를 오름차순 정렬했을 때, B[k]를 구해보자.

배열 A와 B의 인덱스는 1부터 시작한다.

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 105보다 작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(109, N2)보다 작거나 같은 자연수이다.
*/
