#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    bool isDebug = true;
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit(char fbasename[]) {
        char fname[100];
        char* ftailname = "_input.txt";
        int p;
        for (p = 0; fbasename[p] != 0; p++) fname[p] = fbasename[p];
        int t;
        for (t = 0; ftailname[t] != 0; t++) fname[p++] = ftailname[t];
        fname[p] = 0;
        printf("[DEBUG] No Online Judge detected!\n");
        printf("[DEBUG] Trying to use TC file: %s\n", fname);
        freopen(fname, "rt", stdin); 
    }
    #define MAIN_START int main(int a, char* av[]){testInit(av[0]);while(!feof(stdin)){
    #define MAIN_END }return 0;}
#else
    bool isDebug = false;
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;
typedef __int128 lll;

template<class T>
class DArray {
    T* n;
    int capacity;
public:
    int size;
    DArray() {
        n = NULL;
        init();
    }
    void init(int newCap = 100) {
        if (n != NULL) {
            delete[] n;
        }
        size = 0;
        capacity = newCap;
        n = new T[capacity];
    }
    void push(T item) { // call by value..
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
    T& pop() {
        return n[--size];
    }
    T& operator[] (int idx) {
        return n[idx];
    }
    DArray<T>& operator= (DArray<T>& src) {
        this->init();
        for (int i = 0; i < src.size; i++) {
            this->push(src[i]);
        }
        return *this;
    }
    ~DArray() {
        if (n != NULL) {
            delete[] n;
        }
    }
};

// Refer to https://casterian.net/archives/396
ull checker[] = {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL};
ull N;

ull addmod(ull x, ull y, ull m) {
    if (x >= m - y) {
        return x - (m - y);
    } else {
        return x + y;
    }
}
ull mulmod(ull x, ull y, ull m) {
    ull r = 0ULL;
    while (y > 0) {
        if (y % 2 == 1)
            r = addmod(r, x, m);
        x = addmod(x, x, m);
        y /= 2;
    }
    return r;
}

// 빠른 거듭제곱.. (2^N) 을 반복해서 곱하는 방식.
ull powmod(ull x, ull y, ull m) {
    ull r = 1ULL;
    // 이진수 연산한다고 생각.. 2^n 꼴은 자리수 올리고.. 아닌 경우 더하고..
    while (y > 0) {
        if (y % 2 == 1) {
            r = mulmod(r, x, m);
        }
        x = mulmod(x, x, m);
        y /= 2;
    }
    return r;
}

// Miller-Rabin checker
// true를 리턴한다고 해서 무조건 소수인 것은 아님. (확률적 소수)
// 그러나 특정 수들에 대해 (checker 배열) 모두 검사한다면, 확정적으로 소수임을 판별가능.
// (log n)^3 알고리즘
bool MR(ull N, ull A) {
    ull d = N - 1;
    while (d % 2 == 0) {
        if (powmod(A, d, N) == N - 1) {
            return true;
        }
        d /= 2;
    }

    ull tmp = powmod(A, d, N);
    if (tmp == N - 1 || tmp == 1) { // a^(d*2^r) mod n = -1 판정 하는 부분임
        return true;
    } else {
        return false;
    }
}

bool isPrime(ull N) {
    if (N <= 1) {
        return false;
    } else if (N == 2) {
        return true;
    } else if (N <= 10000000000ULL) { // 기존 방법이 빠른 구간 + 밀러라빈 checker 수보다 작은 구간
        for (ull i = 3ULL; i * i <= N; i += 2) { // 홀수만 검사한다.
            if (N % i == 0ULL) return false; // 나누어 떨어지면, 소수
        }
        return true;
    } else {
        for (int i = 0; i < 7; i++) { // 7: checker size
            ull A = checker[i];
            if (MR(N, A) == false) {
                return false;
            }
        }
        return true;
    }
}

ull pseudo_rand(ull start, ull end) {
    static ull seed = 3ULL;
    seed = seed * 214013ULL + 2531011ULL;
    ull r = (seed >> 16) & 0xFFFFFFFFFFFFFFFF;
    r %= end - start;
    return r + start;
}

ull gcd(ull a, ull b) {
    while (b != 0ULL) {
        ull r = a % b;
        a = b;
        b = r;
    }
    return a;
}
ull abssub(ull a, ull b) {
    if (a > b) return a - b;
    return b - a;
}
// pollardRho 합성수 구하기 : O(N^(1/4))
ull PR(ull N) {
    printd("PR: %llu", N);
    if (N == 1) return 1;
    if (N % 2 == 0) return 2;
    if (isPrime(N)) return N;

    ull x = pseudo_rand(2, N);
    ull y = x;
    ull c = pseudo_rand(1, N);
    printd("Rand X: %llu, C: %llu", x, c);
    ull d = 1;
    while (d == 1) {
        // 이 부분에서, ull이 overflow가 나기 때문에, lll(__int128) 비표준을 잠시 사용한다.
        x = (ull)((((lll)x * (lll)x) % N) + c + N) % N;
        y = (ull)((((lll)y * (lll)y) % N) + c + N) % N;
        y = (ull)((((lll)y * (lll)y) % N) + c + N) % N;
        d = gcd(abssub(x, y), N);
        if (d == N) {
            return PR(N);
        }
    }
    if (isPrime(d)) {
        return d;
    } else { // 소수가 아니면, 재귀적으로 반복. (합성수를 리턴하는 것이니) - 이래서 확률적임..
        return PR(d);
    }
}

template <class T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(DArray<ull>& arr) {
    int n = arr.size;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (i == j) continue;
            if (arr[i] < arr[j]) swap(arr[i], arr[j]);
        }
    }
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");
    printd("--------------------------");

    scanf("%llu", &N);
    printd("N: %llu", N);

    DArray<ull> results;
    while (N > 1) {
        ull r = PR(N);
        printd("PR Result: %llu", r);
        results.push(r);
        N /= r;
    }
    bubbleSort(results); // 분해곱 리스트가 크지 않기 때문에 O(n^2) 알고리즘으로도 충분..
    for (int i = 0; i < results.size; i++) {
        printd("%llu", results[i]);
    }

    if (results.size < 2) { // 최소 4개는 있어야.. 구성 가능함
        printf("-1\n");
    } else {
        while (results.size >= 4) {
            printf("%llu ", results.pop() * results.pop());
        }
        ull r = 1;
        while (results.size > 0) {
            r *= results.pop();
        }
        printf("%llu\n", r);
    }
