#include <stdio.h>

int main() {
    char str[105] = { 0, };
    scanf("%s", str);
    
    int count = 0;
    for (int ptr = 0; str[ptr] != NULL; ptr++) {
        if (str[ptr] == 'c' && str[ptr + 1] == '=') ptr++;
        if (str[ptr] == 'c' && str[ptr + 1] == '-') ptr++;
        if (str[ptr] == 'd' && str[ptr + 1] == 'z' && str[ptr + 2] == '=') ptr+=2;
        if (str[ptr] == 'd' && str[ptr + 1] == '-') ptr++;
        if (str[ptr] == 'l' && str[ptr + 1] == 'j') ptr++;
        if (str[ptr] == 'n' && str[ptr + 1] == 'j') ptr++;
        if (str[ptr] == 's' && str[ptr + 1] == '=') ptr++;
        if (str[ptr] == 'z' && str[ptr + 1] == '=') ptr++;
        count ++;
    }

    printf("%d\n", count);
    return 0;
}

/*
크로아티아 알파벳	변경
č	c=
ć	c-
dž	dz=
đ	d-
lj	lj
nj	nj
š	s=
ž	z=
*/
