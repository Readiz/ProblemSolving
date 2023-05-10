#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warning(disable:4996);
int WORD[10][8][8]=
{
	{
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
	},
	{
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
	},
	{
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,1,1,1 },
	},
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0 },
	},
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
	},
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
	},
	{
		{ 1,1,1,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 0,0,0,1,0,0,0,0 },
		{ 1,1,0,1,0,0,0,0 },
		{ 1,0,0,1,0,0,0,0 },
		{ 1,0,0,1,0,0,0,0 },
		{ 1,1,1,1,0,0,0,0 },
	},
	{
		{ 0,0,0,0,1,1,1,1 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,0,0 },
		{ 0,0,0,0,1,0,1,1 },
		{ 0,0,0,0,1,0,0,1 },
		{ 0,0,0,0,1,0,0,1 },
		{ 0,0,0,0,1,1,1,1 },
	},
	{
		{ 0,0,0,0,0,1,0,0 },
		{ 0,0,0,0,0,1,0,0 },
		{ 0,0,0,0,0,1,0,0 },
		{ 0,0,0,0,0,1,0,0 },
		{ 0,0,1,1,1,1,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,1,1,1,1,0,0 },
	},
	{
		{ 0,0,1,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0 },
		{ 0,0,1,0,0,0,0,0 },
		{ 0,0,1,1,1,1,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,1,0,0,1,0,0 },
		{ 0,0,1,1,1,1,0,0 },
	}
};

void makeOriginData(int seed, int originData[16][64])
{
	int rem = 1000, now, sx=0, sy=0;

	for (int i = 0; i < 4; i++)
	{
		sy += rand() % 8;
		sx = rand() % 8;
		now = seed / rem;
		seed %= rem;
		rem /= 10;

		for (int x = sx, ix=0; x < sx + 8; x++, ix++)
		{
			for (int y = sy, iy=0; y < sy + 8; y++, iy++)
			{
				originData[x][y] = WORD[now][ix][iy];
			}
		}
		sy += 8;
	}
}

void decayData(int originData[16][64])
{
	int cha = 0;
	for (int i = 0; i < 16; i++)
		for (int j = 0; j < 64; j++)
			if (rand() % 10 == 4)
				cha++, originData[i][j] = 1 - originData[i][j];

}

extern int getSeed(int originData[16][64]);

int main()
{
	srand(unsigned(time(NULL)));

	int tc = 2000;
	double chk = 0;

	// scanf("%d", &tc);

	for (int i = 1; i <= tc; i++)
	{
		int originData[16][64] = { 0 };

		int seed = rand() % 10000;

		makeOriginData(seed, originData);
		/*
		//print original dataset
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 64; j++)
			{
				printf("%d", originData[i][j]);
			}
			printf("\n");
		}
		printf("----------------------------------------\n");
		
		*/
		decayData(originData);
		/*
		//print decay dataset
		for (int i = 0; i < 16; i++)
		{
			for (int j = 0; j < 64; j++)
			{
				printf("%d", originData[i][j]);
			}
			printf("\n");
		}
		printf("----------------------------------------\n");
		*/
		int userAnswer = getSeed(originData);

		//printf("Answer : %d, user answer : %d\n", seed, userAnswer);
		
		if (seed == userAnswer)
			chk++;
	}
	if (chk / (double)tc >= 0.7)
		printf("1\n");
	else
		printf("0\n");
}

