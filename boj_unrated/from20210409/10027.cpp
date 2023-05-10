#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
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
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);
    #define MAIN_END return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

inline bool m_strcmp(char a[], char b[]) {
    int p;
    for (p = 0; a[p] != 0; p++) {
        if (a[p] != b[p]) return false;
    }
    if (a[p] != b[p]) return false;
    return true;
}

inline void m_strcpy(char dest[], char src[]) {
    int p;
    for (p = 0; src[p] != 0; p++) {
        dest[p] = src[p];
    }
    dest[p] = 0;
}

template<class T>
class DArray {
    T* n;
    int capacity;
public:
    int size;
    DArray() {
        n = NULL;
        init();
    }
    void init(int newCap = 100) {
        if (n != NULL) {
            delete[] n;
        }
        size = 0;
        capacity = newCap;
        n = new T[capacity];
    }
    void push(T item) { // call by value..
        // 공간 다 찼을 경우.. 늘린다.
        if (size == capacity) {
            capacity *= 2; // 두배로 늘린다.
            T* newNodes = new T[capacity];
            for (int i = 0; i < size; i++) {
                newNodes[i] = n[i]; // 기존 값 복사
            }
            delete[] n;
            n = newNodes;
        }
        n[size++] = item;
    }
    T& pop() {
        return n[--size];
    }
    T& operator[] (int idx) {
        return n[idx];
    }
    DArray<T>& operator= (DArray<T>& src) {
        this->init();
        for (int i = 0; i < src.size; i++) {
            this->push(src[i]);
        }
        return *this;
    }
    ~DArray() {
        if (n != NULL) {
            delete[] n;
        }
    }
};

// DArray가 사실 Stack 그 자체임.
template<class T>
class Stack {
    DArray<T> db;
public:
    Stack() {
    }
    void push(T n) {
        db.push(n);
    }
    T& pop() {
        return db.pop();
    }
    T& top() {
        return db[db.size - 1];
    }
    int getSize() {
        return db.size;
    }
    int print() {
        for (int i = 0; i < db.size; i++) {
            printf("%d ", db[i]);
        }
    }
};

// 가짜 Set 구현
template<class T>
class Set {
    DArray<T> db;
public:
    Set() {
    }
    void insert(T n) { // 시간복잡도: O(n)...
        for (int i = 0; i < db.size; i++) {
            if (db[i] == n) return; // 중복된 원소 있으면 삽입 X
        }
        db.push(n);
    }
    bool find(T& n) { // 이거도 시간복잡도: O(n)... 개선할 필요 있음.
        for (int i = 0; i < db.size; i++) {
            if (db[i] == n) return true;
        }
        return false;
    }
    Set& operator= (Set& src) {
        db = src.db;
        return *this;
    }
};

int getHash(char a[]) {
    int h_key = 0;
    for (register int i = 0; a[i]!='\0'; ++i)
    {
        h_key = (h_key << 5) + a[i] - 'a' + 1;
    }
    return h_key;
}

class HTMLElement {
public:
    char id[21];
    DArray<int> children;
    Set<int> classes;

    HTMLElement() {

    }
    HTMLElement(char s[]) {
        m_strcpy(id, s);
    }

    void addChild(int child_id) {
        children.push(child_id);
    }

    void addClass(char *str) {
        int hash = getHash(str);
        classes.insert(hash);
    }

    HTMLElement& operator= (HTMLElement& src) {
        m_strcpy(this->id, src.id);
        this->classes = src.classes;
        this->children = src.children;
        return *this;
    }
};

class SelectorElement {
public:
    int type;
    DArray<int> classes;

    SelectorElement() {

    }
    SelectorElement(int type) {
        this->type = type;
    }

    void addClass(char *str) {
        int hash = getHash(str);
        classes.push(hash);
    }

    bool check(HTMLElement &target) {
        for (int i = 0; i < classes.size; i++) {
            if (target.classes.find(classes[i]) == false) return false;
        }
        return true;
    }
};

void getDOM(DArray<HTMLElement>& tree) {
    int N;
    scanf("%d", &N);
    printd("N: %d", N);

    Stack<int> parents;
    tree.push(HTMLElement());
    parents.push(0);

    for (int i = 0; i < N; ++i) {
        char tag_start[20] = {0, };
        scanf("%s", tag_start);
        if(m_strcmp(tag_start, "</div>")) {
            parents.pop();
        } else {
            char name[31] = {0, };
            scanf(" id='%[^']'", name);
            printd("ID: %s", name);
            tree.push(HTMLElement(name));
            tree[parents.top()].addChild(tree.size - 1);
            parents.push(tree.size - 1);

            scanf(" class='");
            char class_name[31];
            while(scanf(" %[^ ']", class_name)) {
                printd("Read Class Name: %s", class_name);
                tree[tree.size - 1].addClass(class_name);
            }
            scanf("'>");
        }
    }
}

