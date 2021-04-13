#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;

int posColor[51] = {0, };

// bool isAllChecked() {
//     for (int i = 1; i <= 50; i++) {
//         if (posColor[i] == 0) return false;
//     }
//     return true;
// }

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) { // i: 순서
        int tmp;
        scanf("%d", &tmp); // input: color;
        if (posColor[tmp] == 0) {
            posColor[tmp] = i;
        }
        // if (isAllChecked()) break; // 모든 색 카드가 위치 정해졌으면 더 돌 필요 없음..
    }
    for (int i = 1; i <= q; i++) {
        int query;
        scanf("%d", &query);
        int curColorPos = posColor[query];
        for (int c = 1; c <= 50; c++) {
            if (posColor[c] < curColorPos) {
                posColor[c]++; // 한칸 뒤로 업데이트..
            }
        }
        posColor[query] = 1; // 맨 앞으로 이동
        printf("%d ", curColorPos);
    }
MAIN_END
