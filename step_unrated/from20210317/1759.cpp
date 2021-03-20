#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("1759_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif

template <class T>
void SWAP(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// right가 Size가 아님에 주의. 마지막 실제 존재하는 원소를 가리킬 수 있어야 함.
// 즉, quickSort(arr, 0, size - 1); -> arr[0] 와 arr[size - 1] 둘 다 유효해야함.
template <class T>
void quickSort(T arr[], int left, int right) {
    int i = left;
    int j = right;
    T pivot = arr[(left + right) / 2];

    while (true) {
        while (arr[i] < pivot) i++; // 좌측포인터를 움직여서 pivot 보다 더 큰놈이 좌측에 있으면, 그 위에서 대기
        while (arr[j] > pivot) j--; // 우측포인터를 움직여서, pivot보다 더 작은놈이 우측에 있으면, 그 위에서 대기
        // i, j 포인터가 엇갈리면, break. 
        if (i > j) break;
        // 엇갈리기 전이면, SWAP을 반복한다.
        SWAP(arr[i], arr[j]);
        i++; j--; // 다음 swap 거리를 찾아보자
    }
    // 엇갈린 기준으로 break 하였으니(좌측은 j, 우측은 i), 엇갈린 기준으로 배열은 분할정복한다.
    if (left < j) quickSort(arr, left, j); // left < j 가 될 때만 quickSort를 반복해야함. (안그러면 무한 재귀 탐)
    if (i < right) quickSort(arr, i, right); // i < right 가 될 때만 quickSort를 반복해야함. (재귀 탈출 조건)
}

template <class T>
void inverse(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        SWAP(arr[i], arr[size - i - 1]);
    }
}

class ResultDataManager {
    char data[10000][20] = {0, };
    int pos = -1;
    int charPos;
public:
    void startNewData() {
        pos++;
        charPos = 0;
    }
    void addChar(char a) {
        data[pos][charPos++] = a;
    }
    void printResult() {
        for (int i = 0; i <= pos; i++) {
            printf("%s\n", data[i]);
        }
    }
};
ResultDataManager myResultDataManager;

class Stack {
    int size = 0;
    char data[20] = {0, };
public:
    void push(char d) {
        data[size++] = d;
    }
    char pop() {
        return data[--size];
    }
    void addDataToManager() {
        myResultDataManager.startNewData();
        for (int i = 0; i < size; i++) {
            myResultDataManager.addChar(data[i]);
        }
    }
};
Stack myStack;

int L, C;
char A[20] = {0, };
bool visited[20] = {false, };
int countAEIOU = 0;
int countELSE = 0;
int countALL = 0;

bool checkAEIOU(char a) {
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') {
        return true;
    }
    return false;
}

void DFS(int from) {
    if (countALL == L && countAEIOU >=1 && countELSE >= 2) { // 모순 없이 암호 최대 수에 다다랐으면..
        myStack.addDataToManager();
        return;
    } else if (countALL == L) { // 숫자만 채웠음 리턴.
        return;
    }
    for (int i = from + 1; i < C; i++) {
        if (!visited[i]) {
            if (checkAEIOU(A[i])) {
                countAEIOU++;
            } else {
                countELSE++;
            }
            countALL++;
            visited[i] = true;
            myStack.push(A[i]);
            DFS(i);
            myStack.pop();
            visited[i] = false;
            if (checkAEIOU(A[i])) {
                countAEIOU--;
            } else {
                countELSE--;
            }
            countALL--;
        }
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");

    scanf("%d %d", &L, &C);
    printd("L: %d, C: %d", L, C);
    printd("--------------------------");
    for (int i = 0; i < C; i++) {
        char tmp[10];
        scanf("%s", tmp);
        A[i] = tmp[0];
    }
    quickSort(A, 0, C - 1);
    // inverse(A, C);
    // 암호 구성은 최소 한개의 모음과 최소 두개의 자음임, 기억하고 DFS.
    for (int i = 0; i < C; i++) {
        if (checkAEIOU(A[i])) {
            countAEIOU++;
        } else {
            countELSE++;
        }
        countALL++;
        visited[i] = true;
        myStack.push(A[i]);
        DFS(i);
        myStack.pop();
        visited[i] = false;
        if (checkAEIOU(A[i])) {
            countAEIOU--;
        } else {
            countELSE--;
        }
        countALL--;
    }
    myResultDataManager.printResult();
MAIN_END


/*
암호 만들기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	28834	13437	9346	44.857%
문제
바로 어제 최백준 조교가 방 열쇠를 주머니에 넣은 채 깜빡하고 서울로 가 버리는 황당한 상황에 직면한 조교들은, 702호에 새로운 보안 시스템을 설치하기로 하였다. 이 보안 시스템은 열쇠가 아닌 암호로 동작하게 되어 있는 시스템이다.

암호는 서로 다른 L개의 알파벳 소문자들로 구성되며 최소 한 개의 모음(a, e, i, o, u)과 최소 두 개의 자음으로 구성되어 있다고 알려져 있다. 또한 정렬된 문자열을 선호하는 조교들의 성향으로 미루어 보아 암호를 이루는 알파벳이 암호에서 증가하는 순서로 배열되었을 것이라고 추측된다. 즉, abc는 가능성이 있는 암호이지만 bac는 그렇지 않다.

새 보안 시스템에서 조교들이 암호로 사용했을 법한 문자의 종류는 C가지가 있다고 한다. 이 알파벳을 입수한 민식, 영식 형제는 조교들의 방에 침투하기 위해 암호를 추측해 보려고 한다. C개의 문자들이 모두 주어졌을 때, 가능성 있는 암호들을 모두 구하는 프로그램을 작성하시오.

입력
첫째 줄에 두 정수 L, C가 주어진다. (3 ≤ L ≤ C ≤ 15) 다음 줄에는 C개의 문자들이 공백으로 구분되어 주어진다. 주어지는 문자들은 알파벳 소문자이며, 중복되는 것은 없다.

출력
각 줄에 하나씩, 사전식으로 가능성 있는 암호를 모두 출력한다.

예제 입력 1 
4 6
a t c i s w
예제 출력 1 
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw
*/
