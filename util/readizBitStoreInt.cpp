#include <stdio.h>

// 극단적으로 메모리 소모를 줄여야할때 사용
// vector<bool> 같은거 사용하지 않으면, c++에서 데이터 최소사이즈는 1byte이다.
class BitStore {
    unsigned int *s;
    int collapsedSize;
public:
    BitStore(int size) {
        s = NULL;
        init(size);
    }

    void init(int size) {
        if (s != NULL) delete[] s;
        collapsedSize = (size >> 5) + 1;
        s = new unsigned int[collapsedSize];

        for (int i = 0; i < collapsedSize; i++) {
            s[i] = 0; // 초기화. 32배 빠르지~
        }
    }

    void set(int pos) {
        int bucketPos = pos >> 5;
        int bitwisePos = pos & 0b11111;

        s[bucketPos] |= 1 << bitwisePos;
    }

    void unset(int pos) {
        int bucketPos = pos >> 5;
        int bitwisePos = pos & 0b11111;

        s[bucketPos] &= 0xFFFFFFFF ^ (1 << bitwisePos);
    }

    bool get(int pos) {
        int bucketPos = pos >> 5;
        int bitwisePos = pos & 0b11111;

        return s[bucketPos] & (1 << bitwisePos);
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