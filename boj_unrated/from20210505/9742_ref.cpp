// from https://www.acmicpc.net/source/4642565
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, k;
int fact[12];
char str[20];

void f(char *s, int x, int m){
	if(m < 1) return;

	int i = x / fact[m-1], t = s[i]; // 팩토리얼의 각 자리는 바로 계산이 된다.. 참고.
	while(i-- > 0) s[i+1] = s[i]; s[0] = t;

	f(s+1, x % fact[m-1], m-1);
}

int main(){
	fact[0] = 1;
	for(int i = 1; i <= 10; i++)
		fact[i] = fact[i-1] * i;
	while(~scanf("%s %d", str, &k)){
		n = strlen(str); sort(str, str+n);
		printf("%s %d = ", str, k--);
		if(k >= fact[n] || k < 0){
			puts("No permutation");
		}
		else f(str, k, n), puts(str);
	}
}