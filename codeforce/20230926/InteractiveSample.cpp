// #include <cstdio>
// #include <cstring>

// using namespace std;

// int main() {
//     int l = 1, r = 1000000;
//     while (l != r) {
//         int mid = (l + r + 1) / 2;
//         printf("%d\n", mid);
//         fflush(stdout);

//         char response[3];
//         scanf("%s", response);
//         if (strcmp(response, "<") == 0)
//             r = mid - 1;
//         else
//             l = mid;
//     }

//     printf("! %d\n", l);
//     fflush(stdout);
// }

#include <cstdio>
#include <cstring>

using namespace std;

int N;
int a[200010];
long long s[200010];
int response;
void solve() {
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &a[i]);
    }
    fflush(stdout);
    for(int i = 1; i <= N; ++i) {
        s[i] = s[i - 1] + a[i]; // expected
    }
    int l = 1, r = N;
    while (l < r) {
        int mid = (l + r) / 2;

        if (mid - l + 1 >= 1) {
            // 왼쪽 검사
            printf("? ");
            printf("%d ", mid - l + 1);
            for(int i = l; i <= mid; ++i) {
                printf("%d ", i);
            }
            printf("\n");
            fflush(stdout);

            scanf("%d", &response);
            if (response != s[mid] - s[l - 1]) {
                if (mid - l + 1 == 1) {
                    printf("! %d\n", mid);
                    fflush(stdout);
                    return;
                }
                r = mid;
                continue;
            } else {
                l = mid + 1;
                continue;
            }
        }

        if (r - mid >= 1) {
            // 오른쪽 검사
            printf("? ");
            printf("%d ", r - mid);
            for(int i = mid + 1; i <= r; ++i) {
                printf("%d ", i);
            }
            printf("\n");
            fflush(stdout);

            scanf("%d", &response);
            if (response != s[r] - s[mid]) {
                if (r - mid == 1) {
                    printf("! %d\n", mid + 1);
                    fflush(stdout);
                    return;
                }
                l = mid + 1;
            } else {
                r = mid;
            }
        }
    }
    // something is wrong ?
    printf("! %d\n", l);
    fflush(stdout);
    return;
}


int main() {
    int TC;
    scanf("%d", &TC);
    fflush(stdout);
    while(TC--) {
        solve();
    }
}