#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif
#define FOR(i,a,b) for(R int i=(a);((i)^(b));++i)

#include <string.h>

int cnt;
int recursion(char *s, int l, int r){
    ++cnt;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(char *s){
    return recursion(s, 0, strlen(s)-1);
}

int N;
char buf[1010];
int main() {
    scanf("%d", &N);
    FOR(i,0,N) {
        scanf("%s", buf);
        cnt = 0;
        int r = isPalindrome(buf);
        printf("%d %d\n", r, cnt);
    }
}