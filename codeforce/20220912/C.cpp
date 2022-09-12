#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
#define R register
typedef unsigned long long ull;
typedef long long ll;

char buf[200010];
int LUT[300];

struct D {
    int val;
    int oidx;

    bool operator<(const struct D& t) const {
        return val < t.val;
    }
} mdata[200010];

int mstack[200010];
int msp;

void qSortIncre(int s, int e, D arr[]) {
    if (s >= e) return;
    int l = s, r = e;
    D pivot = arr[(l+r)>>1];
    
    while (true) {
        while (arr[l] < pivot) ++l;
        while (pivot < arr[r]) --r;
        if (l > r) break;

        D tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;

        ++l; --r;
    }
    qSortIncre(s, r, arr);
    qSortIncre(l, e, arr);
}

void qSortDecre(int s, int e, D arr[]) {
    if (s >= e) return;
    int l = s, r = e;
    D pivot = arr[(l+r)>>1];
    
    while (true) {
        while (pivot < arr[l]) ++l;
        while (arr[r] < pivot) --r;
        if (l > r) break;

        D tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;

        ++l; --r;
    }
    qSortDecre(s, r, arr);
    qSortDecre(l, e, arr);
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");

    for(int i = 'a'; i <= 'z'; ++i) {
        LUT[i] = i - 'a' + 1;
    }

    int tc;
    scanf("%d", &tc);
    for (int TC = 0; TC < tc; TC++) {
        msp = 0;

        scanf("%s", buf);
        int len = strlen(buf);
        for (int i = 0; i < len; ++i) {
            mdata[i] = D{(int)buf[i], i + 1};
        }
        char ref = buf[0];
        int jmpcnt = 0;
        mstack[msp++] = 1;

        if (buf[0] < buf[len-1]) {
            qSortIncre(1,len-2,mdata);
            for(int i = 1; i < len-1; ++i) {
                if (mdata[i].val >= ref && mdata[i].val <= buf[len-1]) {
                    ref = mdata[i].val;
                    mstack[msp++] = mdata[i].oidx;
                }
            }
        } else {
            qSortDecre(1,len-2,mdata);
            for(int i = 1; i < len-1; ++i) {
                if (mdata[i].val <= ref && mdata[i].val >= buf[len-1]) {
                    ref = mdata[i].val;
                    mstack[msp++] = mdata[i].oidx;
                }
            }
        }
        mstack[msp++] = len;
        // for (int i = 0; i < len; ++i) {
        //     printd("%c(%d) %d\n", mdata[i].val, mdata[i].val - 'a' + 1, mdata[i].oidx);
        // }
        printf("%d %d\n", abs(buf[len-1] - buf[0]), msp);
        for(int i = 0; i < msp; ++i) {
            printf("%d ", mstack[i]);
        }
        printf("\n");
    }
MAIN_END
