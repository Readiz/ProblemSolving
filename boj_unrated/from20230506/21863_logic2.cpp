#include "21863.cpp"

CUSTOM_BITSET mask[16];
int shift[16] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};

CUSTOM_BITSET add(CUSTOM_BITSET a, CUSTOM_BITSET b) {
    CUSTOM_BITSET sum, carry;
    for(int i = 0; i < 50; ++i) {
        // SUM : XOR
        // CARRY : AND
        sum = a;
        sum ^= b;
        
        carry = a;
        carry &= b;
        carry <<= 1;
        
        a = sum;
        b = carry;
    }
    return sum;
}
bool bInit = false;
void INIT() {
    bInit = true;
    for(int i = 0, step = 1; i < 16; ++i, step *= 2) {
        bool cursor = 0;
        for(int c = 0; c < 65536; ++c) {
            if (c % step == 0) {
                cursor ^= 1;
            }
            // printf("%d", cursor);
            mask[i].setbit(c, cursor);
        }
    }
}

int __builtout_popcount(CUSTOM_BITSET& a) {
    if (!bInit) INIT();

    CUSTOM_BITSET v = a;

    for(int i = 0; i < 16; ++i) {
        CUSTOM_BITSET o1 = v;
        CUSTOM_BITSET o2 = v; o2 >>= shift[i];
        o1 &= mask[i];
        o2 &= mask[i];

        v = add(o1, o2);
    }

    int res = 0;
    int mask = 1;
    for(int i = 0; i < 20; ++i, mask <<= 1) {
        if (v.getbit(i)) res |= mask;
    }

    return res;
}