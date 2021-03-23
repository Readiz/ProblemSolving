#include <stdio.h>
#include <deque>
using namespace std;

#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("10866_input.txt", "rt", stdin); }
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
    int T;
    scanf("%d", &T);
    printd("--------------------------");
    deque<int> deque;
    for (int tc = 0; tc < T; tc++) {
        char cmd[10] = {0, };
        scanf("%s", cmd);
        if (cmd[0] == 'p') {
            if (cmd[1] == 'u') {
                int tmp;
                scanf("%d", &tmp);
                if (cmd[5] == 'b') {
                    deque.push_back(tmp);
                } else {
                    deque.push_front(tmp);
                }
            } else {
                if (cmd[4] == 'b') {
                    if (deque.size() > 0) {
                        printf("%d\n", deque.back());
                        deque.pop_back();
                    } else {
                        printf("-1\n");
                    }
                } else {
                    if (deque.size() > 0) {
                        printf("%d\n", deque.front());
                        deque.pop_front();
                    } else {
                        printf("-1\n");
                    }
                }
            }
        } else if (cmd[0] == 'f') {
            if (deque.size() > 0) {
                printf("%d\n", deque.front());
            } else {
                printf("-1\n");
            }
        } else if (cmd[0] == 'b') {
            if (deque.size() > 0) {
                printf("%d\n", deque.back());
            } else {
                printf("-1\n");
            }
        } else if (cmd[0] == 's') {
            printf("%d\n", (int) deque.size());
        } else if (cmd[0] == 'e') {
            if (deque.size() > 0) {
                printf("0\n");
            } else {
                printf("1\n");
            }
        }
    }
MAIN_END


/*
큐 2 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초 (하단 참고)	512 MB	19155	5773	4619	30.931%
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
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 2,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/
