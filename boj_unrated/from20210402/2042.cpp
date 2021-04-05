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
typedef long long int ll;
typedef struct _N {
    int left;
    int right;
    ll sum;
} Node;

int N, M, K;
ll db[1'000'000];
Node tree[3'000'000]; // db의 두배 이상 크기일 것.. 넉넉하게.

ll makeSegTree(int idx) {
    int start = tree[idx].left;
    int end = tree[idx].right;
    printd("[MAKE_SEG_TREE] id: %d / from: %d to %d...", idx, start, end);
    // 부모는 생성되어서 오므로 자식을 재귀적으로 호출해주면 된다.
    if (end - start < 0) return 0LL; // 말이 안되는 case..
    else if (end - start == 0) { // Leaf case
        return db[start]; // 부모에서 left, right 설정해주므로, 값만 리턴하면 됨.
    } else { // 분할하여 내려가는 case
        int mid = start + (end - start) / 2; // 중간에 overflow를 방지하는 중간값 계산
        int lChildIdx = (idx + 1) * 2 - 1;
        int rChildIdx = (idx + 1) * 2;
        tree[lChildIdx].left = start;
        tree[lChildIdx].right = mid;
        tree[lChildIdx].sum = makeSegTree(lChildIdx);
        tree[rChildIdx].left = mid + 1;
        tree[rChildIdx].right = end;
        tree[rChildIdx].sum = makeSegTree(rChildIdx);
        return tree[lChildIdx].sum + tree[rChildIdx].sum;
    }
}

int findSegTreeIdx(int idx, int target) {
    int start = tree[idx].left;
    int end = tree[idx].right;
    int lChildIdx = (idx + 1) * 2 - 1;
    int rChildIdx = (idx + 1) * 2;
    printd("[FIND_SEG_TREE] id: %d / target: %d...", idx, target);
    // printd("[FIND_SEG_TREE] Left: %d / from: %d to %d...", lChildIdx, tree[lChildIdx].left, tree[lChildIdx].right);
    // printd("[FIND_SEG_TREE] Right: %d / from: %d to %d...", rChildIdx, tree[rChildIdx].left, tree[rChildIdx].right);
    if (end - start == 0 && target == start) {
        return idx;
    } else if (tree[lChildIdx].left <= target && tree[lChildIdx].right >= target) {
        printd("[FIND_SEG_TREE] go down to left side...");
        return findSegTreeIdx(lChildIdx, target);
    } else if (tree[rChildIdx].left <= target && tree[rChildIdx].right >= target) {
        printd("[FIND_SEG_TREE] go down to right side...");
        return findSegTreeIdx(rChildIdx, target);
    } else {
        return -1;
    }
}

// 자식이 부모를 물고 호출 (?) 어차피 맨 자식이 업데이트 되는 case 밖에 없다.
void updateSegTree(int idx) {
    printd("[UPDATE_SEG_TREE] Target Seg Tree Idx: %d", idx);
    int start = tree[idx].left;
    int end = tree[idx].right;
    if (end - start == 0) { // Leaf Case
        tree[idx].sum = db[start];
    } else {
        int lChildIdx = (idx + 1) * 2 - 1;
        int rChildIdx = (idx + 1) * 2;
        tree[idx].sum = tree[lChildIdx].sum + tree[rChildIdx].sum;
    }
    if (idx != 0) { // 최상단 노드가 아니라면, 부모를 반복 호출
        int parent = (idx - 1) / 2;
        updateSegTree(parent);
    }
}

ll querySegTree(int idx, int start, int end) {
    printd("[QUERY_SEG_TREE] id: %d / from %d to %d...", idx, start, end);
    // 안겹치는 경우
    if (tree[idx].right < start || tree[idx].left > end) {
        return 0LL;
    } else if (tree[idx].left >= start && tree[idx].right <= end) {
        // 완전히 겹치는 경우
        printd("[QUERY_SEG_TREE] Range is overlapped(%d ~ %d)! return sum: %lld...", tree[idx].left, tree[idx].right, tree[idx].sum);
        return tree[idx].sum;
    } else {
        // 중첩으로 겹치는 경우 (재귀 쿼리 호출)
        int lChildIdx = (idx + 1) * 2 - 1;
        int rChildIdx = (idx + 1) * 2;
        return querySegTree(lChildIdx, start, end) + querySegTree(rChildIdx, start, end);
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &db[i]);
    }
    // Root 설정 및 SegTree 생성
    tree[0].left = 0; tree[0].right = N - 1;
    tree[0].sum = makeSegTree(0);

    // Query Start or Update
    for (int i = 0; i < M + K; i++) {
        ll cmd, a, b;
        scanf("%lld %lld %lld", &cmd, &a, &b);
        if (cmd == 1) { // Update
            db[a - 1] = b;
            int idx = findSegTreeIdx(0, a - 1);
            if (idx != -1) updateSegTree(idx); // a 번째 값을 업데이트
            else printd("[FATAL] cannot find the target node!!!");
        } else { // Query
            ll r = querySegTree(0, a - 1, b - 1);
            printf("%lld\n", r);
        }
    }
MAIN_END


/*
구간 합 구하기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	256 MB	46698	9104	4688	23.580%
문제
어떤 N개의 수가 주어져 있다. 그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 만약에 1,2,3,4,5 라는 수가 있고, 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수이다. 그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, a가 1인 경우 b(1 ≤ b ≤ N)번째 수를 c로 바꾸고 a가 2인 경우에는 b(1 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합을 구하여 출력하면 된다.

입력으로 주어지는 모든 수는 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

예제 입력 1 
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5
예제 출력 1 
17
12
*/
