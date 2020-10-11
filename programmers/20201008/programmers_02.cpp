#include <string>
#include <vector>
#include <iostream>

using namespace std;


void checkArea(vector<vector<int>>& arr, int x, int y, int step) {
    // 구역을 검사하여 다 같은지 본다.
    int firstVal = arr[x][y];
    // 이미 같은 값으로 정의되어 있는 것이면 return..
    if (firstVal == -1) return;
    
    for (int i = 0; i < step; i++) {
        for (int j = 0; j < step; j++) {
            if (i == 0 && j == 0) continue;
            // 하나라도 처음 값과 다르면 바로 나가기
            if (arr[x + i][y + j] != firstVal) return;
        }
    }
    cout << "All The Same!!!!" << endl;
    // 여기까지 오면 통과한 것 (= 모두 같음)
    for (int i = 0; i < step; i++) {
        for (int j = 0; j < step; j++) {
            if (i == 0 && j == 0) continue;
            arr[x + i][y + j] = -1;
        }
    }
}

vector<int> solution(vector<vector<int>> arr) {
    int size = arr.size();
    
    int step = size;
    int x = 0;
    int y = 0;
    
    while (step > 1) {
        for (int i = 0; i < size; i += step) {
            for (int j = 0; j < size; j += step) {
                cout << "Check... " << i << " " << j << " , step: " << step << endl;
                checkArea(arr, i, j, step);
            }
        }
        step /= 2;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    
    
    int ans0 = 0;
    int ans1 = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i][j] == 0) ans0++;
            if (arr[i][j] == 1) ans1++;
        }
    }
    
    vector<int> answer;
    answer.push_back(ans0);
    answer.push_back(ans1);
    
    return answer;
}
