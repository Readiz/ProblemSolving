#include <cstdio>

typedef struct pos {
    int x;
    int y;
} Point;

typedef struct name {
    char name[20];
} Name;

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

    return 0;
}
