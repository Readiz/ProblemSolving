#include <cstdio>

typedef struct pos {
    int x;
    int y;
} Point;

typedef struct name {
    char name[20];
} Name;

typedef struct arr {
    int a[100];
} Arr;

int main() {
    Point x = {1, 2};
    Point y;
    y = x; // deep copy

    printf("%d, %d\n", x.x, x.y);
    printf("%d, %d\n", y.x, y.y); // Interger is deep copied

    y.x = 3;
    y.y = 4;

    printf("%d, %d\n", x.x, x.y);
    printf("%d, %d\n", y.x, y.y); // Changed only "y"

    Name a = {"Max"};
    Name b;
    b = a; // deep copy

    printf("%s\n", a.name);
    printf("%s\n", b.name); // Max

    // We can use strcpy instead.
    b.name[0] = 'B';
    b.name[1] = 'o';
    b.name[2] = 'b';
    b.name[3] = '\0';

    // We cannot assgin like below:
    // b.name = "Bob";
    
    printf("%s\n", a.name);
    printf("%s\n", b.name); // Bob

    Arr arrA;
    arrA.a[0] = 1;
    arrA.a[1] = 100;
    arrA.a[2] = 45;
    arrA.a[3] = 3;

    Arr arrB = arrA;

    printf("%d\n", arrB.a[0]);
    printf("%d\n", arrB.a[1]);
    printf("%d\n", arrB.a[2]);
    printf("%d\n", arrB.a[3]);

    return 0;
}
