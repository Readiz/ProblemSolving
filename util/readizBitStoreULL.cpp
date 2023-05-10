#include <stdio.h>

typedef unsigned long long ull;

// 극단적으로 메모리 소모를 줄여야할때 사용
// vector<bool> 같은거 사용하지 않으면, c++에서 데이터 최소사이즈는 1byte이다.
class BitStore {
    ull *s;
    int collapsedSize;
public:
    BitStore(int size) {
        s = NULL;
        init(size);
    }

    void init(int size) {
        if (s != NULL) delete[] s;
        collapsedSize = (size >> 6) + 1;
        s = new ull[collapsedSize];

        for (int i = 0; i < collapsedSize; i++) {
            s[i] = 0ULL; // 초기화. 64배 빠르지~
        }
    }

    void set(int pos) {
        int bucketPos = pos >> 6;
        int bitwisePos = pos & 0b111111;

        s[bucketPos] |= 1ULL << bitwisePos;
    }

    void unset(int pos) {
        int bucketPos = pos >> 6;
        int bitwisePos = pos & 0b111111;

        s[bucketPos] &= (~0ULL) ^ (1ULL << bitwisePos);
    }

    bool get(int pos) {
        int bucketPos = pos >> 6;
        int bitwisePos = pos & 0b111111;

        return s[bucketPos] & (1ULL << bitwisePos);
    }

    ~BitStore() {
        delete[] s;
    }
};

int main() {
    BitStore bStore(40000);

    bStore.set(1);
    bStore.set(2);
    bStore.set(3);

    printf("------------- Set Test --------------\n");
    printf("%d\n", bStore.get(0));
    printf("%d\n", bStore.get(1));
    printf("%d\n", bStore.get(2));
    printf("%d\n", bStore.get(3));


    bStore.unset(2);

    printf("------------- Unset Test --------------\n");
    printf("%d\n", bStore.get(0));
    printf("%d\n", bStore.get(1));
    printf("%d\n", bStore.get(2));
    printf("%d\n", bStore.get(3));


    bStore.set(20000);
    bStore.set(20003);

    printf("------------- Large Pos Test --------------\n");
    printf("%d\n", bStore.get(20000));
    printf("%d\n", bStore.get(20001));
    printf("%d\n", bStore.get(20002));
    printf("%d\n", bStore.get(20003));

    bStore.unset(20003);
    printf("------------- Large Pos Unset Test --------------\n");
    printf("%d\n", bStore.get(20003));

}