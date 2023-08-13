#include <bits/stdc++.h>
using namespace std;

struct N {
    char name;
    char l, r;
} n[200];

void dfs1(char c) {
    if (c == '.' || c == 0) return;
    printf("%c", c);
    dfs1(n[c].l);
    dfs1(n[c].r);
}

void dfs2(char c) {
    if (c == '.' || c == 0) return;
    dfs2(n[c].l);
    dfs2(n[c].r);
    printf("%c", c);
}

void dfs3(char c) {
    if (c == '.' || c == 0) return;
    dfs3(n[c].l);
    printf("%c", c);
    dfs3(n[c].r);
}

int main() {
    int N; scanf("%d", &N);
    for(char c = 'A'; c <= 'Z'; ++c) n[c].name = c;
    for(int i = 0; i < N; ++i) {
        char a[2], b[2], c[2];
        scanf("%s %s %s", a, b, c);
        n[a[0]].l = b[0];
        n[a[0]].r = c[0];
    }
    
    dfs1('A');
    printf("\n");
    dfs3('A');
    printf("\n");
    dfs2('A');
    printf("\n");

    return 0;
}