#include <bits/stdc++.h>
using namespace std;

int main() {
    char buf[10]; scanf("%s", buf);

    switch(buf[0]) {
        case 'M':
        printf("MatKor\n");
        break;
        case 'W':
        printf("WiCys\n");
        break;
        case 'C':
        printf("CyKor\n");
        break;
        case 'A':
        printf("AlKor\n");
        break;
        case '$':
        printf("$clear\n");
        break;
    }

    return 0;
}