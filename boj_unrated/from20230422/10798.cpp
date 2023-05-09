#include <bits/stdc++.h>
using namespace std;

char buf[5][16];
int main() {
    for(int i = 0; i < 5; ++i) scanf("%s", buf[i]);

    for(int i = 0; i < 15; ++i) {
        for(int j = 0; j < 5; ++j) {
            if (buf[j][i] != 0) printf("%c", buf[j][i]);
        }
    }
    printf("\n");

    return 0;
}