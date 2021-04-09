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