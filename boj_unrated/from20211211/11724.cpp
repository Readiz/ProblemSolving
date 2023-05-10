#include <stdio.h>

#define printd(...) printf(__VA_ARGS__)
#define R register

bool m[1001][1001] = {false, }; // 연결관계
bool visited[1001] = {false, };
int N, M;

void check(int i) {
    for (int j = 1; j <= N; j++) {
        if (visited[j] || (i == j)) continue;
        if (m[i][j]) {
            visited[j] = true;
            check(j);
        }
    }
}
int main() {
    scanf("%d %d", &N, &M);
    
    for (R int i = 0; i < M; i++) {
        int p, q;
        scanf("%d %d", &p, &q);
        m[p][q] = true;
        m[q][p] = true;
    }

    int connected = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i] == true) continue;
        visited[i] = true;
        check(i);
        connected++;
    }

    printf("%d\n", connected);

    return 0;
}