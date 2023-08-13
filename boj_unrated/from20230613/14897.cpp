#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
using namespace std;

int A[1'000'001];

struct Node {
    int num;
    int convertNum;
};
int cidx;

// 1000007로 나눈 위치에 들어간다.
constexpr int BSIZE = 1'000'007;
vector<Node> bucket[BSIZE]; // 숫자 n은 n % BSIZE에 들어가야한다.

int cnt[1'000'000];
int s;

inline void add(int& num) {
    cnt[num]++;
    if (cnt[num] == 1) s++;
}
inline void erase(int& num) {
    cnt[num]--;
    if (cnt[num] == 0) s--;
}

struct Q {
    int l, r, n;
    bool operator<(const struct Q& t) const {
        if (r / 1000 != t.r / 1000) return r / 1000 < t.r / 1000;
        return l < t.l;
    }
} q[1'000'000];

int ans[1'000'000];

int main() {
    int N, a, b, tmp;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d", &tmp);
        int bNum = tmp % BSIZE;
        bool found = false;
        for(auto& item: bucket[bNum]) {
            if (item.num == tmp) {
                found = true;
                A[i] = item.convertNum;
                break;
            }
        }
        if (!found) {
            A[i] = cidx;
            bucket[bNum].push_back(Node{tmp, cidx++});
        }
        // printf("%d -> %d mapped.\n", tmp, A[i]);
    }

    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d %d", &a, &b);
        q[i] = Q{a, b, i};
    }
    sort(q, q + N);

    int l = q[0].l; int r = q[0].r;
    for(int i = l; i <= r; ++i) {
        add(A[i]);
    }
    ans[q[0].n] = s;

    for(int i = 1; i < N; ++i) {
        int cl = q[i].l, cr = q[i].r;
        while(cl < l) add(A[--l]);
        while(l < cl) erase(A[l++]);
        while(cr < r) erase(A[r--]);
        while(r < cr) add(A[++r]);
        ans[q[i].n] = s;
    }

    for(int i = 0; i < N; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}


/*
총 N개의 정수로 이루어진 배열 A가 주어진다. 이때, 다음 쿼리를 총 Q번 반복 수행하는 프로그램을 작성하시오. 배열은 1번부터 시작한다.

l r: l번째 수부터 r번째 수 중에서 서로 다른 수의 개수를 세고 출력한다.
입력
첫째 줄에 배열의 크기 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄에는 배열에 포함된 수가 1번째 수부터 주어진다. 수는 공백으로 구분되어져 있다. 배열에 포함된 수는 1,000,000,000보다 작거나 같은 자연수이다.

셋째 줄에는 쿼리의 개수 Q(1 ≤ Q ≤ 1,000,000)가 주어진다. 넷째 줄부터 Q개의 줄에는 쿼리 li, ri가 주어진다. (1 ≤ li ≤ ri ≤ N)
*/