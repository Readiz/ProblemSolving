#include <stdio.h>

typedef __int128 lll;
namespace fio {
    const int BSIZE = 524288;
    char buffer[BSIZE];
    int p = BSIZE;
    inline char readChar() {
        if(p == BSIZE) {
            fread(buffer, 1, BSIZE, stdin);
            p = 0;
        }
        return buffer[p++];
    }
    long long readInt() {
        char c = readChar();
        while ((c < '0' || c > '9') && c != '-') {
            c = readChar();
        }
        long long ret = 0; bool neg = c == '-';
        if (neg) c = readChar();
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return neg ? -ret : ret;
    }
}

int main() {
    for (int tc = 0; tc < 3; tc++) {
        int N = fio::readInt();
        lll sum = 0;
        for (int i = 0; i < N; i++) {
            long long tmp = fio::readInt();
            sum += tmp;
        }
        if (sum == 0) printf("0\n");
        if (sum > 0) printf("+\n");
        if (sum < 0) printf("-\n");
    }
}


/*
부호 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	2729	759	639	35.149%
문제
N개의 정수가 주어지면, 이 정수들의 합 S의 부호를 구하는 프로그램을 작성하시오.

입력
총 3개의 테스트 셋이 주어진다. 각 테스트 셋의 첫째 줄에는 N(1≤N≤100,000)이 주어지고, 둘째 줄부터 N개의 줄에 걸쳐 각 정수가 주어진다. 주어지는 정수의 절댓값은 9223372036854775807보다 작거나 같다.

출력
총 3개의 줄에 걸쳐 각 테스트 셋에 대해 N개의 정수들의 합 S의 부호를 출력한다. S=0이면 "0"을, S>0이면 "+"를, S<0이면 "-"를 출력하면 된다.

예제 입력 1 
3
0
0
0
10
1
2
4
8
16
32
64
128
256
-512
6
9223372036854775807
9223372036854775806
9223372036854775805
-9223372036854775807
-9223372036854775806
-9223372036854775804
예제 출력 1 
0
-
+
*/
