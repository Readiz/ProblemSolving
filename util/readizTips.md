각종 고인 입출력 예제들은 여기 문제 제출 참조 (버퍼 활용 쩜)
https://www.acmicpc.net/problem/15552
대표적 인 예는 
1. https://www.acmicpc.net/source/8639309 -> syscall 사용
2. https://www.acmicpc.net/source/22882480 -> define 사용
3. https://www.acmicpc.net/source/12174407 -> syscall 사용 2
4. https://www.acmicpc.net/source/8636270 -> syscall 을 사용한 fio 모듈 (readchar) 사용
5. https://www.acmicpc.net/source/27423012 -> readInt / ReadLong / readString 등등 구현 되어 있음
6. https://www.acmicpc.net/source/11806275 -> 그냥 단순하게 fread로 buf에 한번에 다 때려박고, 한번에 fwrite로 씀 (전체 TC 크기 안다면..)

11004 문제: Quick Select 알고리즘
참고 : https://modoocode.com/287
N개의 원소가 있을 때 K 번째 큰 녀석을 O(N) 만에 찾아냄.
하지만 Pivot 때문에 어려움. 최악의 경우 O(N^2)이 됨.
속도가 괜찮은 Pivot을 찾는 알고리즘을 찾아야 함.
단순하게는 가장 작은 값 / 큰 값 / 중간값 중 중간 값을 택해서 Pivot으로 설정하는 등의 방법이 있다.

-----------------------------------------

FFT (Fast Fourier Transform)

[FFT 예시 문제]
큰 수 A * B를 C++로 풀려면... (문제: https://www.acmicpc.net/problem/13277)
https://www.acmicpc.net/board/view/61028
C++으로 큰 수 곱셈을 풀려면 카라츠바 알고리즘 또는 Fast Fourier Transform이 필요합니다.
https://greeksharifa.github.io/algorithm%20&%20data%20structure/2018/07/07/algorithm-FFT/

시간복잡도: O(N logN)
공간복잡도: O(N)
N은 두 수열의 길이의 max값이다.
FFT는 convolution을 빠르게 해 주는 것이지만, PS에서는 거의 대부분 곱셈을 빠르게 하기 위해 쓰인다.
이 글에서는 FFT(고속 푸리에 변환)을 설명한다.
이론적인 부분에 대한 자세한 설명은 topology-blog에 잘 되어 있으므로 생략한다.
설명: https://topology-blog.tistory.com/6

-> 예시 C++ 솔루션: https://www.acmicpc.net/source/7347729


--------------------------------------------
각 형들 MIN & MAX 표현

https://www.keil.com/support/man/docs/armcc/armcc_chr1359125038144.htm
CHAR_MAX	Maximum value of char	255	0xFF
CHAR_MIN	Minimum value of char	0	0x00
SCHAR_MAX	Maximum value of signed char	127	0x7F
SCHAR_MIN	Minimum value of signed char	–128	0x80
UCHAR_MAX	Maximum value of unsigned char	255	0xFF
SHRT_MAX	Maximum value of short	32 767	0x7FFF
SHRT_MIN	Minimum value of short	–32 768	0x8000
USHRT_MAX	Maximum value of unsigned short	65 535	0xFFFF
INT_MAX 	Maximum value of int	2 147 483 647	0x7FFFFFFF
INT_MIN 	Minimum value of int	–2 147 483 648	0x80000000
LONG_MAX	Maximum value of long	2 147 483 647	0x7FFFFFFF
LONG_MIN	Minimum value of long	–2 147 483 648	0x80000000
ULONG_MAX	Maximum value of unsigned long	4 294 967 295	0xFFFFFFFF
LLONG_MAX	Maximum value of long long	9.2E+18	0x7FFFFFFFFFFFFFFF
LLONG_MIN	Minimum value of long long	–9.2E+18	0x8000000000000000
ULLONG_MAX	Maximum value of unsigned long long	1.8E+19	0xFFFFFFFFFFFFFFFF


-------------------------------------------
구간합 구하기

기본적으로는 SegTree를 사용하는 것이 정석
다만, "합" 에 관해서는 더 편한 팬윅 트리(Fenwick Tree)라는 것이 존재함 - Binary Indexed Tree라고도 함
 - https://yabmoons.tistory.com/438
 - https://www.acmicpc.net/blog/view/21
세그트리보다 구조도 간단하고, 사용하기도 편함. (비트 연산 활용)
다만, 활용도는 떨어지는 단점이 있다.
구간합 풀이 예) https://www.acmicpc.net/source/28008395



