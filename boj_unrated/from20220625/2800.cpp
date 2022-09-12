#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) // printf(__VA_ARGS__)
#else
#define _D(...)
#endif
char str[201];
int l;
bool isFirst = true;
void print() {
    if (isFirst) {
        isFirst = false;
        return;
    }
    for (R int i = 0; i < l; ++i) {
        if (str[i] != '<' && str[i] != '>')
        printf("%c", str[i]);
    }
    printf("\n");
}
void dfs(int s) {
    _D("DFS(%d)\n", s);
    int r = 0;
    int k = 0;
    int e = -1;
    for (int p = s + 1; p < l; ++p) {
        if (str[p] == '(' || str[p] == '<') r++;
        else if (str[p] == ')' || str[p] == '>') {
            if (k == r) {
                e = p;
                break;
            }
            k++;
        } 
    }
    if (e != -1) {
        int ns = -1;
        for (int p = s + 1; p < l; ++p) {
            if (str[p] == '(' || str[p] == '<') {
                ns = p;
                break;
            }
        }
        if (ns != -1) {
            dfs(ns);
            str[s] = '<';
            str[e] = '>';
            dfs(ns);
            str[s] = '(';
            str[e] = ')';
        } else {
            print();
            str[s] = '<';
            str[e] = '>';
            print();
            str[s] = '(';
            str[e] = ')';
        }
    } else {
        _D("ERR!");
    }
}

int main() {
    scanf("%s", str);
    for (l = 0; str[l]; ++l);
    _D("l: %d\n", l);
    int s = -1;
    for (int p = 0; p < l; ++p) {
        if (str[p] == '(') {
            s = p;
            break;
        }
    }
    if (s != -1) {
        int r = 0;
        int k = 0;
        int e = -1;
        for (int p = s + 1; p < l; ++p) {
            if (str[p] == '(' || str[p] == '<') r++;
            else if (str[p] == ')' || str[p] == '>') {
                if (k == r) {
                    e = p;
                    break;
                }
                k++;
            } 
        }
        dfs(s);
        // str[s] = '<';
        // str[e] = '>';
        // _D("------\n");
        // dfs(s);
        // str[s] = '(';
        // str[e] = ')';
    }
}