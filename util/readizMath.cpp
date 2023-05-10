#include <stdio.h>
#define PI 3.14159265358979323846

// x_n+1 = 1/2(x_n + a/x_n) 임을 활용 (a: 입력값)
// 반복할 수록 정밀도 높아짐.
int approx_sqrt(int a)
{
    // 자연수만 지원!
    if (a <= 0) return 0;

    int x = 2;
    int x_new;
    for(int i = 0; i < 20; i++) {
        x_new = ( x + ( a / x ) ) / 2;
        if (x_new == x) break;
        x = x_new;
    }
 
    return x;
}

// 반올림
// (sum % N) ? (sum / N) + 1 : (sum / N)

int main() {
    for (int i = 1; i <= 20; i++)
        printf("sqrt(%d) = %d\n", i * i, approx_sqrt(i * i));

    return 0;
}