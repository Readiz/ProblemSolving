#include <stdio.h>

bool is_han(int n) {
    if (n < 100) return true;
    if (n >= 1000) return false;
    int diff1, diff2;
    int n1, n2, n3;
    n1 = n / 100;
    n3 = n % 10;
    n2 = (n - n1 * 100) / 10;
    diff1 = n1 - n2;
    diff2 = n2 - n3;
    if (diff1 == diff2) return true;
    return false;
}

int main() {
    int N, sum = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        if (is_han(i)) sum++;
    }
    printf("%d\n", sum);
    return 0;
}

/*
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 
(N <= 1000)s
*/