void getSelector(DArray<SelectorElement>& sel) {
    char c;
    while(scanf("%c", &c)) {
        if(c == ' ') continue;
        if(c == '\n') break;
        if(c == '>') {
            sel.push(SelectorElement(0));
            scanf(" %c", &c);
        } else {
            sel.push(SelectorElement(1));
        }
        sel.push(SelectorElement(2));

        char class_name[21];
        while(scanf("%[^. \n]", class_name)) {
            sel[sel.size - 1].addClass(class_name);
            scanf(".");
        }
    }
}

bool visited[2][5010][5010];
DArray<HTMLElement> DOMTree;
DArray<SelectorElement> Selector;

void DFS(int jump, int node, int pos, DArray<int> &ans) {
    if(visited[jump][node][pos]) return;
    visited[jump][node][pos] = true;

    if(pos == Selector.size) {
        if(!jump) ans.push(node);
        return;
    }

    switch (Selector[pos].type) {
    case 0: // 직속 자식을 추가하는 경우
        for(int i = 0; i < DOMTree[node].children.size; i++) {
            int child = DOMTree[node].children[i];
            DFS(0, child, pos + 1, ans);
        }
        break;
    case 1: // 일반 자식을 추가하는 경우
        if(jump) DFS(0, node, pos + 1, ans);
        for(int i = 0; i < DOMTree[node].children.size; i++) {
            int child = DOMTree[node].children[i];
            DFS(1, child, pos, ans);
        }
        break;
    case 2: // AND 조건 selector를 추가하는 경우
        if(!Selector[pos].check(DOMTree[node])) return;
        DFS(0, node, pos + 1, ans);
        break;
    }
}

void insertionSort(DArray<int>& arr) {
    int n = arr.size;
    int j;
    for (int i = 1; i < n; i++) {
        int tmp = arr[(j = i)];
        while (--j >= 0 && tmp < arr[j]) {
            arr[j + 1] = arr[j];
            arr[j] = tmp;
        }
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    getDOM(DOMTree);
    printd("Parsing complete! now receiving css selector...");

    int M;
    scanf("%d\n", &M);
    for(int i = 0; i < M; i++) {
        Selector.init();
        getSelector(Selector);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 5010; j++) {
                for (int k = 0; k < 5010; k++) {
                    visited[i][j][k] = false;
                }
            }
        }
        DArray<int> result;
        DFS(0, 0, 0, result);
        insertionSort(result);
        printf("%d ", result.size);
        // 문서에 나온 순서대로 = ID 순서대로와 동치임
        for(int i = 0; i < result.size; i++) {
            printf("%s ", DOMTree[result[i]].id);
        }
        printf("\n");
    }
MAIN_END


