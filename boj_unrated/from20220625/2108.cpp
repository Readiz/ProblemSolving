#include <stdio.h>

#define R register
#ifndef ONLINE_JUDGE
#define _D(...) printf(__VA_ARGS__)
#else
#define _D(...)
#endif

int cnt[8001];
int values[500000];
int N;

void quickSort(int s, int e, int arr[]) {
    if (s >= e) return;
    int i = s;
    int j = e;
    int pivot = arr[(s + e) >> 1];

    while (s < e) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i > j) break;
        if (arr[i] != arr[j])
            arr[i] ^= arr[j] ^= arr[i] ^= arr[j];
        i++; j--;
    }

    quickSort(s, j, arr);
    quickSort(i, e, arr);
}

int main() {
    scanf("%d", &N);
    long long mVal = 0LL;
    for (register int i = 0; i ^ N; ++i) {
        int v;
        scanf("%d", &v);
        mVal += v * 10000;
        cnt[v + 4000]++;
        values[i] = v;
    }
    quickSort(0, N - 1, values);
    long long mean = mVal / N;
    int iMean = mean / 10000;
    if (mean > 0) {
        if (mean % 10000 >= 5000) {
            iMean += 1; // 반올림
        }
    } else if (mean < 0) {
        if (mean % 10000 <= -5000) {
            iMean -= 1;
        }
    }
    printf("%d\n", iMean);
    printf("%d\n", values[(N - 1) >> 1]);
    
    int maxCnt = 0;
    int maxVal = -1;
    int maxIdx = -1;
    for (register int i = 0; i <= 8000; ++i) {
        if (cnt[i] > maxVal) {
            maxVal = cnt[i];
            maxIdx = i;
            maxCnt = 1;
        } else if (cnt[i] == maxVal) {
            maxCnt++;
            if (maxCnt == 2) { // 요구사항: 2번째 최소값
                maxIdx = i;
            }
        }
    }
    printf("%d\n", maxIdx - 4000);
    printf("%d\n", values[N - 1] - values[0]);
}