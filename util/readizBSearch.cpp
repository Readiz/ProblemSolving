#include <stdio.h>

#define printd(...) printf(__VA_ARGS__)
#define R register

// Should be sorted.
int d[10] = {1, 3, 5, 6, 9, 10, 12, 15, 17, 20};
int dSize = 10;

int bSearch(int t) {
    int l = 0;
    int h = dSize - 1; // 실제 ptr로 사용할 수 있는 값이 오는 것이 편리함 (qSort와 동일)

    while (l < h) {
        int m = l + (h - l) / 2;
        printd("d[%d]: %d\n", m, d[m]);
        if (d[m] == t) {
            return m;
        } else if (d[m] < t) {
            l = m + 1;
        } else {
            h = m - 1;
        }
    }
    return -1;
}

/*
이진탐색과 다른점은 크기가 9인  int test1[] = {1,2,2,3,3,3,4,6,7} 이 주어질때 이진탐색은 정확히 같은 값이 있는곳을 찾는거지만
lower bound는 주어진 값보다 같거나 큰 값이 처음으로 나오는걸 리턴해야 하는데,
만약 lower_bound(9) 면 주어진 배열크기 만큼 리턴되어야 하기 때문에 high = array.length -1 이 아니고 high = array.length로 지정 해야 한다. 

그리고 탐색한 값이 주어진 값보다 크거나 같으면 바로 리턴하지 않고, 같거나 처음으로 나오는 값을 찾기위해 범위를 더 좁히면서 찾아간다. 
예를들어 test1 에서 lower_bound(3) 을 호출하면 
{1,2,2,3, 3 <- array[mid]는 여기를 가리킴.,3,4,6,7}
하지만 우리가 찾으려 하는 index 는 처음 mid = 4 가 아닌  mid=3 이어야 한다.
따라서 크거나 같은경우 high = mid 로 지정해서 범위를 좀더 좁혀 나가면서 찾아가는 것이다. 
*/
int lowerBound(int t) {
    int l = 0;
    int h = dSize; // 실제 ptr로 사용할 수 있는 값이 오는 것이 편리함 (qSort와 동일)

    while (l < h) {
        int m = l + (h - l) / 2;
        printd("d[%d]: %d\n", m, d[m]);
        if (d[m] >= t) {
            h = m;
        } else {
            l = m + 1;
        }
    }
}

/*
lower bound와 마찬가지로 upper bound는 주어진 값보다  큰 값이 처음으로 나오는걸 리턴해야 함
만약 upper_bound(max_element) 면 주어진 배열크기 만큼 리턴되어야 하기 때문에 high = array.length -1 이 아니고 high = array.length로 지정 해야 한다. 
그리고 탐색한 값이 주어진 값보다 크다면  바로 리턴하지 않고 최초로 큰 값이 있는 위치를  찾기 위해 high = mid 지정하여 범위를 더 좁히면서 찾아가면 된다. 
*/

int upperBound(int t) {
    int l = 0;
    int h = dSize; // 실제 ptr로 사용할 수 있는 값이 오는 것이 편리함 (qSort와 동일)

    while (l < h) {
        int m = l + (h - l) / 2;
        printd("d[%d]: %d\n", m, d[m]);
        if (d[m] > t) {
            h = m;
        } else {
            l = m + 1;
        }
    }
}

int main() {
    printd("BSearch(15): %d\n", bSearch(15));
    printd("BSearch(16): %d\n", bSearch(16));
    printd("LBound(15): %d\n", lowerBound(15));
    printd("LBound(16): %d\n", lowerBound(16));
    printd("UBound(15): %d\n", upperBound(15));
    printd("UBound(16): %d\n", upperBound(16));
}