/*
CSS 출처다국어분류
시간 제한    메모리 제한    제출    정답    맞은 사람    정답 비율
10 초    256 MB    157    6    6    35.294%
문제
오늘날 많이 사용되고 있는 HTML 문서는 계층 구조를 가지는 형식이다. 이 문서는 '요소'라 불리는 것들로 구성되어 있으며, 요소는 이름과 함께 특정 '속성'들을 가지고, 또 다른 요소들을 포함할 수도 있다. 여기에서는 div 요소로만 구성되어 있는 HTML 문서를 사용한다고 가정하자. 명확하게, 각 문서는 아래와 같은 형태의 라인들로 구성되어 있다.

<div id=’name’ class=’class1 class2 . . . classK’> 요소의 시작
...                                                요소의 내용
</div>                                             요소의 끝
따라서, 한 개의 요소는 그 시작을 나타내는 줄과, 그 끝을 나타내는 줄, 그리고 그 사이가 비어 있거나, 혹은 그 사이에 또 다른 요소를 계속해서 포함할 수 있는 요소가 한 개 혹은 여러 개 존재하는 내용으로 구성되어 있다. 문서 또한 여러 요소의 집합으로 구성되어 있으며, 그 중 일부는 또 다른 요소를 포함할 수도 있다. 추가적으로 요소를 정의하기 위한 사항들은 다음과 같다.

요소의 이름(id)은 영문 알파벳 소문자로 구성되어 있다. 이름은 문서에서 해당 요소를 하나밖에 없는 것으로 정의하며, 다른 요소와 같은 이름을 사용할 수 없다.
요소의 각 클래스(class) 역시 영문 알파벳 소문자로 구성되며, 요소의 초기 목록에 포함된 클래스가 있다면, 그 요소가 해당 클래스에 속한다고 할 수 있다. 각 요소는 하나 이상의 서로 다른 클래스에 속할 수 있다. 서로 다른 요소가 같은 클래스들에 속하는 것 역시 가능하다.
요소를 나타내는 줄에서 공백이 올 수 있는 곳은 id 바로 앞에 1개, class 바로 앞에 1개 그리고 각각의 클래스 사이, 즉, 인접한 두 클래스 사이에 1개다.
만약 요소 E가 요소 F의 내용 (즉, 시작을 나타내는 줄과, 끝을 나타내는 줄 사이의 어느 곳이든) 에 작성되어 있다면, 우리는 F가 E를 포함하고 있다고 할 수 있고, 다시 말해, E가 F에 포함되어 있다고 할 수 있다.

만약 요소 F가 E에 포함되어 있으며, 'F를 포함하고 E에 포함된' G라는 요소가 없다면, E는 F의 부모라 할 수 있다.

CSS는 웹브라우저에서 HTML 요소들이 보여질 때 그 요소들의 생김새와 형태를 기술하기 위해 사용되는 스타일 시트 언어다. 이 언어의 중요한 부분은 선택자와 분류자(classifier)다. 분류자는 점(.)으로 시작되며, 점(.)으로 구분되는 하나 이상의 클래스가 나열되는 형태를 가진다. 다시 말하지만 클래스는 영문 소문자 알파벳으로만 이루어져 있다. 분류자의 몇 가지 예를 들면 다음과 같다. ".banana.apple", ".banana", ".apple.banana.mango". 이 분류자들은 순서대로 각각 2개, 1개, 3개의 클래스로 이루어져 있다. 우리는 분류자에 나열된 모든 클래스에 속한 HTML 요소는 그 분류자에 속한다고 한다.

선택자는 하나 이상의 분류자로 구성되며, 인접한 두 분류자는 공백, 오른 꺽쇠(" > "), 공백 문자열로 구분된다. HTML 요소는 재귀적으로 정의된 아래와 같은 방법으로 선택자에 의해 선택된다.

선택자 S가 딱 하나의 분류자 k로 구성되었다면, k에 해당하는 요소는 S에 해당한다.
선택자 S가 'T k'의 형태이며 T가 선택자, k가 분류자라면, k에 해당하는 요소 E가 T에 해당하는 요소 F에 포함되어 있다면(직접 포함일 필요는 없다), E는 S에 해당한다.
선택자 S가 'T > k'의 형태이며 T가 선택자, k가 분류자라면, k에 해당하는 요소 E의 부모 F가 T에 해당할 경우, E가 S에 해당한다.
N 줄로 구성된 문서와 M 개의 선택자가 주어질 때, 각 선택자에 해당하는 모든 요소의 이름을 출력하는 프로그램을 작성하시오. 각각의 선택자에 대해 출력은 주어진 문서 상에 나타나는 순서와 반드시 일치해야 한다.

입력
입력의 첫 줄에는 짝수 정수, N(2 ≤ N ≤ 10 000)이 주어지며, 전체 문서의 줄 수를 나타낸다.

이어지는 N개의 줄에 문서의 내용이 주어진다. 각 줄은 위에서 설명한 대로 한 요소의 시작이거나 끝에 해당한다.

그 다음 줄에는 선택자의 개수 M(1 ≤ M ≤ 5)이 정수로 주어진다.

그 다음 M개 줄에는 각각의 선택자가 주어진다.

입력되는 데이터의 모든 요소의 이름과 클래스는 영문 알파벳 소문자로만 구성되며 20자를 넘지 않는다.

추가적으로, 입력 데이터의 각 줄은 5,000 글자를 넘지 않으며, 입력에 포함된 모든 줄의 길이를 합해도 5,000,000 글자를 넘지 않는다.

출력
입력 데이터의 각 선택자마다 한 줄을 출력한다. 먼저 그 선택자에 해당하는 요소의 개수를 출력하고, 문서에 기술된 순서대로 요소의 이름(id)을 출력한다.

예제 입력 1 
22
<div id='a' class='banana mango'>
<div id='b' class='orange'>
<div id='c' class='banana'>
<div id='d' class='apple mango orange'>
<div id='e' class='orange'>
</div>
</div>
</div>
</div>
<div id='f' class='orange apple'>
<div id='g' class='apple'>
<div id='h' class='orange apple'>
<div id='i' class='banana'>
</div>
</div>
</div>
<div id='j' class='banana'>
</div>
</div>
</div>
<div id='k' class='glupo voce daj mi sarme'>
</div>
5
.banana
.banana > .sarme
.banana > .orange > .banana
.banana .apple.orange > .orange
.mango > .orange .banana
예제 출력 1 
4 a c i j
0
2 c j
1 e
3 c i j
*/
