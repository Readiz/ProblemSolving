#include <stdio.h>

#define INT_MAX 2147483647
#define MAX_INPUT_NUM 100000
bool hashMap[MAX_INPUT_NUM * 100] = {false, };
int hashVal[MAX_INPUT_NUM * 100] = {0, };

int hash(long long x) {
    x = (x + INT_MAX) * 2654435761;
    int r = (int)(x) % (MAX_INPUT_NUM * 100 - 1); 
    return (r < 0) ? -r : r;
}

int main() {
    bool isZeroSaved = false;
    int N, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        int addr;
        for (addr = hash(tmp); hashMap[addr] == true; addr++);
        hashMap[addr] = true;
        hashVal[addr] = tmp;
        // printf("origin: %d, hash: %d, addr: %d\n", tmp, hash(tmp), addr);
        if (tmp == 0) isZeroSaved = true;
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        int tmp;
        scanf("%d", &tmp);
        if (tmp == 0) {
            // hashVal 기본값이 0 이므로 0만 따로 처리..
            if (isZeroSaved) {
                printf("1\n");
            } else {
                printf("0\n");
            }
            continue;
        }
        int addrInit = hash(tmp);
        int addr;
        for (addr = addrInit; (addr < addrInit + 10) && (hashVal[addr] != tmp); addr++);
        if (addr != addrInit + 10) {
            // printf("Found! addr: %d, value: %d\n", addr, hashVal[addr]);
            printf("1\n");
        } else {
            printf("0\n");
        }
    }
    return 0;
}


/*
문제
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -231 보다 크거나 같고 231보다 작다.

출력
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.

예제 입력 1 
5
4 1 5 2 3
5
1 3 7 9 5
예제 출력 1 
1
1
0
0
1
*/
