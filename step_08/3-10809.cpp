#include <stdio.h>

int main() {
    int alpha_pos[26];
    for (int i = 0; i < 'z' - 'a' + 1; i++)
        alpha_pos[i] = -1;

    char word[102] = {0, };
    scanf("%s", word);

    int ptr = 0;
    while (word[ptr] != 0) {
        // printf("%c\n", word[ptr]);
        if (alpha_pos[word[ptr] - 'a'] == -1)
            alpha_pos[word[ptr] - 'a'] = ptr;
        ptr++;
    }
    
    for (int i = 0; i < 'z' - 'a' + 1; i++) {
        printf("%d ", alpha_pos[i]);
    }
    printf("\n");
    
    return 0;
}


/*
알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
*/
