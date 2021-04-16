// from https://www.acmicpc.net/source/share/23759948e0ff471db6577461b38bcd0c

///EVERYONE BELIEVE IN GODTAEGYU
#include<bits/stdc++.h>
using namespace std;
int n, m, i, j, k;

char buffer[40];
void print_uint128(unsigned __int128 x, int n = 0) {
	memset(buffer, '0', sizeof(buffer));
	char *p = buffer + 39;

	*p = 0;
	do {
		*(--p) = "0123456789"[x % 10];
	} while (x /= 10);

	if (n) {
		printf("%s", buffer + 39 - n);
	}
	else {
		printf("%s", p);
	}
}

char input[300001];
unsigned __int128 A[18141], B[18141], P[36141], tmp;
int main() {
	// 자연수 A 입력
	scanf("%s", input);
	int L = strlen(input), LevelA = 0, LevelB = 0, LevelP;
	long long step = 1;
	if (L == 1 && input[0] == '0')
	{
		printf("0");
		return 0;
	}
	for (int i = L - 1; i >= 0; i--)
	{
		if (step == 100000000000000000)
		{
			LevelA++;
			step = 1;
		}
		A[LevelA] += (input[i] - '0') * step;
		step *= 10;
	}

	// 자연수 B 입력
	scanf("%s", input);
	L = strlen(input), step = 1;
	if (L == 1 && input[0] == '0')
	{
		printf("0");
		return 0;
	}
	for (int i = L - 1; i >= 0; i--)
	{
		if (step == 100000000000000000)
		{
			LevelB++;
			step = 1;
		}
		B[LevelB] += (input[i] - '0') * step;
		step *= 10;
	}

	// 곱셈 ㄱㄱ
	// A[i]에 들어있는 정수(0~99999999999999999)는 10^17i만큼의 자릿값을 가지는 수를 의미함.
	// 울프람피셜 오버플로 안 나는 자릿값의 한계선은 17.
    //   input      2^128 > 10^(2x) * (300000 / x)
    //   solution   8.81621*10^-34 < x < 17.1444
	LevelP = LevelA + LevelB;
	for (int i = 0; i <= LevelA; i++)
		for (int j = 0; j <= LevelB; j++)
			P[i + j] += A[i] * B[j];

	// 자릿수 올림 처리
	for (int i = 0; i < LevelP; i++)
	{
		tmp = P[i] / 100000000000000000;
		if (tmp > 0)
		{
			P[i + 1] += tmp;
			P[i] -= tmp * 100000000000000000;
		}
	}

	// 출력
	print_uint128(P[LevelP]);
	for (int i = LevelP - 1; i >= 0; i--)
		print_uint128(P[i], 17);

	return 0;
}


/* 큰 수 곱셈 3 
FFT 의도 문제이지만, __uint128로 풀림..

*/
