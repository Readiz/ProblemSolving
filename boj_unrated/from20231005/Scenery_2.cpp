#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Photo {
    ll r; ll d; // release, deadline
    bool operator<(const Photo& t) {
        if (r != t.d) return r < t.r;
        return r < t.d;
    }
};

int main() {
    ll N, T; scanf("%lld %lld", &N, &T);
    vector<Photo> photo(N);
    for(auto& item: photo) scanf("%lld %lld", &item.r, &item.d);
    vector<ll> forbidden(N), etime(N);
    for(int i = 0; i < N; ++i) etime[i] = photo[i].d;
    sort(photo.begin(), photo.end());
    sort(etime.begin(), etime.end());
    // 인덱스 i의 forbidden region의 시작 지점
    // i번째 forbidden region은 개구간 (forbidden[i], photo[i].r) 이다.
    for(int i = 0; i < N; ++i) forbidden[i] = photo[i].r;

    for(int i = 0; i < N; ++i) {
        ll curEndTime = etime[i];
        ll remainTime = curEndTime - T;
        int k = N - 1;

        for(int j = N - 1; j >= 0; --j) { // 뒤쪽 사진부터 확인한다. (Backward Scheduling)
            if (photo[j].d <= etime[i]) {
                for(; k >= 0 && remainTime < photo[k].r; k--) // 모든 forbidden을 고려한다.
                    remainTime = min(remainTime, forbidden[k]); // job 할당
                if (remainTime < photo[j].r) {
                    printf("no\n"); return 0;
                }
                // Forbidden Region을 업데이트 할 조건이 아래
                if (remainTime < photo[j].r + T) forbidden[j] = min(forbidden[j], remainTime - T);

                // 할당했으니 시간을 줄인다.
                remainTime -= T;
            }
        }
    }
    printf("yes\n");

    return 0;
}