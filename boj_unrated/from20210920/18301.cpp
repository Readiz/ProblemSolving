#include <stdio.h>
#include <bits/stdc++.h>
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

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int n1, n2, n12;
    // ⌊(n1 + 1)(n2 + 1)/(n12 + 1) - 1⌋
    scanf("%d %d %d", &n1, &n2, &n12);
    printf("%d\n", (n1 + 1) * (n2 + 1) / (n12 + 1) - 1);
MAIN_END


/*
Rats 출처다국어
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	1707	1389	1333	82.284%
문제
To celebrate the Lunar New Year of the Rat, Douglas decides to count the number of rats living in his area. It is impossible for him to find all rats, as they tend to be well hidden. However, on the first day of the new year, Douglas manages to capture n1 rats, and marks each of them with an ear tag before releasing them. On the second day of the new year, Douglas captures n2 rats, and observes that n12 of them had been marked during the first day.

Douglas is asking for your help to estimate the total number of rats in his area. Looking up in your statistics textbook, you propose using the Chapman estimator N, given by:

N := ⌊(n1 + 1)(n2 + 1)/(n12 + 1) - 1⌋

where ⌊x⌋ is the floor of a real number x, i.e., the closest integer less than or equal to x.

입력
The input consists of a single line, with three space-separated integers: n1, n2, n12, in that order.

출력
The output should contain a single line with the single integer N.

제한
0 ≤ n1, n2 ≤ 10 000;
0 ≤ n12 ≤ min(n1, n2).
예제 입력 1 
15 18 11
예제 출력 1 
24
*/
