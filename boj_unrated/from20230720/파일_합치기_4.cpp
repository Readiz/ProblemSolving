#pragma GCC optimize ("O3")
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")

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
    ~Vector() {
        delete[] data;
    }

    void insert(T v) {
        if (capa == sz) {
            capa *= 2;
            T* newData = new T[capa];
            for(int i = 0; i < sz; ++i) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[sz++] = v;
    }
    T& operator[](int idx) {
        assert(idx < sz && idx >= 0);
        return data[idx];
    }
    int size() { return sz; }
    void pop() { 
        assert(sz > 0);    
        --sz;
    };
    void resize(int N) {
        delete[] data;
        capa = N;
        sz = N;
        data = new T[N];
    }
    void clear() {
        delete[] data;
        capa = 10, sz = 0;
        data = new T[capa];
    }
};

template <typename T>
struct MinHeap {
    Vector<T> data;
    int p(int idx) {
        return ((idx - 1) >> 1);
    }
    int l(int idx) {
        return (idx << 1) + 1;
    }
    int r(int idx) {
        return (idx << 1) + 2;
    }
    void push(T v) {
        data.insert(v);
        int idx = data.size() - 1;

        while(idx > 0 && data[p(idx)] > data[idx]) {
            swap(data[p(idx)], data[idx]);
            idx = p(idx);
        }
    }
    T top() {
        return data[0];
    }
    T second_top() {
        if (data.size() >= 3) return data[1] < data[2] ? data[1] : data[2];
        return data[1];
    }
    T pop() {
        assert(data.size() > 0);
        T ret = data[0];
        data[0] = data[data.size() - 1];
        data.pop();

        int idx = 0;
        while(l(idx) < data.size()) {
            int c = l(idx);
            if (r(idx) < data.size() && data[l(idx)] > data[r(idx)]) {
                c = c+1;
            }
            if (data[c] < data[idx]) {
                swap(data[c], data[idx]);
            } else {
                break;
            }
            idx = c;
        }

        return ret;
    }
    
    void merge(MinHeap<T>& other) {
        if (other.data.size() < data.size()) {
            swap(data.data, other.data.data);
            swap(data.sz, other.data.sz);
            swap(data.capa, other.data.capa);
        }
        while(other.data.size()) {
            push(other.pop());
        }
        other.clear();
    }

    void clear() {
        data.clear();
    }

    int size() { return data.size(); }
};

struct Node {
    ll initValue; // INF: not used
    int leftIdx; // Linked List
    int rightIdx;
    ll rangeMin;
    MinHeap<ll> heap;
};

struct Priority {
    ll value;
    int idx;
    bool operator<(const Priority& t) const {
        if (value != t.value) return value < t.value;
        return idx > t.idx;
    }
    bool operator>(const Priority& t) const {
        return t < *this;
    }
};

Vector<Node> n;
constexpr ll INF = 0x3A3A3A3A3A3A3A3ALL;
void solve() {
    int N; scanf("%d", &N);
    n.clear();
    n.resize(N+2);

    MinHeap<Priority> Candidates; // {val, idx}
    for(int i = 1; i <= N; ++i) {
        int val; scanf("%d", &val);
        n[i].initValue = val;
        n[i].leftIdx = i - 1;
        n[i].rightIdx = i + 1;
        n[i].rangeMin = INF;
        n[i].heap.clear();
    }
    n[0].leftIdx = n[0].rangeMin = n[0].initValue = INF;
    n[0].rightIdx = 1;
    n[0].heap.clear();
    n[N+1].rightIdx = n[N+1].rangeMin = n[N+1].initValue = INF;
    n[N+1].leftIdx = N;
    n[N+1].heap.clear();
    for(int i = 1; i < N; ++i) {
        Candidates.push({n[i].initValue + n[i + 1].initValue, i});
        n[i].rangeMin = n[i].initValue + n[i + 1].initValue;
    }
    ll ans = 0;
    int mergeNeedCnt = N - 1;
    while(Candidates.size() > 0 && mergeNeedCnt > 0) {
        auto cur = Candidates.pop();
        int idx = cur.idx;
        int ridx = n[idx].rightIdx;
        ll cval = cur.value;
        _D("cur min: %lld / idx: %d (latest: %lld)\n", cval, idx, n[idx].rangeMin);
        if (cval >= INF) {
            break;
        }
        if (n[idx].rangeMin != cval) continue; // lazy value 유효성 검사
        if (n[idx].initValue + n[ridx].initValue == cval) {
            // 초창기 case
            // LinkedList에서 idx와 n[idx].rightIdx를 지운다.
            int ridx = n[idx].rightIdx;
            int lidx = n[idx].leftIdx;
            n[idx].initValue = n[ridx].initValue = INF;
            n[idx].rangeMin = n[ridx].rangeMin = INF;
            n[lidx].rightIdx = n[ridx].rightIdx;
            n[n[ridx].rightIdx].leftIdx = lidx;
            n[idx].heap.merge(n[ridx].heap);
            n[lidx].heap.merge(n[idx].heap);
            idx = lidx; // idx, ridx가 삭제되고, 왼쪽으로 합쳐진다.
        } else if (n[idx].heap.size() >= 2 && n[idx].heap.top() + n[idx].heap.second_top() == cval) {
            n[idx].heap.pop();
            n[idx].heap.pop();
        } else if (n[idx].heap.size() >= 1 && n[idx].initValue + n[idx].heap.top() == cval) {
            n[idx].initValue = INF;
            n[idx].rangeMin = INF;
            n[idx].heap.pop();
            // LinkedList에서 idx를 지운다.
            int lidx = n[idx].leftIdx;
            int ridx = n[idx].rightIdx;
            n[lidx].rightIdx = ridx;
            n[ridx].leftIdx = lidx;
            n[lidx].heap.merge(n[idx].heap);
            idx = lidx; // idx가 삭제되고, 왼쪽으로 합쳐진다.
        } else if (ridx != INF && n[idx].heap.size() >= 1 && n[ridx].initValue + n[idx].heap.top() == cval) {
            n[ridx].initValue = INF;
            n[ridx].rangeMin = INF;
            n[idx].heap.pop();
            // LinkedList에서 ridx를 지운다.
            int rridx = n[ridx].rightIdx;
            n[idx].rightIdx = rridx;
            n[rridx].leftIdx = idx;
            n[idx].heap.merge(n[ridx].heap);
            // idx = idx; // ridx가 삭제되고, 왼쪽으로 합쳐진다.
        } else {
            _D("Not covered!\n");
            return;
        }
        // 1336160000
        // 7844640000
        n[idx].heap.push(cval); // 합친 값을 이제 heap에 넣는다.

        ridx = n[idx].rightIdx;
        ll v1 = INF, v2 = INF, v3 = INF, v4 = INF;
        v1 = n[idx].initValue + n[ridx].initValue;
        if (n[idx].heap.size() > 0) v2 = n[idx].initValue + n[idx].heap.top();
        v3 = n[ridx].initValue + n[idx].heap.top();
        if (n[idx].heap.size() >= 2) v4 = n[idx].heap.top() + n[idx].heap.second_top();

        ll nextRangeMin = min(min(v1, v2), min(v3, v4));
        _D("next min: %lld, at: %d\n", nextRangeMin, idx);
        Candidates.push({nextRangeMin, idx});
        n[idx].rangeMin = nextRangeMin;
        ans += cval;
        mergeNeedCnt--;
    }
    assert(ans < INF);
    printf("%lld\n", ans);
}

int main() {
    int TC; scanf("%d", &TC);
    while(TC--) solve();

    return 0;
}