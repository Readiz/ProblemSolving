#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int solution(int n) {
    long long tmp = 0;
    while (n != 0) {
        tmp += n % 3;
        tmp *= 10;
        n /= 3;
    }
    tmp /= 10;
    
    int answer = 0;
    int multiple = 1;
    while (tmp != 0) {
        int last = tmp % 10;
        answer += last * multiple;
        tmp /= 10;
        multiple *= 3;
    }
    
    return answer;
}