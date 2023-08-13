#include <stdio.h>

int main() {
    unsigned int testVal = 0x7F000000;
    printf("%f\n", testVal);
    unsigned int testVal1 = 0x7F000001;
    printf("%f\n", testVal1);
    unsigned int testVal2 = 0x7F000002;
    printf("%f\n", testVal2);
    unsigned int testVal3 = 0x7F000003;
    printf("%f\n", testVal3);

    float a = 1.0F;
    printf("%x\n", a);
    float b = 0.0F;
    printf("%x\n", b);
}