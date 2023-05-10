// 정수론을 이해하면 아래와 같은 풀이도 가능함...
// 무조건 짝수 / 홀수 쌍에 답이 있으니, 해당 쌍을 먼저 출력 시키고, 나머지 두 수를 소수의 합으로 찾는다.
// from https://www.acmicpc.net/source/9641305

#include <cstdio>
bool p(int x) {
	if (x < 2) return false;
	for (int i = 2; i*i <= x; i++) if (x%i == 0) return false;
	return true;
}
int main() {
	int n;
	while (scanf("%d",&n)==1) {
		if (n < 8) {
			puts("-1");
			continue;
		}
		if (n & 1) {
			n -= 5;
			printf("2 3 ");
		}
		else {
			n -= 4;
			printf("2 2 ");
		}
		if (n == 4) puts("2 2");
		else
		for (int i = 3; i < n; i += 2)
			if (p(i) && p(n - i)) {
				printf("%d %d\n", i, n - i);
				break;
			}
	}
	return 0;
}