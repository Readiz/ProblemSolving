#include <stdio.h>

int main() {

	int a, b; scanf("%d %d", &a, &b);
	int tmp = a * b;
	a *= 100;
	a -= tmp;
	if (a >= 10000) printf("0\n");
	else printf("1\n");
	return 0;
}