#include <stdio.h>

int main() {
    int countChar[26] = {0, };
    char str[1000002];

    scanf("%s", str);
    
    // ASCII.. a보다 A가 32만큼 큼. (참고)
    // printf("%d", 'a' - 'A'); -> 32

    for (int ptr = 0; str[ptr] != NULL; ptr++) {
        // Uppercase
        if (str[ptr] >= 'a' && str[ptr] <= 'z')
            str[ptr] -= 32;

        // count
        countChar[str[ptr] - 'A']++;
    }
    
    int max = -1;
    int countIdx = -1;
    for (int i = 0; i < 26; i++) {
        if (countChar[i] > max) {
            max = countChar[i];
            countIdx = i;
        }
            }
    int countMax = 0;
    for (int i = 0; i < 26; i++) {
        if (countChar[i] == max)
            countMax ++;
    }

    if (countMax >= 2)
        printf("?\n");
    else
        printf("%c\n", 'A' + countIdx);
    
    
    return 0;
}

/*
문제
알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.
*/
