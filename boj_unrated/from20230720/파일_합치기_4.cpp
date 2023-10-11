// HuTucker 공부하기
// 참고자료: https://blog.myungwoo.kr/141
// 시간복잡도: O(N log^2 N)

#include <bits/stdc++.h>
using namespace std;
 
using lld = long long;
 
template<typename T>
struct HuTucker{
    using value_t = T;
    using heap_t = priority_queue<value_t, vector<value_t>, greater<value_t>>;
    int N;
    vector<value_t> W, C;
    vector<int> L, R;
    vector<heap_t> heaps;
    priority_queue<pair<value_t, int>> main;
    static value_t second_top(heap_t& h){
        auto a = h.top(); h.pop();
        auto b = h.top();
        h.push(a);
        return b;
    }
    static void merge(heap_t& a, heap_t& b){
        if (a.size() < b.size()) a.swap(b);
        while (!b.empty()) a.push(b.top()), b.pop();
    }
    static constexpr value_t inf = numeric_limits<value_t>::max();
    HuTucker(const vector<T>& arr){
        N = arr.size();
        W.resize(N+2); C.resize(N+2); L.resize(N+2); R.resize(N+2);
        for (int i=0;i<N;i++) W[i+1] = arr[i];
        for (int i=0;i<=N;i++) R[i] = i+1, L[i+1] = i;
        W[0] = W[N+1] = inf;
        heaps.resize(N+1);
        for (int i=1;i<N;i++){
            C[i] = W[i]+W[i+1];
            main.emplace(-C[i], i);
        }
    }
    value_t get_min(int i){
        value_t ret = inf;
        if (W[i] != inf && W[R[i]] != inf) ret = min(ret, W[i]+W[R[i]]);
        if (W[i] != inf && heaps[i].size() >= 1) ret = min(ret, W[i]+heaps[i].top());
        if (W[R[i]] != inf && heaps[i].size() >= 1) ret = min(ret, W[R[i]]+heaps[i].top());
        if (heaps[i].size() >= 2) ret = min(ret, heaps[i].top()+second_top(heaps[i]));
        return ret;
    }
    value_t solve(){
        value_t ans{};
        for (int elements=N;elements>1;){
            auto item = main.top(); main.pop(); 
            auto c = item.first;
            auto i = item.second;
            c = -c;
            if (C[i] != c) continue;
            if (heaps[i].size() >= 2 && heaps[i].top()+second_top(heaps[i]) == c){
                heaps[i].pop(); heaps[i].pop();
            }
            else if (W[i] != inf && heaps[i].size() >= 1 && W[i]+heaps[i].top() == c){
                C[i] = W[i] = inf;
                R[L[i]] = R[i];
                L[R[i]] = L[i];
                heaps[i].pop();
                merge(heaps[L[i]], heaps[i]);
                i = L[i];
            }
            else if (W[R[i]] != inf && heaps[i].size() >= 1 && W[R[i]]+heaps[i].top() == c){
                C[R[i]] = W[R[i]] = inf;
                heaps[i].pop();
                L[R[R[i]]] = i;
                merge(heaps[i], heaps[R[i]]);
                R[i] = R[R[i]];
            }
            else if (W[i] != inf && W[R[i]] != inf && W[i]+W[R[i]] == c){
                C[i] = C[R[i]] = W[i] = W[R[i]] = inf;
                R[L[i]] = R[R[i]];
                L[R[R[i]]] = L[i];
                merge(heaps[i], heaps[R[i]]);
                merge(heaps[L[i]], heaps[i]);
                i = L[i];
            }
            else assert(0);
            heaps[i].push(c); C[i] = get_min(i);
            main.emplace(-C[i], i);
            --elements; ans += c;
        }
        return ans;
    }
};
 
void solve(){
    int n; scanf("%d", &n);
    vector<lld> arr(n);
    for (lld& v: arr) scanf("%lld", &v);
    auto h = HuTucker<lld>(arr);
    printf("%lld\n", h.solve());
}
 
int main(){
    int T;
    for (scanf("%d", &T);T--;) solve();
}