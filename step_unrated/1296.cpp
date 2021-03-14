#include <stdio.h>
#define MAX(a, b) (a) > (b) ? (a): (b)
#define MIN(a, b) (a) < (b) ? (a): (b)

int N;
char myname[21] = {0, };
char names[50][21] = {0, };
int baseL = 0, baseO = 0, baseV = 0, baseE = 0;
int numChar(char str[], char a) {
    int r = 0;
    for (int p = 0; str[p] != 0; p++) {
        if (str[p] == a) r++;
    }
    return r;
}
int len(char s[]) {
    int p;
    for (p = 0; s[p] != 0; p++);
    return p;
}

// a가 b보다 사전순으로 앞서면 true
bool compareChars(char a[], char b[]) {
    int sLen = MIN(len(a), len(b));
    for (int p = 0; p < sLen; p++) {
        if (a[p] < b[p]) { // a가 더 앞섬
            return true;
        } else if(a[p] > b[p]) {
            return false;
        }
    }
    if (len(a) > len(b)) {
        return false;
    } else if (len(a) == len(b)) {
        return true; // 둘아 같아도 true
    } else {
        return true;
    }
}

int main() {
    scanf("%s", myname);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", names[i]);
    }
    baseL = numChar(myname, 'L');
    baseO = numChar(myname, 'O');
    baseV = numChar(myname, 'V');
    baseE = numChar(myname, 'E');

    int scores[50] = {0, };
    for (int i = 0; i < N; i++) {
        int L = baseL + numChar(names[i], 'L');
        int O = baseO + numChar(names[i], 'O');
        int V = baseV + numChar(names[i], 'V');
        int E = baseE + numChar(names[i], 'E');
        scores[i] = ((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E)) % 100;
    }
    int max = -1;
    int maxIdx = -1;
    for (int i = 0; i < N; i++) {
        if (max < scores[i]) {
            max = scores[i];
            maxIdx = i;
        }
        else if (max == scores[i]) { // 사전 순보다 앞서면 업데이트
            if (compareChars(names[i], names[maxIdx])) {
                max = scores[i];
                maxIdx = i;
            }
        }
    }
    printf("%s\n", names[maxIdx]);

    return 0;
}


/*
데이트 분류
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	1710	602	533	39.569%
문제
오민식은 자기가 좋아하는 여자 N명 중에 한 명과 함께 데이트하러 나가고 싶어한다.

하지만 N명 모두를 사랑하는 오민식에게는 한 명을 선택하고 나머지 여자를 버리는 것은 슬픈 결정이기 때문에 누구를 선택해야 할지 고민에 빠졌다.

마침 오민식은 사랑계산기를 얻었다. 사랑계산기는 두 사람의 이름을 이용해서 두 사람이 성공할 확률을 계산해 준다. 사랑계산기는 다음과 같이 작동한다.

L = 두 사람 이름에서 등장하는 L의 개수
O = 두 사람 이름에서 등장하는 O의 개수
V = 두 사람 이름에서 등장하는 V의 개수
E = 두 사람 이름에서 등장하는 E의 개수
위의 개수를 모두 계산 한 후에 확률 계산은 다음과 같이 한다.

((L+O)*(L+V)*(L+E)*(O+V)*(O+E)*(V+E)) mod 100

오민식의 영어 이름과 나머지 여자들의 이름이 주어졌을 때, 오민식과 성공할 확률이 가장 높은 여자의 이름을 출력하는 프로그램을 작성하시오. 여러명일 때에는 알파벳으로 가장 앞서는 이름을 출력하면 된다.

입력
첫째 줄에 오민식의 영어 이름이 주어진다. 둘째 줄에는 좋아하는 여자가 몇 명인지 N이 주어지고, 셋째 줄부터 N개의 줄에 여자의 이름이 하나 씩 주어진다. N은 50보다 작거나 같고, 모든 이름은 알파벳 대문자로만 구성되어 있고 모두 길어야 20글자이다.

출력
오민식이 선택한 여자의 이름을 출력한다.

예제 입력 1 
OHMINSIK
9
YOONA
TIFFANY
YURI
HYOYEON
SOOYOUNG
SEOHYUN
TAEYEON
JESSICA
SUNNY
예제 출력 1 
HYOYEON
*/
