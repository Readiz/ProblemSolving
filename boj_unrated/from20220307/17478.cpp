#include <stdio.h>

void printu(int k) {
    while (k-- > 0) {
        printf("____");
    }
}

void print(int N, int k) {
    if (N == 0) {
        printu(k); printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
        printu(k); printf("라고 답변하였지.\n");
        return;
    }
    printu(k); printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
    printu(k); printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
    printu(k); printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
    printu(k + 1); printf("\"재귀함수가 뭔가요?\"\n");
    print(N - 1, k + 1);
    printu(k); printf("라고 답변하였지.\n");
}

int main() {
    int N;
    scanf("%d", &N);
    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    printf("\"재귀함수가 뭔가요?\"\n");
    print(N, 0);
}