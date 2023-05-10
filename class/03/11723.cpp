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
        printf("[DEBUG] No Online Judge detected!\n", fname);
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int strlen(char s[]) {
    int p;
    for (p = 0; s[p] != 0; p++);
    return p;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int M;
    scanf("%d", &M);
    printd("--------------------------");
    int db[21] = {0, };
    for (int i = 0; i < M; i++) {
        char cmd[10] = {0, };
        int val;
        scanf("%s", cmd);
        switch (cmd[0])
        {
        case 'a':
            if (cmd[1] == 'd') {
                scanf("%d", &val);
                db[val] = 1;
            } else if (cmd[1] == 'l') {
                for (int i = 1; i <= 20; i++) {
                    db[i] = 1;
                }
            }
            break;
        case 'c':
            scanf("%d", &val);
            if (db[val]) printf("%d\n", 1);
            else printf("%d\n", 0);
            break;
        case 't':
            scanf("%d", &val);
            if (db[val]) db[val] = 0;
            else db[val] = 1;
            break;
        case 'r':
            scanf("%d", &val);
            db[val] = 0;
            break;
        case 'e':
            for (int i = 1; i <= 20; i++) {
                db[i] = 0;
            }
            break;
        }
    }
    return 0;
MAIN_END

/*
집합 실패분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1.5 초	4 MB (하단 참고)	29837	9173	6414	30.158%
문제
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다. 
입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.
*/
