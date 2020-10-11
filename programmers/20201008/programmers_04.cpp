#include <string>
#include <vector>
#include <iostream>
using namespace std;

int findBeauty(string s) {
    int leftMax = -1;
    int rightMax = -1;
    int size = s.size();
    
    // 바로 끝나는거 찾기
    if (size == 1) return 0;
    string startChar = s.substr(0, 1);
    string endChar = s.substr(size - 1, 1);
    if (startChar != endChar) {
        return size - 1;
    }
    
    // 왼쪽의 max 찾기
    string leftMost = s.substr(0, 1);
    int rightPos = size - 1;
    while (rightPos > 0) {
        string curRightChar = s.substr(rightPos, 1);
        if (leftMost == curRightChar) {
            rightPos--;
            continue;
        }
        leftMax = rightPos;
        break;
    }
    
    // 오른쪽의 max 찾기
    string rightMost = s.substr(size - 1, 1);
    int leftPos = 0;
    while (leftPos < size - 1) {
        string curLeftChar = s.substr(leftPos, 1);
        if (rightMost == curLeftChar) {
            leftPos++;
            continue;
        }
        rightMax = leftPos;
        break;
    }
    
    // 최종 결과
    if (leftMax == -1 && rightMax == -1) return 0;
    if (leftMax > rightMax) return leftMax;
    return rightMax;
}

long long solution(string s) {
    long long answer = 0;
    int size = s.size();
    int startPos = 0;
    
    while (startPos < size) {
        for (int endPos = startPos + 1; endPos <= size; endPos++) {
            string substr = s.substr(startPos, endPos - startPos);
            cout << substr << ", ANS: " << findBeauty(substr) << endl;
            answer += findBeauty(substr);
        }
        startPos++;
    }
    
    
    return answer;
}