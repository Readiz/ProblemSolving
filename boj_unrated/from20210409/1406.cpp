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

// Linked List의 구현
typedef struct __N {
    char c;
    struct __N* prev;
    struct __N* next;
} Node;

class Editor {
    Node* root;
    Node* cur;
public:
    Editor() {
        // 나중에 root 뒤 부터 출력 시킬 것임. root에 커서 위치 가능.
        root = new Node;
        root->c = '!'; // 더미 문자열.. [참고] root는 삭제할 수 없다. 출력도 안함.
        root->prev = NULL;
        root->next = NULL;
        cur = root;
    }
    void init(char s[]) {
        for (int p = 0; s[p] != 0; p++) {
            cur->next = new Node;
            cur->next->prev = cur; // 새로 생성한 노드의 이전 포인터 정의
            cur = cur->next; // 새로 만든 노드로 옮기고..
            cur->c = s[p];
            cur->next = NULL;
        }
    }
    void moveLeft() {
        if (cur->prev != NULL) {
            cur = cur->prev;
        }
    }
    void moveRight() {
        if (cur->next != NULL) {
            cur = cur->next;
        }
    }
    void deleteLeft() {
        if (cur != root) { // root는 삭제하지 않는다.
            Node* prev = cur->prev;
            Node* next = cur->next;
            delete cur;
            // cur 커서를 지워주고, 둘을 이어준다.
            // prev가 NULL인 경우는 없지만(항상 root가 있으니), next가 없을 수는 있음.
            prev->next = next;
            if (next != NULL) {
                next->prev = prev;
            }
            cur = prev;
        }
    }
    void insertLeft(char c) {
        printd("[INSERT] %c", c);
        Node* newNode = new Node;
        newNode->c = c;
        newNode->next = cur->next;
        newNode->prev = cur;
        if (cur->next != NULL) {
            // 원래 연결된 그 다음 녀석의 이전 녀석도 다시 연결해줘야 한다.
            cur->next->prev = newNode; // *** 이거 안해주면 오류..
        }
        cur->next = newNode;
        cur = newNode;
    }
    void print() {
        Node* p = root;
        while (p->next != NULL) {
            if (p != root) printf("%c", p->c); // root의 다음 문자부터 출력
            p = p->next;
        }
        if (p != root) printf("%c", p->c); // 마지막 문자 출력
        printf("\n");
    }
};

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    char initStr[100'001];
    scanf("%s", initStr);
    Editor editor;
    editor.init(initStr);
    printd("Init with: %s", initStr);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        char cmd[2], c[2];
        scanf("%s", cmd);
        printd("CMD: %s", cmd);
        if (cmd[0] == 'L') {
            editor.moveLeft();
        } else if (cmd[0] == 'D') {
            editor.moveRight();
        } else if (cmd[0] == 'B') {
            editor.deleteLeft();
        } else {
            scanf("%s", c);
            editor.insertLeft(c[0]);
        }
    }
    editor.print();
MAIN_END

/*
에디터 출처다국어분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
0.3 초 (하단 참고)	512 MB	44243	12217	8085	27.176%
문제
한 줄로 된 간단한 에디터를 구현하려고 한다. 이 편집기는 영어 소문자만을 기록할 수 있는 편집기로, 최대 600,000글자까지 입력할 수 있다.

이 편집기에는 '커서'라는 것이 있는데, 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽), 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치할 수 있다. 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면, 커서가 위치할 수 있는 곳은 L+1가지 경우가 있다.

이 편집기가 지원하는 명령어는 다음과 같다.

L	커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
D	커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
B	커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
P $	$라는 문자를 커서 왼쪽에 추가함
초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때, 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 구하는 프로그램을 작성하시오. 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다고 한다.

입력
첫째 줄에는 초기에 편집기에 입력되어 있는 문자열이 주어진다. 이 문자열은 길이가 N이고, 영어 소문자로만 이루어져 있으며, 길이는 100,000을 넘지 않는다. 둘째 줄에는 입력할 명령어의 개수를 나타내는 정수 M(1 ≤ M ≤ 500,000)이 주어진다. 셋째 줄부터 M개의 줄에 걸쳐 입력할 명령어가 순서대로 주어진다. 명령어는 위의 네 가지 중 하나의 형태로만 주어진다.

출력
첫째 줄에 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열을 출력한다.

예제 입력 1 
abcd
3
P x
L
P y
예제 출력 1 
abcdyx
예제 입력 2 
abc
9
L
L
L
L
L
P x
L
B
P y
예제 출력 2 
yxabc
예제 입력 3 
dmih
11
B
B
P x
L
B
B
B
P y
D
D
P z
예제 출력 3 
yxz
*/
