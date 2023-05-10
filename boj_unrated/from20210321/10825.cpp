/////////////////////////////////////// TODO ///////////////////////////////
////// 아래는 정렬 벡터 버전. 내짠코드로 다시 해보자.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Student{
    string name;
    int a, b, c;
};

bool cmp(Student a, Student b) {
    if (a.a == b.a && a.b == b.b && a.c == b.c) return a.name < b.name;
    if (a.a == b.a && a.b == b.b) return a.c > b.c;
    if (a.a == b.a) return a.b < b.b;
    return a.a > b.a;
}
 
int main() {
    int N;
    cin >> N;
 
    vector<Student> v(N);
    for (int i=0; i<N; i++) {
        cin >> v[i].name >> v[i].a >> v[i].b >> v[i].c;
    }
    sort(v.begin(), v.end(), cmp);
 
    for (int i = 0; i < N; i++) {
        cout << v[i].name << '\n';
    }
}



/////////////////////// TODO /////////////////////////////
#include <stdio.h>
#include <cmath>
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

bool scmp(char a[], char b[]) {
    printd("%s vs %s", a, b);
    int lena, lenb;
    for (lena = 0; a[lena] != 0; lena++);
    for (lenb = 0; a[lenb] != 0; lenb++);
    int min = lena < lenb ? lena : lenb;
    for (int i = 0; i < min; i++) {
        if (a[i] >= b[i]) return true;
    }
    return false;
}
class Student {
    int a, b, c;
public:
    char name[11];
    void init(char _name[], int _a, int _b, int _c) {
        int p;
        for (p = 0; _name[p] != 0; p++) {
            name[p] = _name[p];
        }
        name[p] = 0;
        a = _a;
        b = _b;
        c = _c;
    }
    bool operator< (Student &o) {
        printd("comparing...");
        if (this->a > o.a) return true;
        if (this->a < o.a) return false;
        if (this->b < o.b) return true;
        if (this->b > o.b) return false;
        if (this->c > o.c) return true;
        if (this->c < o.c) return false;
        return scmp(this->name, o.name);
    }
    Student& operator= (Student &o) {
        int p;
        for (p = 0; o.name[p] != 0; p++) {
            name[p] = o.name[p];
        }
        name[p] = 0;
        a = o.a;
        b = o.b;
        c = o.c;
        return *this;
    }
};

Student s[100000];

template<class T>
void SWAP(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// right가 Size가 아님에 주의. 마지막 실제 존재하는 원소를 가리킬 수 있어야 함.
// 즉, quickSort(arr, 0, size - 1); -> arr[0] 와 arr[size - 1] 둘 다 유효해야함.
template<class T>
void quickSort(T arr[], int left, int right) {
    int i = left;
    int j = right;
    int mid = (left + right) / 2;
    T pivot = arr[mid];

    printd("QuickSort: left: %d, right %d", left, right);

    while (true) {
        while (arr[i] < pivot) i++; // 좌측포인터를 움직여서 pivot 보다 더 큰놈이 좌측에 있으면, 그 위에서 대기
        while (pivot < arr[j]) j--; // 우측포인터를 움직여서, pivot보다 더 작은놈이 우측에 있으면, 그 위에서 대기
        // i, j 포인터가 엇갈리면, break. 
        if (i > j) break;
        // 엇갈리기 전이면, SWAP을 반복한다.
        if (i != j) {
            printd("before i: %d, j: %d, swap: %s, %s", i, j, arr[i].name, arr[j].name);
            SWAP(arr[i], arr[j]);
            printd("after i: %d, j: %d, swap: %s, %s", i, j, arr[i].name, arr[j].name);
        }
        i++; j--; // 다음 swap 거리를 찾아보자
    }
    // 엇갈린 기준으로 break 하였으니(좌측은 j, 우측은 i), 엇갈린 기준으로 배열은 분할정복한다.
    if (left < j) quickSort(arr, left, j); // left < j 가 될 때만 quickSort를 반복해야함. (안그러면 무한 재귀 탐)
    if (i < right) quickSort(arr, i, right); // i < right 가 될 때만 quickSort를 반복해야함. (재귀 탈출 조건)
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    int N;
    scanf("%d", &N);
    printd("N: %d", N);
    printd("--------------------------");
    for (int i = 0; i < N; i++) {
        char name[11];
        int a, b, c;
        scanf("%s %d %d %d", name, &a, &b, &c);
        printd("%s %d %d %d", name, a, b, c);
        s[i].init(name, a, b, c);
    }
    quickSort(s, 0, N - 1);
    printd("--------------------------");
    printd("Result");
    printd("--------------------------");
    for (int i = 0; i < N; i++) {
        printf("%s\n", s[i].name);
    }
MAIN_END

/*
국영수 실패분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	15965	7847	5754	49.663%
문제
도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 이때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.

국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)
입력
첫째 줄에 도현이네 반의 학생의 수 N (1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 한 줄에 하나씩 각 학생의 이름, 국어, 영어, 수학 점수가 공백으로 구분해 주어진다. 점수는 1보다 크거나 같고, 100보다 작거나 같은 자연수이다. 이름은 알파벳 대소문자로 이루어진 문자열이고, 길이는 10자리를 넘지 않는다.

출력
문제에 나와있는 정렬 기준으로 정렬한 후 첫째 줄부터 N개의 줄에 걸쳐 각 학생의 이름을 출력한다.

예제 입력 1 
12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90
예제 출력 1 
Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan
*/
