#include <stdio.h>

int p1 = 2;
int p2 = 27;
int p3 = 151;

#define MAXHASHSIZE 1000000

char hash1[MAXHASHSIZE]; // 1 byte * 백만 = 1백만 byte
char hash2[MAXHASHSIZE]; // 1 byte * 백만 = 1백만 byte
char hash3[MAXHASHSIZE]; // 1 byte * 백만 = 1백만 byte

int N, M;

int gethash(char buf[], int prime) {
    int r = prime;
    int hash = 0;
    for (int p = 0; buf[p] != 0; ++p) {
        hash += (buf[p] - 'a' + 1) * r;
        r *= prime;
        r %= MAXHASHSIZE;
        hash %= MAXHASHSIZE;
    }
    return hash;
}

int main() {
    scanf("%d %d", &N, &M);
    char buf[501];
    
    for (int i = 0; i ^ N; ++i) {
        scanf("%s", buf);
        hash1[gethash(buf, p1)] = 1;
        hash2[gethash(buf, p2)] = 1;
        hash3[gethash(buf, p3)] = 1;
    }
    int matched = 0;
    for (int i = 0; i ^ M; ++i) {
        scanf("%s", buf);
        if (hash1[gethash(buf, p1)] &&
            hash2[gethash(buf, p2)] &&
            hash3[gethash(buf, p3)]) {
            matched++; // 세가지 hash값이 일치하면 존재하는 것으로 본다.
        }
    }
    printf("%d\n", matched);

    return 0;
}