template <class T>
void SWAP(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

// right가 Size가 아님에 주의. 마지막 실제 존재하는 원소를 가리킬 수 있어야 함.
// 즉, quickSort(arr, 0, size - 1); -> arr[0] 와 arr[size - 1] 둘 다 유효해야함.
template <class T>
void quickSort(T arr[], int left, int right) {
    int i = left;
    int j = right;
    T pivot = arr[(left + right) / 2];

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

template <class T>
void inverse(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        SWAP(arr[i], arr[size - i - 1]);
    }
}

class ResultDataManager {
    char data[10000][20] = {0, };
    int pos = -1;
    int charPos;
public:
    void startNewData() {
        pos++;
        charPos = 0;
    }
    void addChar(char a) {
        data[pos][charPos++] = a;
    }
    void printResult() {
        for (int i = 0; i <= pos; i++) {
            printf("%s\n", data[i]);
        }
    }
};
ResultDataManager myResultDataManager;

class Stack {
    int size = 0;
    char data[20] = {0, };
public:
    void push(char d) {
        data[size++] = d;
    }
    char pop() {
        return data[--size];
    }
    void addDataToManager() {
        myResultDataManager.startNewData();
        for (int i = 0; i < size; i++) {
            myResultDataManager.addChar(data[i]);
        }
    }
};
Stack myStack;