MAIN_END

// 밀러라빈: 확률적 소수판정. 소수가 아닌 case는 완벽하게 알 수 있음.
// 결국 a를 많이 넣어보지 않으면 높은 확률로 틀린다는 건데, n이 작으면 a를 이 정도만 넣어봐도 충분하다고 계산해놓은 게 있습니다. n이 232보다 작은 합성수이면(unsigned int에 저장 가능한 정수라면) a에 2, 7, 61만 넣어봐도 소수로 잘못 판별되는 일이 없다고 합니다. 또, n이 264보다 작은 합성수이면(unsigned long long) a에 2, 325, 9375, 28178, 450775, 9780504, 1795265022만 넣어봐도 충분합니다.
// 폴라드로: 빠른 소인수 분해 방법.

/*
합성인수분해 출처분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초 (추가 시간 없음)	1024 MB	531	108	95	26.611%
문제
소인수분해란 어떤 자연수를 소수의 곱으로 나타내는 것이다. 정수론을 끔찍하게 싫어하는 연두는 소수만 보면 치가 떨려, 대신에 자연수를 합성수의 곱으로 나타내는 “합성인수분해”라는 것을 만들었다.

자연수 의 합성인수분해는 다음의 조건을 모두 만족하는 수열 로 정의한다.

의 모든 원소는 합성수이다. (합성수란 과 자기 자신 이외의 다른 약수를 가지는 정수이다.)
의 모든 원소의 곱은 이다.
하지만 연두는 의 합성인수분해가 여러 개이거나 존재하지 않을 수도 있다는 것을 깨달았다. 연두를 대신해 을 합성인수분해 해주는 프로그램을 만들어보자. 만약 가능한 결과가 여러 개일 경우, 사전 순으로 가장 앞서는 것을 선택해야 한다.

입력
다음과 같이 입력이 주어진다.

 
은 정수다.
출력
의 합성인수분해 중 사전순으로 가장 앞서는 수열의 원소들을 순서대로 공백으로 구분하여 출력한다.

합성인수분해가 불가능하다면 대신에 -1을 출력한다.

예제 입력 1 
3
예제 출력 1 
-1
예제 입력 2 
24
예제 출력 2 
4 6
노트
수열 가 수열 보다 사전 순으로 앞선다는 것의 엄밀한 정의는, 다음 중 하나를 만족한다는 것이다.

이고 인 가 존재한다.
이고 이다.
*/
