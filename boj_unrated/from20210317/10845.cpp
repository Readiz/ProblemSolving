#include <stdio.h>
#ifndef ONLINE_JUDGE
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

class Queue {
    int startPos = 0;
    int endPos = 0;
    int data[10001];
public:
    int getSize() {
        return endPos - startPos;
    }
    void push(int num) {
        data[endPos++] = num;
    }
    int pop() {
        if (getSize() > 0) {
            return data[startPos++];
        } else {
            return -1;
        }
    }
    int empty() {
        if (getSize() > 0) {
            return 0;
        } else {
            return 1;
        }
    }
    int front() {
        if (getSize() > 0) {
            return data[startPos];
        } else {
            return -1;
        }
    }
    int back() {
        if (getSize() > 0) {
            return data[endPos - 1];
        } else {
            return -1;
        }
    }
};

Queue q;

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N;
    scanf("%d", &N);
    printd("Input - N: %d", N);
    printd("--------------------------");
    for (int i = 0; i < N; i++) {
        char s[10];
        int num;
        scanf("%s", s);
        if (s[0] == 'p' && s[1] == 'u') {
            scanf("%d", &num);
            q.push(num);
        } else if (s[0] == 'f') {
            printf("%d\n", q.front());
        } else if (s[0] == 'b') {
            printf("%d\n", q.back());
        } else if (s[0] == 's') {
            printf("%d\n", q.getSize());
        } else if (s[0] == 'e') {
            printf("%d\n", q.empty());
        } else if (s[0] == 'p') {
            printf("%d\n", q.pop());
        }
    }
MAIN_END

/*
큐 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.5 초 (추가 시간 없음)	256 MB	49183	23187	17914	49.228%
문제
정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

예제 입력 1 
15
push 1
push 2
front
back
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
front
예제 출력 1 
1
2
2
0
1
2
-1
0
1
-1
0
3
*/
