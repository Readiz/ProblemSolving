// from https://www.acmicpc.net/source/23712110
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <iostream>
using namespace std;

class Pair {

public:
	long long first;
	long long second;
	long long breakWall;

};

#define H_ 1002
#define W_ 1002
#define Margin 1
#define H (H_ + Margin + Margin)
#define W (W_ + Margin + Margin)

char mapData__[H * W];
char *mapData_[H];
char **mapData;

long long n, m;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long i, j;

	mapData = mapData_ + Margin;
	for (i = 0; i < H; i++) {
		mapData_[i] = mapData__ + Margin + i * W;
	}

	cin >> n >> m;

	for (i = 0; i < n; i++) {
		cin >> mapData[i];
	}

	for (i = 0; i < n; i++) {
		mapData[i][-1] = 3; // 이게 왜 딱히 에러가 안나는지는 잘 모르겠음..
		mapData[i][m] = 3;
	}

	for (j = 0; j < m; j++) {
		mapData[-1][j] = 3;
		mapData[n][j] = 3;
	}

	Pair q[2050];
	long long qLeft = 0;
	long long qRight = 1;
	long long qFRight;

	q[0].first = 0;
	q[0].second = 0;
	q[0].breakWall = 0;

	long long cnt = 1;

	long long d;
	long long dy[4] = { 0, 0, 1, -1 };
	long long dx[4] = { 1, -1, 0, 0 };

	while (qLeft != qRight) {

		qFRight = qRight;

		while (qLeft != qFRight) {

			long long first = q[qLeft].first;
			long long second = q[qLeft].second;
			long long breakWall = q[qLeft].breakWall;

			if (first == n - 1 && second == m - 1) {
				cout << cnt;
				return 0;
			}

			for (d = 0; d < 4; d++) {

				long long nextY = first + dy[d];
				long long nextX = second + dx[d];

				// '0' : 벽 없음
				// '1' : 벽 있음
				// 2 : 벽을 부순 상태로 다녀감
				// 3 : 벽을 부수지 않은 상태로 다녀감.
				char& cData = mapData[nextY][nextX];

				if (cData == '0') {

					if (breakWall == 0) {
						q[qRight].first = nextY;
						q[qRight].second = nextX;
						q[qRight].breakWall = 0;
						qRight++;
						qRight &= ~2048; // 순환시킴. 대충 queue 맥스값이 2048 보다 작다고 하고 푼 것

						cData = 3;
					} else {
						q[qRight].first = nextY;
						q[qRight].second = nextX;
						q[qRight].breakWall = 1;
						qRight++;
						qRight &= ~2048;

						cData = 2;
					}

				} else if (cData == '1') {

					if (breakWall == 0) {
						q[qRight].first = nextY;
						q[qRight].second = nextX;
						q[qRight].breakWall = 1;
						qRight++;
						qRight &= ~2048;

						cData = 3;
					}
				} else if (cData == 2) {

					if (breakWall == 0) {
						q[qRight].first = nextY;
						q[qRight].second = nextX;
						q[qRight].breakWall = 0;
						qRight++;
						qRight &= ~2048;

						cData = 3;
					}

				}

			}

			qLeft++;
			qLeft &= ~2048;

		}

		cnt++;

	}

	cout << "-1";

}