#include <bits/stdc++.h>
using namespace std;

int main() {
    char buf[100];
    char value[5];
    double multiple;
    double multipleSum = 0.;
    double valueSum = 0.;
    while (scanf("%s %lf %s", buf, &multiple, value) != EOF) {
        if (value[0] == 'P') continue;
        multipleSum += multiple;
        if (value[0] == 'A') {
            if (value[1] == '+') valueSum += 4.5 * multiple;
            else                 valueSum += 4.0 * multiple;
        } else if (value[0] == 'B') {
            if (value[1] == '+') valueSum += 3.5 * multiple;
            else                 valueSum += 3.0 * multiple;
        } else if (value[0] == 'C') {
            if (value[1] == '+') valueSum += 2.5 * multiple;
            else                 valueSum += 2.0 * multiple;
        } else if (value[0] == 'D') {
            if (value[1] == '+') valueSum += 1.5 * multiple;
            else                 valueSum += 1.0 * multiple;
        }
    }

    printf("%lf\n", valueSum / multipleSum);



    return 0;
}