----------------------------------------------
이진 탐색 관련 유의할 점 모음
http://blog.weirdx.io/post/3121

1. Mid Overflow
  - int mid = low + (high - low) / 2 사용
  - int mid = (low + high) >> 1 사용

2. 경계값 문제
  - left: 0 <= i < n / 2
  - right: (n + 1) / 2 <= i < n
  -... 으로 두면, 대부분 문제는 발생하지 않는다. 홀수 / 짝수에서 어그러지니 유의.
  - 특히, right가 n / 2 + 1 이 아님에 유의. 홀 / 짝수 둘 다 고려하면, (n + 1) / 2 부터 시작하는 것이 맞다.
  - ex) n = 3 일 경우
    - left: 0 <= i < 1
    - right: 2 <= i < n
  - ex) n = 4 일 경우
    - left: 0 <= i < 2
    - right: 2<= i < 4
  - 중간 포지션을 기점으로 어떻게 해야하는지에 대한 내용이니, 반드시 기억. 홀수 일때는 중간 값을 제외, 짝수 일때는 따로 포함 x 한다고 생각.

3. 실제 구현 (반복문이 좋다)
```c++
int binary_search(int* arr, int length, int value) {

    if (arr == nullptr || length < 0)
        return -1;

    int left = 0;
    int right = length - 1;
    int mid;

    while(left <= right) {  // 여기서 left <= right 로 설정함에 유의.. 원소가 {0, 1} 두개이면, 1을 찾을 때 돌지 않음. (left = right가 되면 loop 탈출하므로..)
        mid = left + (right - left) / 2;

        if(arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else if (arr[mid] > value) {
            right = mid - 1;
        }
    }

    return -1;
}
```


-----------------------------------------------------
정수론 / 소수이론

