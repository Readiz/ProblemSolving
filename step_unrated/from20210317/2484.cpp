#include <stdio.h>
#ifndef BOJ
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif


MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N;
    scanf("%d", &N);
    printd("Input - N: %d", N);
    printd("--------------------------");
    int maxSum = -1;
    for (int i = 0; i < N; i++) {
        int count[7] = {0, };
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int tmp;
            scanf("%d", &tmp);
            count[tmp]++;
        }
        int count4 = 0, count3 = 0, count2 = 0, count1 = 0;
        int idx4, idx3, idx2_1 = -1, idx2_2 = -1, idx1;
        for (int i = 1; i <= 6; i++) {
            if (count[i] == 4) {
                count4++;
                idx4 = i;
            }
            if (count[i] == 3) {
                count3++;
                idx3 = i;
            }
            if (count[i] == 2) {
                count2++;
                if (idx2_1 == -1) {
                    idx2_1 = i;
                } else {
                    idx2_2 = i;
                }
            }
            if (count[i] == 1) {
                count1++;
                idx1 = i;
            }
        }
        if (count4 == 1) {
            sum += 50000 + idx4 * 5000;
        } else if (count3 == 1) {
            sum += 10000 + idx3 * 1000;
        } else if (count2 == 2) {
            sum += 2000 + idx2_1 * 500 + idx2_2 * 500;
        } else if (count2 == 1) {
            printd("Case 4 / idx2: %d", idx2_1);
            sum += 1000 + idx2_1 * 100;
        } else {
            sum += idx1 * 100;
        }
        printd("Current Sum: %d", sum);
        if (sum > maxSum) {
            maxSum = sum;
        }
        
    }
    printf("%d\n", maxSum);
    return 0;
MAIN_END


/*
주사위 네개 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	128 MB	3422	1405	1202	42.414%
문제
1에서부터 6까지의 눈을 가진 4개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다. 

같은 눈이 4개가 나오면 50,000원+(같은 눈)*5,000원의 상금을 받게 된다. 
같은 눈이 3개만 나오면 10,000원+(3개가 나온 눈)*1,000원의 상금을 받게 된다. 
같은 눈이 2개씩 두 쌍이 나오는 경우에는 2,000원+(2개가 나온 눈)*500원+(또 다른 2개가 나온 눈)*500원의 상금을 받게 된다.
같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)*100원의 상금을 받게 된다. 
모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)*100원의 상금을 받게 된다.  
예를 들어, 4개의 눈이 3, 3, 3, 3으로 주어지면 50,000+3*5,000으로 계산되어 65,000원의 상금을 받게 된다. 4개의 눈이 3, 3, 6, 3으로 주어지면 상금은 10,000+3*1,000으로 계산되어 13,000원을 받게 된다. 또 4개의 눈이 2, 2, 6, 6으로 주어지면 2,000+2*500+6*500으로 계산되어 6,000원을 받게 된다. 4개의 눈이 6, 2, 1, 6으로 주어지면 1,000+6*100으로 계산되어 1,600원을 받게 된다. 4개의 눈이 6, 2, 1, 5로 주어지면 그 중 가장 큰 값이 6이므로 6*100으로 계산되어 600원을 상금으로 받게 된다.

N(1≤N≤1,000)명이 주사위 게임에 참여하였을 때, 가장 많은 상금을 받은 사람의 상금을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 참여하는 사람 수 N이 주어지고 그 다음 줄부터 N개의 줄에 사람들이 주사위를 던진 4개의 눈이 빈칸을 사이에 두고 각각 주어진다.

출력
첫째 줄에 가장 많은 상금을 받은 사람의 상금을 출력한다.

예제 입력 1 
4
3 3 3 3
3 3 6 3
2 2 6 6
6 2 1 5
예제 출력 1 
65000
*/
