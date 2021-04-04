#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("B_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

char A[300001], B[300001];
int Acount[300001][2];
int len;

int compare(char a[], char b[], int len) {
    for (int i = len; i >= 0; i--) {
        if (a[i] != b[i]) return i;
    }
    return -1; // -1이면 같은 것
}

// bool checkSameOneZero(int p) {
//     int count0 = 0, count1 = 0;
//     for (int i = 0; i <= p; i++) {
//         if (A[i] == '0') count0++;
//         else count1++;
//     }
//     if (count0 == count1) return true;
//     return false;
// }

void swap(int p) {
    for (int i = 0; i <= p; i++) {
        if (A[i] == '0') A[i] = '1';
        else A[i] = '0';
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        scanf("%d", &len);
        scanf("%s", A);
        scanf("%s", B);

        // A의 전처리
        int count0 = 0, count1 = 0;
        for (int i = 0; i <= len; i++) {
            if (A[i] == '0') count0++;
            else count1++;
            Acount[i][0] = count0;
            Acount[i][1] = count1;
        }

        bool canMakeSame = false;
        int p = len;
        while (true) {
            p = compare(A, B, p);
            if (p == -1) {
                printd("A and B are same.");
                canMakeSame = true;
                break;
            }
            printd("A and B are differnt at %d", p);
            if (Acount[p][0] == Acount[p][1]) {
                swap(p);
                printd("swapped: %s", A);
                continue;
            }
            break;
        }
        if (canMakeSame) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
MAIN_END
