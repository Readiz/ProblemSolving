#include <bits/stdc++.h>
using namespace std;

int main() {
    set<char> checker;
    checker.insert('M');
    checker.insert('O');
    checker.insert('B');
    checker.insert('I');
    checker.insert('S');
    
    char buf[200];
    scanf("%s", buf);

    for(char* p = buf; *p != 0; ++p) {
        if (checker.find(*p) != checker.end()) checker.erase(*p);
    }

    if (checker.size() == 0) printf("YES\n");
    else printf("NO\n");

    return 0;
}