#include <stdio.h>
#define SWAP(a,b,type)do{type temp;temp=a;a=b;b=temp;}while(0)

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a > b) SWAP(a, b, int);
    if (b > c) SWAP(b, c, int);
    if (a > b) SWAP(a, b, int);
    printf ("%d\n", b);

    return 0;
}
/*
세 정수 A, B, C가 주어진다. 이때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 
*/