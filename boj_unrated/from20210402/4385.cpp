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
        printf("[DEBUG] No Online Judge detected!\n");
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

int mem[1'000];
int reg[10];
MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    for (int i = 0; i < 1000; i++) {
        mem[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
        reg[i] = 0;
    }

    int p = 0;
    int cmd;
    while (scanf("%d", &cmd) != EOF) {
        mem[p++] = cmd;
    }
    int pc = 0;
    int countExecuted = 0;
    while (true) {
        printd("Executing %d... Command: %d", pc, mem[pc]);
        int inst = mem[pc];
        int type = inst / 100;
        countExecuted++;
        if (inst == 100) {
            break;
        }
        if (type == 2) {
            int d = (inst / 10) % 10;
            int n = inst % 10;
            reg[d] = n;
            reg[d] %= 1000;
            printd("[REG %d]: %d", d, reg[d]);
        } else if (type == 3) {
            int d = (inst / 10) % 10;
            int n = inst % 10;
            reg[d] += n;
            reg[d] %= 1000;
            printd("[REG %d]: %d", d, reg[d]);
        } else if (type == 4) {
            int d = (inst / 10) % 10;
            int n = inst % 10;
            reg[d] *= n;
            reg[d] %= 1000;
            printd("[REG %d]: %d", d, reg[d]);
        } else if (type == 5) {
            int d = (inst / 10) % 10;
            int s = inst % 10;
            reg[d] = reg[s];
            reg[d] %= 1000;
            printd("[REG %d]: %d", d, reg[d]);
        } else if (type == 6) {
            int d = (inst / 10) % 10;
            int s = inst % 10;
            reg[d] += reg[s];
            reg[d] %= 1000;
            printd("[REG %d]: %d", d, reg[d]);
        } else if (type == 7) {
            int d = (inst / 10) % 10;
            int s = inst % 10;
            reg[d] *= reg[s];
            reg[d] %= 1000;
            printd("[REG %d]: %d", d, reg[d]);
        } else if (type == 8) {
            int d = (inst / 10) % 10;
            int a = inst % 10;
            reg[d] = mem[reg[a]];
            reg[d] %= 1000;
            printd("[REG %d]: %d", d, reg[d]);
        } else if (type == 9) {
            int s = (inst / 10) % 10;
            int a = inst % 10;
            mem[reg[a]] = reg[s];
            printd("[MEM %d]: %d", mem[reg[a]], reg[s]);
        } else if (type == 0) {
            int d = (inst / 10) % 10;
            int s = inst % 10;
            if (reg[s] != 0) {
                printd("[JMP] jump to #%d", pc);
                pc = reg[d];
                continue;
            }
        }
        pc++;
        pc %= 1000;
    }

    printf("%d\n", countExecuted);

MAIN_END

/*
Interpreter 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	56	18	14	36.842%
문제
A certain computer has 10 registers and 1000 words of RAM. Each register or RAM location holds a 3-digit integer between 0 and 999. Instructions are encoded as 3-digit integers and stored in RAM. The encodings are as follows:

100 means halt
2dn means set register d to n (between 0 and 9)
3dn means add n to register d
4dn means multiply register d by n
5ds means set register d to the value of register s
6ds means add the value of register s to register d
7ds means multiply register d by the value of register s
8da means set register d to the value in RAM whose address is in register a
9sa means set the value in RAM whose address is in register a to the value of register s
0ds means goto the location in register d unless register s contains 0
All registers initially contain 000. The initial content of the RAM is read from standard input. The first instruction to be executed is at RAM address 0. All results are reduced modulo 1000.

입력
The input to your program consists of up to 1000 3-digit unsigned integers, representing the contents of consecutive RAM locations starting at 0. Unspecified RAM locations are initialized to 000.

출력
The output from your program is a single integer: the number of instructions executed up to and including the halt instruction. You may assume that the program does halt.

You may assume that the program halts in at most 100,000 instructions.

예제 입력 1 
299
492
495
399
492
495
399
283
279
689
078
100
000
000
000
예제 출력 1 
16

*/