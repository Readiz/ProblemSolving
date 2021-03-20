#include <stdio.h>
#ifndef ONLINE_JUDGE
    #define READIZ_DEBUG
#endif
#ifdef READIZ_DEBUG
    #define printd(...) { printf("[DEBUG] "); printf(__VA_ARGS__); printf("\n"); }
    inline void testInit() { freopen("1654_input.txt", "rt", stdin); }
    #define MAIN_START int main(){testInit();while(!feof(stdin)){
    #define MAIN_END } return 0;}
#else
    #define printd(...)
    #define MAIN_START int main(){
    #define MAIN_END return 0;}
#endif
typedef unsigned long long ull;

template <class T>
void SWAP(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// right가 Size가 아님에 주의. 마지막 실제 존재하는 원소를 가리킬 수 있어야 함.
// 즉, quickSort(arr, 0, size - 1); -> arr[0] 와 arr[size - 1] 둘 다 유효해야함.
void quickSort(ull arr[], int left, int right) {
    int i = left;
    int j = right;
    ull pivot = arr[(left + right) / 2];

    while (true) {
        while (arr[i] < pivot) i++; // 좌측포인터를 움직여서 pivot 보다 더 큰놈이 좌측에 있으면, 그 위에서 대기
        while (arr[j] > pivot) j--; // 우측포인터를 움직여서, pivot보다 더 작은놈이 우측에 있으면, 그 위에서 대기
        // i, j 포인터가 엇갈리면, break. 
        if (i > j) break;
        // 엇갈리기 전이면, SWAP을 반복한다.
        SWAP(arr[i], arr[j]);
        i++; j--; // 다음 swap 거리를 찾아보자
    }
    // 엇갈린 기준으로 break 하였으니(좌측은 j, 우측은 i), 엇갈린 기준으로 배열은 분할정복한다.
    if (left < j) quickSort(arr, left, j); // left < j 가 될 때만 quickSort를 반복해야함. (안그러면 무한 재귀 탐)
    if (i < right) quickSort(arr, i, right); // i < right 가 될 때만 quickSort를 반복해야함. (재귀 탈출 조건)
}
// 오름차순 정렬된 배열에서 특정 수 찾기..
// 중복 수는 없다고 가정
int find(ull arr[], int start, int end, ull num) {
    while (end - start >= 0) {
        int mid = start + (end - start) / 2;
        // printd("start: %d, end: %d, mid: %d, key: %d", start, end, mid, num);
        // if (mid - 1 >= 0) printd("%d %d", arr[mid - 1], arr[mid]);
        if (arr[mid] == num) {
            return mid;
        } else if ((mid - 1) >= 0 && arr[mid - 1] < num && arr[mid] > num) {
            return mid;
        } else if (arr[mid] > num) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return 0;
}

MAIN_START
    printd("--------------------------");
    printd("TEST START!!!");

    int K, N;
    scanf("%d %d", &K ,&N);
    printd("K: %d, N: %d", K, N);
    printd("--------------------------");
    ull A[10001] = {0, };
    for (int i = 0; i < K; i++) {
        ull tmp;
        scanf("%llu", &tmp);
        A[i] = tmp;
    }
    quickSort(A, 0, K - 1);

    int pos = K - 1;
    // 길이는 모두 다른 것이 문제에서 보장되어 있음.
    ull length = 0;
    ull maxLength = A[pos]; // 이 값보다 더 큰놈은 없다. (정렬되어 있으니)
    ull minLength = 1;
    printd("maxLength = %llu", maxLength);
    // 각 랜선을 length가 나오게 잘랐을 때 총 개수가 N개가 되면 되는 문제.
    // 타겟으로 하는 A[] 배열의 경우 길이가 그렇게 길지 않기 때문에, 다 돌아도 상관 없다.
    // length의 경우, 21억까지 가능하므로, 이것을 이분 탐색 처리 한다.
    while (minLength <= maxLength) {
        ull midLength = minLength + (maxLength - minLength) / 2;
        printd("min: %llu, mid: %llu, max: %llu", minLength, midLength, maxLength);
        int checkN = 0;
        for (int i = 0; i < K; i++) {
            checkN += A[i] / (int)midLength;
        }
        printd("checkN: %d, N: %d", checkN, N);
        if (checkN >= N) {
            printd("check need to update...");
            if (length < midLength) {
                length = midLength;
                printd("updated, length: %llu", length);
            }
            minLength = midLength + 1;
        } else {
            maxLength = midLength - 1;
        }

    }
    // 아래는 틀린 풀이. 길이 범위가 너무 커서(int, 21억) 하나씩 줄이는 걸로는 한세월임
    // while (true) {
    //     int checkN = 0;
    //     ull mul = length; // 초기 랜선 배수 설정
    //     do {
    //         int minPos = find(A, 0, K - 1, mul);
    //         checkN += K - minPos;
    //         mul += length; 
    //     } while (mul < maxLength);
    //     printd("length: %llu, checkN: %d, targetN: %d", length, checkN, N);
    //     if (checkN >= N) break;
    //     length--;
    //     if (length == 0) {
    //         printd("length is 0.. something is wrong.");
    //         break;
    //     }
    // }
    printf("%llu\n", length);
MAIN_END


/*
랜선 자르기 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	64630	14199	9219	20.277%
문제
집에서 시간을 보내던 오영식은 박성원의 부름을 받고 급히 달려왔다. 박성원이 캠프 때 쓸 N개의 랜선을 만들어야 하는데 너무 바빠서 영식이에게 도움을 청했다.

이미 오영식은 자체적으로 K개의 랜선을 가지고 있다. 그러나 K개의 랜선은 길이가 제각각이다. 박성원은 랜선을 모두 N개의 같은 길이의 랜선으로 만들고 싶었기 때문에 K개의 랜선을 잘라서 만들어야 한다. 예를 들어 300cm 짜리 랜선에서 140cm 짜리 랜선을 두 개 잘라내면 20cm는 버려야 한다. (이미 자른 랜선은 붙일 수 없다.)

편의를 위해 랜선을 자르거나 만들 때 손실되는 길이는 없다고 가정하며, 기존의 K개의 랜선으로 N개의 랜선을 만들 수 없는 경우는 없다고 가정하자. 그리고 자를 때는 항상 센티미터 단위로 정수길이만큼 자른다고 가정하자. N개보다 많이 만드는 것도 N개를 만드는 것에 포함된다. 이때 만들 수 있는 최대 랜선의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 오영식이 이미 가지고 있는 랜선의 개수 K, 그리고 필요한 랜선의 개수 N이 입력된다. K는 1이상 10,000이하의 정수이고, N은 1이상 1,000,000이하의 정수이다. 그리고 항상 K ≦ N 이다. 그 후 K줄에 걸쳐 이미 가지고 있는 각 랜선의 길이가 센티미터 단위의 정수로 입력된다. 랜선의 길이는 231-1보다 작거나 같은 자연수이다.

출력
첫째 줄에 N개를 만들 수 있는 랜선의 최대 길이를 센티미터 단위의 정수로 출력한다.

예제 입력 1 
4 11
802
743
457
539
예제 출력 1 
200
힌트
802cm 랜선에서 4개, 743cm 랜선에서 3개, 457cm 랜선에서 2개, 539cm 랜선에서 2개를 잘라내 모두 11개를 만들 수 있다.
*/
