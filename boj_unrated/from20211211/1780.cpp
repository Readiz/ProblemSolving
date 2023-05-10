#include <stdio.h>

#define printd(...) printf(__VA_ARGS__)
#define R register
int map[3000][3000] = {0,};

int main() {
    int N;
    scanf("%d", &N);
    for (R int i = 0; i < N; i++)
        for (R int j = 0; j < N; j++) 
            scanf("%d", &map[i][j]);

    int num_zero = 0, num_first = 0, num_negfirst = 0;
    for (int cur_size = N; cur_size > 0; cur_size /= 3) {
        printd("------- CUR_SIZE: %d --------\n", cur_size);
        for (int by = 0; by < N; by += cur_size) {
            for (int bx = 0; bx < N; bx += cur_size) {
                printd("--- bx: %d, by: %d\n", bx, by);
                bool allNegFirst = true;
                bool allZero = true;
                bool allFirst = true;
                for (int dy = 0; dy < cur_size; dy++) {
                    for (int dx = 0; dx < cur_size; dx++) {
                        int val = map[by + dy][bx + dx];
                        printd("%d ", val);
                        if (val == 1) {
                            allZero = false;
                            allNegFirst = false;
                        }
                        else if (val == 0) {
                            allFirst = false;
                            allNegFirst = false;
                        }
                        else if (val == -1) {
                            allFirst = false;
                            allZero = false;
                        }
                        else { // 2 case
                            allZero = false; allFirst = false; allNegFirst = false;
                        }
                    }
                    printd("\n");
                }
                if (allZero) {
                    printd("-> This block is all 0!!\n");
                    num_zero++;
                    for (int dy = 0; dy < cur_size; dy++)
                        for (int dx = 0; dx < cur_size; dx++)
                            map[by + dy][bx + dx] = 2;
                } else if (allFirst) {
                    printd("-> This block is all 1!!\n");
                    num_first++;
                    for (int dy = 0; dy < cur_size; dy++)
                        for (int dx = 0; dx < cur_size; dx++)
                            map[by + dy][bx + dx] = 2;
                } else if (allNegFirst) {
                    printd("-> This block is all -1!!\n");
                    num_negfirst++;
                    for (int dy = 0; dy < cur_size; dy++)
                        for (int dx = 0; dx < cur_size; dx++)
                            map[by + dy][bx + dx] = 2;
                }
            }
        }
    }
    printf("%d\n%d\n%d\n", num_negfirst, num_zero, num_first);
    return 0;
}