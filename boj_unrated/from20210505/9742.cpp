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

char str[11];
int K;
int idx = 1;
int len;
char s[11];
int stackSize;
bool visited[11];

bool DFS(int depth, int charIdx) {
    // printd("DFS(%d, %d) => len: %d...", depth, charIdx, len);
    if (depth == len) {
        // printd("idx: %d...", idx);
        if (idx == K) {
            s[stackSize++] = str[charIdx];
            return true;
        }
        idx++;
        return false;
    }

    for (R int i = 0; i < len; i++) {
        if (!visited[i]) {
            visited[i] = true;
            bool r = DFS(depth + 1, i);
            if (r) {
                s[stackSize++] = str[charIdx];
                return true;
            }
            visited[i] = false;
        }
    }
    return false;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");

    while (scanf("%s %d", str, &K) != EOF) { 
        printd("Getting %s %d...", str, K);
        idx = 1;
        for (len = 0; str[len] != 0; len++);
        for (R int i = 0; i < len; i++) visited[i] = false;
        printf("%s %d = ", str, K);
        bool r = false;
        for (R int i = 0; i < len; i++) {
            stackSize = 0;
            visited[i] = true;
            r = DFS(1, i);
            visited[i] = false;
            if (r) {
                while (--stackSize >= 0) {
                    printf("%c", s[stackSize]);
                }
                break;
            }
        }
        if (!r) printf("No permutation");
        printf("\n");
    }
MAIN_END

/*
순열 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
5 초	128 MB	981	367	283	39.691%
문제
집합의 순열이란 집합의 서로 다른 원소를 모두 사용해 만들 수 있는 순서이다. 예를 들어, {2,3,5}의 순열은 다음과 같다.

2 3 5
2 5 3
3 2 5
3 5 2
5 2 3
5 3 2
각각의 순열은 숫자로 나타낼 수 있다. 위의 순열은 사전순으로 쓰여져 있으며, 등장하는 순서를 이용해 나타낸다. 즉, 3 5 2는 위치 4에 있고, 5 3 2는 마지막 위치인 6에 있다.

{b,e,i,n}으로 만들 수 있는 순열은 다음과 같다.

b e i n
b e n i
b i e n
b i n e
b n e i
b n i e
e b i n
e b n i
e i b n
e i n b
e n b i 
e n i b
i b e n
i b n e
i e b n
i e n b
i n b e
i n e b
n b e i
n b i e
n e b i
n e i b
n i b e
n i e b
서로 다른 숫자와 문자로 이루어진 집합과 위치가 주어졌을 때, 그 집합의 순열 중 주어진 위치의 순열을 구하는 프로그램을 작성하시오.

입력
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스는 한 줄로 이루어져 있다. 첫 번째 문자열은 서로 다른 숫자와 알파벳으로 이루어져 있으며, 길이는 최대 10이다. 또한, 사전순 순서대로 주어진다. 문자열 다음에는 찾아야 하는 위치가 주어지며, 이 값은 3,628,800보다 작거나 같은 자연수이다.

출력
각각의 테스트 케이스마다, 입력으로 주어진 위치에 해당하는 순열을 공백없이 출력한다. 만약, 해당하는 순열이 없는 경우에는 "No permutation"을 출력한다.
*/
