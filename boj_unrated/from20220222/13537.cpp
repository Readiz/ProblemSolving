#include <stdio.h>

#define printd(...) printf(__VA_ARGS__)
#define R register
#define NULL 0

int A[100001];
int N, M;

struct Node {
    int s;
    int e;
    int max;
    int min;

    Node* l;
    Node* r;

    Node() {
        l = NULL;
        r = NULL;
    }
};

Node* root = NULL;

int query(Node* n, int i, int j, int k) {
    printd("[QUERY] %d, %d find > %d(at %d ~ %d)\n", i, j, k, n->s, n->e);
    if (n->s > j || n->e < i) {
        return 0;
    }

    // 구간 전체가 들어가는 경우
    if (n->s >= i && n->e <= j) {
        int localmax = n->max;
        int localmin = n->min;
        printd("inner case. k: %d / max: %d, min: %d\n", k, localmax, localmin);
        if (k >= localmax) {
            printd("all members are bigger than %d at %d ~ %d\n", k, n->s, n->e);
            return 0;
        } else if (k < localmin) {
            printd("all members are smaller than %d at %d ~ %d\n", k, n->s, n->e);
            return (n->e - n->s + 1);
        } else {
            if (n->l != NULL && n->r != NULL) {
                return query(n->l, i, j, k) + query(n->r, i, j, k);
            } else if (n->l != NULL) {
                return query(n->l, i, j, k);
            } else if (n-> r != NULL) {
                return query(n->r, i, j, k);
            } else {
                printd("leaf, member is smaller than %d! (val: %d)\n", k, n->max);
                return 0;
            }
        }
    } else { // 일부만 들어가는 경우 - 무조건 나눠서 쿼리 재생산
        if (n->l != NULL && n->r != NULL) {
            return query(n->l, i, j, k) + query(n->r, i, j, k);
        } else if (n->l != NULL) {
            return query(n->l, i, j, k);
        } else if (n-> r != NULL) {
            return query(n->r, i, j, k);
        } else {
            return 0;
        }
    }
}



Node* make_tree(int s, int e) {
    Node* root = new Node;
    root->s = s;
    root->e = e;
    int mid = (s + e) / 2;
    printd("[DEBUG] make_tree %3d ~ %3d (mid: %d)\n", s, e, mid);

    // left 업데이트
    if (s != e) {\
        root->l = make_tree(s, mid);
    }

    // right 업데이트
    if (mid + 1 <= e) {
        root->r = make_tree(mid + 1, e);
    }

    // max 값 업데이트
    if (s == e) { // leaf 일떄는 자기자신임
        root->max = A[s];
        root->min = A[s];
    }
    if (root->l != NULL && root->r != NULL) {
        if (root->l->max < root->r->max) {
            root->max = root->r->max;
        } else {
            root->max = root->l->max;
        }
        if (root->l->min > root->r->min) {
            root->min = root->r->min;
        } else {
            root->min = root->l->min;
        }
    } else if (root->l != NULL) {
        root->max = root->l->max;
        root->min = root->l->min;
    } else if (root->r != NULL){
        root->max = root->r->max;
        root->min = root->r->min;
    }
    return root;
}

int main() {
    scanf("%d", &N);
    for (R int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);
    }

    Node* root = make_tree(1, N);
    printd("[TEST] all_max: %d\n", root->max);

    scanf("%d", &M);
    while (M--) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        printf("%d\n", query(root, i, j, k));
    }

    return 0;
}

/*
수열과 쿼리 1
시간 제한	메모리 제한	제출	정답	맞힌 사람	정답 비율
1 초	512 MB	3127	1358	967	48.278%
문제
길이가 N인 수열 A1, A2, ..., AN이 주어진다. 이때, 다음 쿼리를 수행하는 프로그램을 작성하시오.

i j k: Ai, Ai+1, ..., Aj로 이루어진 부분 수열 중에서 k보다 큰 원소의 개수를 출력한다.
입력
첫째 줄에 수열의 크기 N (1 ≤ N ≤ 100,000)이 주어진다.

둘째 줄에는 A1, A2, ..., AN이 주어진다. (1 ≤ Ai ≤ 109)

셋째 줄에는 쿼리의 개수 M (1 ≤ M ≤ 100,000)이 주어진다.

넷째 줄부터 M개의 줄에는 쿼리 i, j, k가 한 줄에 하나씩 주어진다. (1 ≤ i ≤ j ≤ N, 1 ≤ k ≤ 109)

출력
각각의 쿼리마다 정답을 한 줄에 하나씩 출력한다.

예제 입력 1 
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2
예제 출력 1 
2
0
3
*/