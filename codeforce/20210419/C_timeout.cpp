#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("C_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef long long ll;

template<class T>
class DArray {
    T* n;
    int capacity;
public:
    int size;
    DArray() {
        size = 0;
        capacity = 100;
        n = new T[capacity];
    }
    void push(T item) {
        // 공간 다 찼을 경우.. 늘린다.
        if (size == capacity) {
            capacity *= 2; // 두배로 늘린다.
            T* newNodes = new T[capacity];
            for (int i = 0; i < size; i++) {
                newNodes[i] = n[i]; // 기존 값 복사
            }
            delete[] n;
            n = newNodes;
        }
        n[size++] = item;
    }
    T pop() {
        return n[--size];
    }
    T& operator[] (int idx) {
        return n[idx];
    }
    ~DArray() {
        delete[] n;
    }
};

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");
    ull n;
    scanf("%llu", &n);
    printd("N: %llu\n-------------------------------", n);

    if (n < 5 || n == 6) printf("1\n1\n");
    else {
        // n * k + 1 꼴의 수로 계속해서 시도한다.
        ull k = 1ULL;
        while (true) {
            ull t = n * k + 1;
            // printd("trying %llu * %llu + 1 => %llu...", n, k, t);
            DArray<ull> s;
            bool success = false;
            for (ull i = 1; i < n; i++) {
                if (t % i == 0) {
                    s.push(i);
                    t /= i;
                    if (t == 1) {
                        success = true;
                        break;
                    }
                }
            }
            if (success) {
                printd("%llu => One of the combination is found!", n * k + 1);
                printf("%d\n", s.size);
                for (int i = 0; i < s.size; i++) {
                    printf("%d ", s[i]);
                }
                printf("\n");
                // break;
            } else {
                // 종료 조건 확인. 남겨진 녀석이 마지막 원소보다 크고, n보다 크거나 같으면 종료.
                // if (t > s[s.size - 1] && t >= n) {
                //     printd("Last element: %llu > %llu, break!", t, n);
                //     break;
                // }
            }

            k++;
            if (k > 1000000000ULL) break;
        }
    }

MAIN_END
