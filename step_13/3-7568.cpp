#include <stdio.h>

int weight[200];
int height[200];
int maxIndex = 0;
int rank[200];

enum CompareResult {
    notDefined = 0,
    targetIsBigger = 1,
    sourceIsBigger = 2
};

// return true when target is bigger then source
CompareResult compare(int source, int target) {
    if (weight[source] < weight[target] &&
        height[source] < height[target]) {
        return targetIsBigger;
    } else if (weight[source] > weight[target] &&
        height[source] > height[target]) {
        return sourceIsBigger;
    }
    return notDefined;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &weight[i], &height[i]);
        if (i != 0) {
            if(compare(maxIndex, i) == targetIsBigger) {
                maxIndex = i;
            }
        }
    }
    
    int rankDefined = 0;
    for (int i = 0; i < N; i++) {
        int myRank = 1; // 처음에 1위라고 가정
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (compare(i, j) == targetIsBigger) {
                myRank++;
            }
        }
        rank[i] = myRank;
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", rank[i]);
    }
    printf("\n");
    
    return 0;
}

/*
입력
첫 줄에는 전체 사람의 수 N이 주어진다. 그리고 이어지는 N개의 줄에는 각 사람의 몸무게와 키를 나타내는 양의 정수 x와 y가 하나의 공백을 두고 각각 나타난다. 단, 2 ≤ N ≤ 50, 10 ≤ x,y ≤ 200 이다.

출력
여러분은 입력에 나열된 사람의 덩치 등수를 구해서 그 순서대로 첫 줄에 출력해야 한다. 단, 각 덩치 등수는 공백문자로 분리되어야 한다.
*/