/*
고대 유적지에서 다량의 유적을 발견한 훈이는 그 중에서도 특수한 기호들이 적힌 판에 매우 관심이 생겼다.



국내 연구팀에 연구 결과에 따르면 해당 판에 적혀 있는 기호는 고대 이집트, 그리스가 사용한 것과는 다른 방법의 표기인 숫자인 것으로 밝혀졌다.



게다가 이 고대 문명은 0을 처음 사용했다고 알려진 것보다 훨씬 이전 시대의 문명임에도 0의 개념을 사용하고 있음을 알아내었다.



다음은 고대 연구팀이 알아낸 기수법이다.



□□□□■■■■
□□□□■□□□
□□□□■□□□
□□□□■■■■
□□□□□□□□
□□□□□□□□
□□□□□□□□
□□□□□□□□

□□□□■■■■
□□□□■□□□
□□□□■□□□
□□□□■■■■
□□□□■□□□
□□□□■□□□
□□□□■□□□
□□□□■□□□

□□□□■■■■
□□□□■□□□
□□□□■□□□
□□□□■■■■
□□□□■□□□
□□□□■□□□
□□□□■□□□
□□□□■■■■

■■■■□□□□
□□□■□□□□
□□□■□□□□
■■■■□□□□
□□□□□□□□
□□□□□□□□
□□□□□□□□
□□□□□□□□

■■■■□□□□
□□□■□□□□
□□□■□□□□
■■■■□□□□
□□□■□□□□
□□□■□□□□
□□□■□□□□
□□□■□□□□

0
1
2
3
4
■■■■□□□□
□□□■□□□□
□□□■□□□□
■■■■□□□□
□□□■□□□□
□□□■□□□□
□□□■□□□□
■■■■□□□□

■■■■□□□□
□□□■□□□□
□□□■□□□□
□□□■□□□□
■■□■□□□□
■□□■□□□□
■□□■□□□□
■■■■□□□□

□□□□■■■■
□□□□■□□□
□□□□■□□□
□□□□■□□□
□□□□■□■■
□□□□■□□■
□□□□■□□■
□□□□■■■■

□□□□□■□□
□□□□□■□□
□□□□□■□□
□□□□□■□□
□□■■■■□□
□□■□□■□□
□□■□□■□□
□□■■■■□□

□□■□□□□□
□□■□□□□□
□□■□□□□□
□□■□□□□□
□□■■■■□□
□□■□□■□□
□□■□□■□□
□□■■■■□□

5
6
7
8
9

판에는 4자리의 숫자가 적혀 있었으며, 일부 판들은 대체로 토기 안이나 땅 밑에 묻혀 있어 온전한 형태로 보관되어 있었다.
그러나 대부분의 판들은 훼손이 되어 육안으로는 판별이 힘든 경우가 많았다. 예를 들면 다음과 같다.

원본
□□□□□□□□□□□□□□□□□□■■■■□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□□□■□
□□■□■□□□□□■□□□□■□□■□□■□□□□□□□□□■■■□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■■■■□□■□□■□□□□□■□□□□■□□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■□□□□□□□□■□□■■■■□□■□□□□□□□□■□□□□□□□□□□□□□□□□□□□□■□□■□□□□□□
■□□□□□■□□□□■■□■■□□□□■■□□□□□□□□□□■□□□□□□□□□□□□□□■□□□□□□□□□□□□□■□□
□□□□□□■■□■■□■■■■□□□□□■□□□□□□■□□■□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■□□□□□■□□■□□□□□■□□□□□□□□□□□□□■□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□■■□□□□□■□□■□□□□□■□□□□□□□□□□□□□□□■□□□□■□□□□□□□□□□■□□□□□□■□□□
□□□□□□■□□□□□■■■■□■□□□□□■□□□□□□□□□□■□□■□□□□□□□□□□□■■□□■□■□□□□□□□□
□□□□□□■■■□□□□□□□□□□□□□□□■□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□□□■□□□□□□□□□□□□□□□□□□■■□□□□□■■□■□□□□■□□■□■□□□□□□□□■□□□□□□□
□■□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□□□□□□■□□□□□□□□□□□□■□□■□□□□■□□□□□
■□□□■□□□□□□■□□□□□□□□■■□□□□■□□■□□□□■□□■□□□□□□■□□□■□□□□□□□■□□□□□□□
□■□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□■□■■■□■□■□■□■□□□■□■■□□□■□□□□□□
□□□□□□□□■□□■□□□□□□□□■□□□□□□□□□□□□■□□□■□□□□□□□□□□□□□□□□□□■■■■□□□□
■■□□□□□□□□■□□□■□□□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□

그러나 특수한 장비를 이용하여 복원을 시도하면 원래 적혀있던 숫자를 복원할 수 있음이 확인되었다.
아래는 복원본이다.
복원본

□□□□□□□□□□□□□□□□□□■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□□□□□□□□□□■□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■■■■□□□□□■□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■□□□□□□□□■□□■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■□□□□□□□□■□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■■■■□□■■■■□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■□□□□□■□□■□□□□□■□□□□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■□□□□□■□□■□□□□□■□□□□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■□□□□□■■■■□□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■□□■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□■■■■□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□
□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□

숫자의 위치는 고정되어 있지 않지만 왼쪽에서 오른쪽으로 읽으면 된다. 위와 같은 경우 판에 적혀있던 숫자는 "2848" 이 된다.
하지만 현재 사용하고 있는 장비는 판독 시간도 오래 걸리며 인식률도 현저하게 낮은 상태이다.
훈이는 주어진 훼손된 판의 숫자를 판독하는 프로그램을 직접 제작하여 연구 효율을 올려보기로 결심하였다.
훈이는 최고의 프로그래머인 당신에게 연락하여 이 문제를 논의하였다. 성공할 경우 1비트코인을 받을 수 있다고 하니, 훈이를 도와주러 가즈아!

제약사항

1) 이 문제는 input이 없다.
2) 이 문제는 모든 test case를 전부 맞출 필요가 없다. 총 2000개의 판을 복원 시도할 것이며,  70% 이상 복원 성공시 사용할 수 있는 프로그램으로 간주한다.
3) 제한시간은 10초이다. 주어진 판의 숫자는 절대 겹치지 않으며, 반드시 4자리만 기록되어 있음이 보장되어 있다.
4) main.cpp의 주석을 해제하여 판의 원본 상태, 훼손 상태, 원래 정답, 제출 정답을 확인할 수 있다.
5) user.cpp의 getSeed 함수에서 정답을 제출하면 된다. 입력으로는 훼손된 판이 주어지며, 리턴값으로는 해독한 4자리의 숫자를 리턴하면 된다. 만약 앞 자리에 0이 붙어 있을 경우 표시하지 않아도 된다.(ex : 정답이 "0052" 라면 52를 리턴하면 된다.)
*/