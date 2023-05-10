#include <stdio.h>
#include <vector>
#include <list>
#include <string>
#include <deque>
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

template <typename T>
void printElements(T db) {
    for (const auto& elem: db) {
        cout << elem << "\n";
    }
}
template <typename T>
struct greater_comp {
    bool operator()(const T& a, const T& b) const { return a > b; }
};

int main() {
    vector<int> av;

    av.push_back(1);
    av.push_back(2);
    av.push_back(3);

    // C+11 이후부터 지원되는 아주 nice한 방식
    // 범위 기반 for문(range-based for) 라고 부름
    for (auto elem: av) { // -> 여기서 auto는 int임
        printf("%d\n", elem);
    }
    // 복사 안하고 출력해버리기
    for (const auto& elem: av) {
        printf("%d\n", elem);
    }

    // 기존 방식 -> size_type은 unsigned라, 역으로는 순회하기 어려움
    for (vector<int>::size_type i = 0; i < av.size(); i++) {
        printf("%d\n", av[i]);
    }

    // iterator를 사용하는 방식  -> iterator도 ++, -- 연산은 기본적으로 지원됨. (설마 list라 할 지라도)
    for (vector<int>::iterator itr = av.begin(); itr != av.end(); itr++) {
        printf("%d\n", *itr);
    }

    av.insert(av.begin(), 0); // iter 기준으로 삽입도 가능
    for (auto i: av) {
        printf("%d\n", i);
    }
    av.erase(av.begin());
    for (auto i: av) {
        printf("%d\n", i);
    }

    // 역참조자 -> size_type은 unsigned 임에 다시한번 유의.
    for (auto itr = av.rbegin(); itr != av.rend(); itr++) {
        printf("%d\n", *itr);
    }

    ///////////////////////////////////////////////////////////////////////

    list<string> l; // 임의위치 삽입 / 삭제가 O(1) 인 구조
    l.push_back("테스트");
    l.push_back("아햏햏");
    l.push_back("햄볶아요");
    printElements(l);

    l.insert(l.begin(), "첫번째에삽입");
    printElements(l);

    ///////////////////////////////////////////////////////////////////////

    deque<int> dq; // vector보다 많은 기능이 있지만 메모리 또한 희생이 큰 자료구조

    dq.push_back(51);
    dq.push_back(52);
    dq.push_back(53);
    printElements(dq);
    dq.pop_front();
    printElements(dq);
    dq.pop_back();
    printElements(dq);

    ///////////////////////////////////////////////////////////////////////
    set<int> s; // Heap과 동일하다고 생각하면 됨.. 삽입에 O(log n), 지우는데 O(log n)
    s.insert(500);
    s.insert(100);
    s.insert(123);
    s.insert(300);
    s.insert(50);
    printElements(s); // iterator로 접근은 가능하지만 순서가 없기 때문에 push_back 과 같은 메서드는 없음

    auto itr = s.find(123); // find도 O(log n) - 내부 트리 구성이기 때문
    if (itr != s.end()) {
        cout << "Found: " << *itr << "\n";
    } else {
        cout << "Not Found!\n";
    }

    ///////////////////////////////////////////////////////////////////////
    map<string, int> m;
    m.insert(make_pair("맥스", 32)); // <- map에는 pair를 넣어야 하기 때문임
    m.insert(make_pair("유니", 30));
    m.insert(make_pair("캬캬캬", 50));
    for (const auto& e: m) {
        cout << e.first << " / " << e.second << "\n"; // pair의 원소에 접근하기 위해서는 fisrt, second를 써야함
    }
    cout << "맥스의 나이: " << m["맥스"] << "\n";

    ///////////////////////////////////////////////////////////////////////
    cout << "Int 정렬 테스트\n";
    map<int, int> mint;
    mint.insert(make_pair(100, 52));
    mint.insert(make_pair(20, 35));
    mint.insert(make_pair(30, 40));
    mint.insert(make_pair(50, 40));
    for (const auto& e: mint) {
        cout << e.first << " / " << e.second << "\n"; // pair의 원소에 접근하기 위해서는 fisrt, second를 써야함
    }

    ///////////////////////////////////////////////////////////////////////
    unordered_set<string> realset; // 해시함수를 쓰는 set -> Find에 O(1)
    // 해시함수를 쓰기 때문에, custom obj를 넣으려면, 복잡한 hash 구현을 마쳐야지만 넣을 수 있다.
    realset.insert("맥스");
    realset.insert("유니");
    realset.insert("세균맨");
    realset.insert("호빵맨");
    printElements(realset);
    if (realset.find("호빵맨") != realset.end()) {
        cout << "호빵맨 이쑴\n";
    } else {
        cout << "호빵맨이 뉘신가\n";
    }

    ///////////////////////////////////////////////////////////////////////
    vector<int> sv;
    sv.push_back(50);
    sv.push_back(5);
    sv.push_back(1);
    sv.push_back(4);
    sv.push_back(30);
    sv.push_back(7);
    sv.push_back(10);
    cout << "Before: \n";
    printElements(sv);
    cout << "After: \n";
    sort(sv.begin(), sv.end()); // <- 임의접근 반복자를 가지고 있을 경우에만 가능, 즉 list는 정렬 불가임.
    printElements(sv);

    sort(sv.begin(), sv.end(), greater_comp<int>());
    printElements(sv);

    // 제거
    // 1. remove 함수가 같은 수를 한곳으로 모아주고, 시작지점과 끝 지점을 리턴한다.
    // 2. erase 함수가 실제로 삭제를 수행한다.
    sv.erase(remove(sv.begin(), sv.end(), 30), sv.end());
    printElements(sv);

    // 제거 2: 람다 함수 활용 - 홀수 지우기
    // 람다는 익명의 함수 객체..
    // 이거도 가능: auto func = [](int i) { return i % 2 == 1; };
    // 이거도 가능: [](int i) { return i % 2 == 1; }(3);
    sv.erase(remove_if(sv.begin(), sv.end(), [](int i) -> bool { return i % 2 == 1; }), sv.end());
    printElements(sv);

    // 전체에 같은 작업 수행
    // 두번째 begin은 저장할 장소..
    transform(sv.begin(), sv.end(), sv.begin(), [](int i) { return i + 1; });
    printElements(sv);

    return 0;
}

/*
데이터의 존재 유무 만 궁금할 경우 → set
중복 데이터를 허락할 경우 → multiset (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))
데이터에 대응되는 데이터를 저장하고 싶은 경우 → map
중복 키를 허락할 경우 → multimap (insert, erase, find 모두 O(\log N)O(logN). 최악의 경우에도 O(\log N)O(logN))
속도가 매우매우 중요해서 최적화를 해야하는 경우 → unordered_set, unordered_map
(insert, erase, find 모두 O(1)O(1). 최악의 경우엔 O(N)O(N) 그러므로 해시함수와 상자 개수를 잘 설정해야 한다!)
*/
