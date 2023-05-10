#include <stdio.h>

#define MEMO_MAX 20000

int main() {
    int guide_array[MEMO_MAX] = {-1, 1, 7, 19, 37, };

    int N;
    scanf("%d", &N);

    for(int p = 1; p < MEMO_MAX; p++) {
        if (guide_array[p] == 0) {
            guide_array[p] = guide_array[p - 1] + (guide_array[p - 1] - guide_array[p - 2] + 6);
        }
        if (N <= guide_array[p]) {
            printf("%d\n", p);
            break;
        }
    }
    return 0;
}

/*
  1 ==> 1
  diff: 6
  7 ==> 2
  diff: 12
  19 ==> 3
  diff: 18
  37 ==> 4
  ...
*/
