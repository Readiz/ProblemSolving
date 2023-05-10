#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

class DicString {
public:
    char str[52];
    int length;
    DicString(char* mStr) {
        for (int p = 0; ; p++) {
            str[p] = mStr[p];
            if (mStr[p] == 0) {
                length = p;
                break;
            }
        }
    }
    bool operator==(DicString p) {
        if (this->length != p.length) return false;

        for (int i = 0; i < p.length; i++) {
            if (this->str[i] == p.str[i]) continue;
            else return false;
        }
        return true;
    }
    bool operator!=(DicString p) {
        return !(*this == p);
    }
    bool operator<(DicString p) {
        if (this->length != p.length) {
            return this->length < p.length;
        } else {
            for (int i = 0; i < p.length; i++) {
                if (this->str[i] == p.str[i]) continue;
                else return this->str[i] < p.str[i];
            }
            return false;
        }
    }
};

int main() {
    int N;
    scanf("%d", &N);
    vector<DicString> vStrs;

    for (int i = 0; i < N; i++) {
        char str[52];
        scanf("%s", str);
        vStrs.push_back(DicString(str));
    }
    
    sort(vStrs.begin(), vStrs.end());

    for (int i = 0; i < N; i++) {
        if (i == 0 || vStrs[i - 1] != vStrs[i])
            printf("%s\n", vStrs[i].str);
    }
    return 0;
}

/*
문제
알파벳 소문자로 이루어진 N개의 단어가 들어오면 아래와 같은 조건에 따라 정렬하는 프로그램을 작성하시오.

길이가 짧은 것부터
길이가 같으면 사전 순으로
입력
첫째 줄에 단어의 개수 N이 주어진다. (1≤N≤20,000) 둘째 줄부터 N개의 줄에 걸쳐 알파벳 소문자로 이루어진 단어가 한 줄에 하나씩 주어진다. 주어지는 문자열의 길이는 50을 넘지 않는다.

출력
조건에 따라 정렬하여 단어들을 출력한다. 단, 같은 단어가 여러 번 입력된 경우에는 한 번씩만 출력한다.
*/
