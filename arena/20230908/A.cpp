

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;



int main() {
    int a, b, c; scanf("%d%d%d", &a,&b,&c);    
    if (a >= 1000) {
        if (b >= 8000 || c >= 260) {
            printf("Very Good\n");
        } else {
            printf("Good\n");
        }
    } else {
        printf("Bad\n");
    }
    return 0;
}