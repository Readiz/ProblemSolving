// // #pragma GCC optimize ("O3")
// // #pragma GCC optimize ("Ofast")
// // #pragma GCC optimize ("unroll-loops")
// // #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #include <bits/stdc++.h>
// using namespace std;

// #define SQRT 65536 // Max: 20억의 루트 근처의 SQRT 유사값
// #define MASK 65535
// int cnt1[SQRT + 1];
// int acc[SQRT + 1];
// int cnt2[SQRT + 1];
// int tmp[5000000];

// int kth(int *data, int size, int k) {
// 	register int i;
//     register int j;

//     // 하위 부터 bucket
//     for(i = 0; i < size; ++i) {
//         data[i] += 1000000000;
//         cnt1[data[i] & MASK]++;
//     }
//     for(i = 0; i < SQRT; ++i) {
//         acc[i+1] = acc[i] + cnt1[i];
//     }
//     for(i = 0; i < size; ++i) {
//         tmp[acc[data[i] & MASK]++] = data[i];
//     }

//     // 상위 bucket
//     for(i = 0; i < size; ++i) {
//         cnt2[tmp[i] >> 16]++;
//     }
//     acc[0] = 0;
//     for(i = 0; i < SQRT; ++i) {
//         acc[i+1] = acc[i] + cnt2[i];
//     }
//     for(i = 0; i < size; ++i) {
//         data[acc[tmp[i] >> 16]++] = tmp[i];
//     }
//     return data[k-1] - 1000000000;
// }

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

template <typename T>
T quickselect_pos(std::vector<T>& data, size_t start, size_t end, size_t k);

template <typename T>
size_t sort_and_get_median(std::vector<T>& data, size_t start, size_t end) {
  std::sort(data.begin() + start, data.begin() + end + 1);
  return (start + end) / 2;
}

template <typename T>
size_t choose_pivot(std::vector<T>& data, size_t start, size_t end) {
  // 데이터 셋의 크기가 5 이하라면 그냥 정렬해서 중간값을 찾는다.
  if (end - start < 5) {
    return sort_and_get_median(data, start, end);
  }

  size_t current = start;
  for (size_t i = start; i <= end; i += 5) {
    // 데이터 셋을 크기가 5 인 그룹으로 쪼개서 각 그룹의 중간값을 찾는다.
    size_t med_pos = sort_and_get_median(data, i, std::min(i + 4, end));

    // 각 그룹의 중간값을 맨 앞으로 가져온다.
    std::iter_swap(data.begin() + current, data.begin() + med_pos);
    current++;
  }

  return quickselect_pos(data, start, current - 1, (current + start - 1) / 2);
}

template <typename T>
size_t partition(std::vector<T>& data, size_t start, size_t end,
                 size_t pivot_pos) {
  // 우리의 파티션 알고리즘은 피벗이 맨 마지막에 있다고 가정하므로, 고른 피벗을
  // 맨 뒤로 옮긴다.
  std::iter_swap(data.begin() + end, data.begin() + pivot_pos);

  const auto& pivot = data[end];
  size_t current_small_loc = start;  // 검은색 지시자

  // i 가 빨간색 지시자 역할을 한다.
  for (size_t i = start; i <= end; i++) {
    if (data[i] <= pivot) {
      std::swap(data[current_small_loc++], data[i]);
    }
  }
  return current_small_loc - 1;
}

template <typename T>
T quickselect_pos(std::vector<T>& data, size_t start, size_t end, size_t k) {
  if (start == end) {
    return start;
  }

  // 피벗을 하나 고른다.
  size_t pivot_pos = choose_pivot(data, start, end);
  // 파티션 후 피벗의 위치를 받는다.
  pivot_pos = partition(data, start, end, pivot_pos);

  if (pivot_pos == k) {  // 빙고!
    return pivot_pos;
  } else if (pivot_pos < k) {  // 찾고자 하는 원소는 피벗 오른쪽에 있다.
    return quickselect_pos(data, pivot_pos + 1, end, k);
  } else {  // 찾고자 하는 원소는 피벗 왼쪽에 있다.
    return quickselect_pos(data, start, pivot_pos - 1, k);
  }
}

template <typename T>
T quickselect(std::vector<T>& data, size_t start, size_t end, size_t k) {
  if (start == end) {
    return data[start];
  }

  // 피벗을 하나 고른다.
  size_t pivot_pos = choose_pivot(data, start, end);

  // 파티션 후 피벗의 위치를 받는다.
  pivot_pos = partition(data, start, end, pivot_pos);

  if (pivot_pos == k) {  // 빙고!
    return data[pivot_pos];
  } else if (pivot_pos < k) {  // 찾고자 하는 원소는 피벗 오른쪽에 있다.
    return quickselect(data, pivot_pos + 1, end, k);
  } else {  // 찾고자 하는 원소는 피벗 왼쪽에 있다.
    return quickselect(data, start, pivot_pos - 1, k);
  }
}

// int main() {
//   std::vector<int> data;
//   data.reserve(10000);
//   for (int i = 1; i <= 10000; i++) {
//     data.push_back(i);
//   }

//   std::random_device rd;
//   std::mt19937 g(rd());

//   for (int i = 0; i < 10; i++) {
//     // 데이터를 랜덤하게 섞는다.
//     std::shuffle(data.begin(), data.end(), g);

//     // 매번 5000 이 나와야 한다.
//     std::cout << "중간값 : " << quickselect(data, 0, 9999, 4999) << std::endl;
//   }
// }

int kth(std::vector<int> &a, int k) {
        
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(a.begin(), a.end(), g);
	return quickselect(a, 0, a.size() - 1, k - 1);
}


int seed = 5;
int pseudo_rand() {
    seed = seed * 214013 + 2531011;
    return (seed >> 16) & 0x7FFF;
}

int test[5'000'000];
int main() {
    std::vector<int> test(5000000);

    for(int i = 0; i < 5'000'000; ++i) {
        if (pseudo_rand() % 2 == 0) {
            test[i] = (pseudo_rand() * 53133 + pseudo_rand()) % 1'000'000'000;
        } else {
            test[i] = -((pseudo_rand() * 53133 + pseudo_rand()) % 1'000'000'000);
        }
    }

    clock_t start = clock();
    kth(test, pseudo_rand());
    printf("%ld", (clock() - start) * 1000 / CLOCKS_PER_SEC);

    return 0;
}