#include <stdio.h>

typedef long long ll;
// int main() {

//     int test[5] = {-1, -2};
//     ll* p = (ll*)(&test[0]);

//     printf("%d\n", (int)((*p) & 0xFFFFFFFF));
//     printf("%d\n", (int)((*p) >> 32));

//     return 0;
// }

int main() {

    char test[10] = {-1, -2, 3, 4};
    ll* p = (ll*)(&test[0]); // char: 1byte, ll: 8byte

    printf("%d\n", (char)((*p) & 0xFF)); // 뒤집혀서 읽히기 때문에 이것은 맨 뒤 바이트부터 읽힘


    return 0;
}