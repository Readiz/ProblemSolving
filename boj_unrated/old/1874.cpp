#include <stdio.h>

int Stack[100000] = {0, };
int StackSize = 0;

void push(int num) {
    Stack[StackSize++] = num;
}
int pop() {
    return Stack[--StackSize];
}
int peek() {
    return Stack[StackSize - 1];
}
int N;
int arr[100001] = {0, };

bool isAvailable() {
    int lastEle = 0;
    int p = 0;
    // 최초 아이템까지는 해당 숫자가 될 때까지 +, 출력 위해 -
    while (p < N) {
        if (arr[p] > lastEle) {
            while (arr[p] > lastEle) {
                lastEle++;
                push(lastEle);
            }
            pop();
        } else {
            if (arr[p] == peek()) {
                pop();
            } else {
                return false;
            }
        }
        p++;
    }
    return true;
}
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    if (isAvailable()) {
        int lastEle = 0;
        int p = 0;
        // 최초 아이템까지는 해당 숫자가 될 때까지 +, 출력 위해 -
        while (p < N) {
            if (arr[p] > lastEle) {
                while (arr[p] > lastEle) {
                    printf("+\n");
                    lastEle++;
                }
                printf("-\n");
            } else {
                printf("-\n");
            }
            p++;
        }
    } else {
        printf("NO\n");
    }

    return 0;
}

// 일단 첫 번째 아이템은 무조건 출력 가능
// 그 다음 증가하는 아이템도 출력 가능
// 감소하는 아이템 출력이 조금 애매한데, stack top에 있는 아이템의 경우 출력 가능

/*
문제
스택 (stack)은 기본적인 자료구조 중 하나로, 컴퓨터 프로그램을 작성할 때 자주 이용되는 개념이다. 스택은 자료를 넣는 (push) 입구와 자료를 뽑는 (pop) 입구가 같아 제일 나중에 들어간 자료가 제일 먼저 나오는 (LIFO, Last in First out) 특성을 가지고 있다.

1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다. 이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자. 임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지, 있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다. 이를 계산하는 프로그램을 작성하라.

입력
첫 줄에 n (1 ≤ n ≤ 100,000)이 주어진다. 둘째 줄부터 n개의 줄에는 수열을 이루는 1이상 n이하의 정수가 하나씩 순서대로 주어진다. 물론 같은 정수가 두 번 나오는 일은 없다.

출력
입력된 수열을 만들기 위해 필요한 연산을 한 줄에 한 개씩 출력한다. push연산은 +로, pop 연산은 -로 표현하도록 한다. 불가능한 경우 NO를 출력한다.
*/
