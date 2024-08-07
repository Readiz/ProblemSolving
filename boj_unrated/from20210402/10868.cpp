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

#define INF 0x7FFFFFFF
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

int N, M;
int data[100000];

typedef struct __N {
    int left = -1;
    int right = -1;
    int min = INF;
} Node;
Node tree[1000000]; // Size는 Data를 담는 녀석의 두배 이상이 되어야 할 것 (Seg Tree 특성)

int makeSegTree(int idx) {
    Node curNode = tree[idx];
    int start = curNode.left;
    int end = curNode.right;
    int size = end - start + 1;
    printd("[MakeSegTree] Idx: %d / start: %d / end: %d", idx, start, end);

    if (size <= 0) return INF; // 비정상 case
    else if (size == 1) {
        // 남은 노드 한개 일때는, leaf임
        curNode.left = start; // 어차피 start / end는 같은 값. (leaf 조건)
        curNode.right = end;
        curNode.min = data[start]; // 어차피 데이터는 같은 값..
        return curNode.min;
    } else {
        // 아닐 때는, 재귀 호출
        // printd("left: %d, right: %d, call recursively...", start, end);
        int lChild = (idx + 1) * 2 - 1;
        int rChild = (idx + 1) * 2;
        Node* lNode = &tree[lChild];
        Node* rNode = &tree[rChild];

        lNode->left = start;
        lNode->right = start + (end - start) / 2;
        // printd("[LEFT] left: %d, right: %d, call recursively...", lNode->left, lNode->right);
        lNode->min = makeSegTree(lChild);

        rNode->left = start + (end - start) / 2 + 1;
        rNode->right = end;
        // printd("[Right] left: %d, right: %d, call recursively...", rNode->left, rNode->right);
        rNode->min = makeSegTree(rChild);

        // 만드는 것 완료 되었으면, 값 업데이트. (좌측 / 우측에서 값 받자..)
        return MIN(lNode->min, rNode->min);
    }
}

int query(int idx, int left, int right) {
    printd("[QUERY] Find %d...", idx);
    Node* curNode = &tree[idx];
    printd("[QUERY] left: %d / right: %d", curNode->left, curNode->right);
    if (left <= curNode->left && right >= curNode->right) {
        // 전체 포함하면, 최소값 리턴
        printd("[QUERY] Area covered, value return!");
        return curNode->min;
    } else if (left > curNode->right || right < curNode->left) {
        // 하나도 포함 안해도, 리턴
        printd("[QUERY] Area is not covered at all! return dummy value...");
        return INF;
    } else {
        // 아니면, 자식들에게 똑같이 쿼리.
        int lChild = (idx + 1) * 2 - 1;
        int rChild = (idx + 1) * 2;
        printd("[QUERY] Call %d and %d...", lChild, rChild);
        int leftVal = query(lChild, left, right);
        int rightVal = query(rChild, left, right);
        int min = MIN(leftVal, rightVal); // 매크로 함수에 걸어버리면 함수 중복 호출 됨...
        return min;
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d %d", &N, &M);
    printd("N: %d / M: %d", N, M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &data[i]);
    }

    tree[0].left = 0;
    tree[0].right = N - 1;
    tree[0].min = makeSegTree(0);
    printd("[REF] MIN ROOT: %d", tree[0].min);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printd("[QUERY] %d ~ %d", a - 1, b - 1);
        // 쿼리
        printf("%d\n", query(0, a - 1, b - 1));
    }
MAIN_END

// 전형적인 Segment Tree 사용하는 문제.
/*
최솟값 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	11115	4896	3362	47.392%
문제
N(1 ≤ N ≤ 100,000)개의 정수들이 있을 때, a번째 정수부터 b번째 정수까지 중에서 제일 작은 정수를 찾는 것은 어려운 일이 아니다. 하지만 이와 같은 a, b의 쌍이 M(1 ≤ M ≤ 100,000)개 주어졌을 때는 어려운 문제가 된다. 이 문제를 해결해 보자.

여기서 a번째라는 것은 입력되는 순서로 a번째라는 이야기이다. 예를 들어 a=1, b=3이라면 입력된 순서대로 1번, 2번, 3번 정수 중에서 최솟값을 찾아야 한다. 각각의 정수들은 1이상 1,000,000,000이하의 값을 갖는다.

입력
첫째 줄에 N, M이 주어진다. 다음 N개의 줄에는 N개의 정수가 주어진다. 다음 M개의 줄에는 a, b의 쌍이 주어진다.

출력
M개의 줄에 입력받은 순서대로 각 a, b에 대한 답을 출력한다.

예제 입력 1 
10 4
75
30
100
38
50
51
52
20
81
5
1 10
3 5
6 9
8 10
예제 출력 1 
5
38
20
5
*/