1. 밀러 라빈 소수판정법 (https://casterian.net/archives/396)
확률적 소수판정. 소수가 아닌 case는 완벽하게 알 수 있음.
결국 a를 많이 넣어보지 않으면 높은 확률로 틀린다는 건데, n이 작으면 a를 이 정도만 넣어봐도 충분하다고 계산해놓은 게 있습니다. n이 2^32보다 작은 합성수이면(unsigned int에 저장 가능한 정수라면) a에 2, 7, 61만 넣어봐도 소수로 잘못 판별되는 일이 없다고 합니다. 또, n이 2^64보다 작은 합성수이면(unsigned long long) a에 2, 325, 9375, 28178, 450775, 9780504, 1795265022만 넣어봐도 충분합니다.

2. 폴라드로: 빠른 소인수 분해 방법.
랜덤으로 생성한 숫자에 g(x) = (x^2 + 1) mod N 꼴의 함수를 태워서, 빠르게 소인수를 찾아나가는 방법.
큰 수에 대해서는 1부터 차례로 숫자에 접근하는 것보다 이 방법이 빠르다.
다만 소수일 경우에는 무한루프 가능이라, 소수는 바로 자기 자신의 인수라고 판정하고 합성수 아니라고 하고 나가는게 좋다.



---------------------------------------------------------
Architect는 고려하지 않은 무조건적인 최적화 팁 (시험을 통한 잡지식... 컴구 관련.)

1. 반복문을 많이 쓰는 문제는 register 차이가 크다.
  - 함수당 2개씩 사용 가능함. (or 3개.. 지역당.)
2. a[i][j] 와 같은 것도 반복문에서 많이 쓰이면, 접근하는 overhead가 크다.
  - pa = a[i] 로 먼저 잡아주고, pa[j] 로 접근하기.
3. if - else 구성 시 빈도수가 높은 경우의 수를 위로
  - 분기문이 더 많을 경우 이진트리 식으로 분기문 구성
4. 함수 호출 줄이기
  - inline으로 그냥 작성하는게 젤빠르다. (진짜로 반복 하는거고 inline 키워드 말하는 것 아님. inline 키워드는 컴파일러 옵션에 따라 달라짐.)
  - 아니라면, #define을 활용하는게 나을 듯. #define max(a, b) { a>b... } 와 같이...
5. new, alloc 사용 지양. 전역 공간에 메모리 배열로 잡아두고 할당하면 속도에서 이득.


---------------------------------------------------------
Codeforces 라운드 정의
- These have some score distribution. Hacking can be done in the contest itself. Once you lock your solution to a problem, you can hack other participants' solutions.
 . Codeforces Global Rounds
  a. Rated for all
 . Codeforces Div2
  a. Rated for <= 2099
 . Codeforces Div1+Div2
  a. Rated for all
  b. This is actually 2 contests(Div1 and Div2) held at the same time with some shared problems. Participants <= 1899 participate in Div2 and participants >= 1900 participate in Div1.

- These rounds have equal weightage for each problem and have a 12 hr hacking phase after the contest ends
 . Educational
  a. rated for <= 2099
 . Div3
  a. rated for <= 1599


------------------------------------------------------------
비트 연산 관련
- 비트 연산의 우선순위는 낮기 때문에 아래와 같이 홀수를 판별하는 로직에서 매우 조심하여야 함.
 . if ((N & 1ULL) == 0ULL) <- 괄호 필요.
 


------------------------------------------------------------
헤더 관련

- #include <bits/stdc++.h>
 . gcc에서만 사용 가능. 비표준.


------------------------------------------------------------
샘플 코드 for pair using
------------------------------------------------------------
https://blog.naver.com/p_bysu
```c++
#include<bits/stdc++.h>
using namespace std;
int n, k;
typedef long long ll;
typedef pair<ll, ll> pll;
deque<pll> dq;
ll dp[100001], tmp, ans, arr[100001];
int main() {
	dq.push_back({0,0});
	scanf("%d %d\n", &n, &k);
	for (int i = 0; i < n; i++) 
		scanf("%lld", arr + i);
	for(int i =0; i< n; i++){
		while(dq.size() && dq.front().second < i-k) dq.pop_front();
		dp[i] = arr[i];
		tmp = dq.front().first;
		dp[i] = max(dp[i], tmp+ arr[i]);
		while(dq.size() && dq.back().first <= dp[i]) dq.pop_back();
		dq.push_back({dp[i],i});
	}
	ans = -1e18;
	for(int i = 0; i<n; i++)
		ans = max(ans, dp[i]);
	printf("%lld\n", ans);
	return 0;
}
// [출처] BOJ) 15678 연세 워트 파크|작성자 bysu
```



---------------------------------------
한글 인코딩 관련
----------------------------------------
https://www.vbflash.net/192
아주 쉬운 문자 인코딩 강좌 1/7 
https://www.clien.net/service/board/lecture/9924551
CLIEN

아주 쉬운 문자 인코딩 강좌 2/7 
https://www.clien.net/service/board/lecture/9924679
CLIEN

아주 쉬운 문자 인코딩 강좌 3/7 
https://www.clien.net/service/board/lecture/9924722
CLIEN

아주 쉬운 문자 인코딩 강좌 4/7 
https://www.clien.net/service/board/lecture/9924759
CLIEN

아주 쉬운 문자 인코딩 강좌 5/7 
https://www.clien.net/service/board/lecture/9924778
CLIEN

아주 쉬운 문자 인코딩 강좌 6/7 
https://www.clien.net/service/board/lecture/9924803
CLIEN

아주 쉬운 문자 인코딩 강좌 7/7 
https://www.clien.net/service/board/lecture/9924839
CLIEN