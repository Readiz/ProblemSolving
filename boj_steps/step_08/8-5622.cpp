#include <stdio.h>

int main() {

    // printf("%d", 'A'); // 65
    // printf("%d", 'Z'); // 90
    int map_table[91];
    map_table['A'] = 3; map_table['B'] = 3; map_table['C'] = 3;
    map_table['D'] = 4; map_table['E'] = 4; map_table['F'] = 4;
    map_table['G'] = 5; map_table['H'] = 5; map_table['I'] = 5;
    map_table['J'] = 6; map_table['K'] = 6; map_table['L'] = 6;
    map_table['M'] = 7; map_table['N'] = 7; map_table['O'] = 7;
    map_table['P'] = 8; map_table['Q'] = 8; map_table['R'] = 8; map_table['S'] = 8;
    map_table['T'] = 9; map_table['U'] = 9; map_table['V'] = 9;
    map_table['W'] = 10; map_table['X'] = 10; map_table['Y'] = 10; map_table['Z'] = 10;

    char str[16];
    scanf("%s", str);

    int sum = 0;
    for (int ptr = 0; str[ptr] != NULL; ptr++) {
        sum += map_table[str[ptr]];
    }

    printf("%d\n", sum);

    return 0;
}


/*
전화를 걸고 싶은 번호가 있다면, 숫자를 하나를 누른 다음에 금속 핀이 있는 곳 까지 시계방향으로 돌려야 한다. 숫자를 하나 누르면 다이얼이 처음 위치로 돌아가고, 다음 숫자를 누르려면 다이얼을 처음 위치에서 다시 돌려야 한다.

숫자 1을 걸려면 총 2초가 필요하다. 1보다 큰 수를 거는데 걸리는 시간은 이보다 더 걸리며, 한 칸 옆에 있는 숫자를 걸기 위해선 1초씩 더 걸린다.

상근이의 할머니는 전화 번호를 각 숫자에 해당하는 문자로 외운다. 즉, 어떤 단어를 걸 때, 각 알파벳에 해당하는 숫자를 걸면 된다. 예를 들어, UNUCIC는 868242와 같다.

할머니가 외운 단어가 주어졌을 때, 이 전화를 걸기 위해서 필요한 시간을 구하는 프로그램을 작성하시오.
*/
