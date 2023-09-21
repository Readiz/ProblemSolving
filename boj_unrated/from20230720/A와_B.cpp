#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

char buf1[1010], buf2[1010];
int main() {
    scanf("%s %s", buf1, buf2);
    int len1 = strlen(buf1), len2 = strlen(buf2);
    bool isReversed = false;
    int l = 0;
    int r = len2 - 1;
    while((r - l + 1) > len1) {
        if (isReversed == false) {
            if (buf2[r] == 'A') {
                --r;
            } else if (buf2[r] == 'B') {
                isReversed = true;
                --r;
            } else {
                printf("0\n");
                return 0;
            }
        } else {
            if (buf2[l] == 'A') {
                ++l;
            } else if (buf2[l] == 'B') {
                isReversed = false;
                ++l;
            } else {
                printf("0\n");
                return 0;
            }
        }
    }
    // 길이가 같다
    bool isSame = true;
    if (isReversed) {
        for(int i = r, j = 0; i >= l; --i, ++j) {
            if (buf1[j] == buf2[i]) continue;
            isSame = false;
            break;
        }
    } else {
        for(int i = l, j = 0; i <= r; ++i, ++j) {
            if (buf1[j] == buf2[i]) continue;
            isSame = false;
            break;
        }
    }
    if (isSame) printf("1\n");
    else printf("0\n");

    return 0;
}