#include <bits/stdc++.h>
using namespace std;

int A[100'001];

struct Node {
    int cnt;
    int idx;

    bool operator<(const struct Node& t) const {
        if (cnt != t.cnt) return cnt > t.cnt;
        return idx < t.idx;
    }
};

// 1-indexed, min heap
#define parent(v) ((v) >> 1)
#define left(v) ((v) << 1)
#define right(v) (((v) << 1)|1)
struct Heap {
    Node n[100'001];
    int pos[100'001];
    int sz;

    void up(int i) {
        while (parent(i) > 0) {
            int p = parent(i);
            if (n[i] < n[p]) {
                Node tmp = n[i];
                n[i] = n[p];
                n[p] = tmp;
                pos[n[i].idx] = i;
                pos[n[p].idx] = p;

                i = p;
            } else {
                break;
            }
        }
    }
    void down(int i) {
        while(left(i) <= sz) {
            int c = left(i);
            if ((c|1) <= sz) {
                if (n[c|1] < n[c]) {
                    c = c|1;
                }
            }
            if (n[c] < n[i]) {
                Node tmp = n[c];
                n[c] = n[i];
                n[i] = tmp;
                pos[n[i].idx] = i;
                pos[n[c].idx] = c;

                i = c;
            } else {
                break;
            }
        }
    }
    void add(int& num) {
        if (pos[num] == 0) {
            ++sz;
            pos[num] = sz;
            n[sz] = Node{1, num};
            up(sz);
        } else {
            int p = pos[num];
            n[p].cnt++;
            up(p);
        }
    }
    void erase(int& num) {
        int p = pos[num];
        if (p > 0) {
            n[p].cnt--;
            down(p);
        }
    }

    void printall() {
        for(int i = 1; i <= sz; ++i) {
            if (n[i].cnt > 5 || n[i].cnt < 0)
            printf("%d, %d\n", n[i].cnt, n[i].idx);
        }
        printf("---\n");
    }
} h;

struct Q {
    int l, r, n;
    bool operator<(const struct Q& t) const {
        if (r / 320 != t.r / 320) return r / 320 < t.r / 320;
        return l < t.l;
    }
} q[100'000];
int ans[100'000];
int main() {
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; ++i) scanf("%d", &A[i]);
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        q[i] = Q{a, b, i};
    }
    sort(q, q + N);

    int l = q[0].l; int r = q[0].r;
    for(int i = l; i <= r; ++i) {
        h.add(A[i]);
    }
    ans[q[0].n] = h.n[1].cnt;
    // printf("[%d] %d ~ %d\n", q[0].n, l, r);
    // h.printall();

    for(int i = 1; i < N; ++i) {
        int cl = q[i].l; int cr = q[i].r;
        while(cr > r) h.add(A[++r]);
        while(cl < l) h.add(A[--l]);
        while(cr < r) h.erase(A[r--]);
        while(cl > l) h.erase(A[l++]);

        // printf("[%d] %d ~ %d\n", q[i].n, l, r);
        // h.printall();
        ans[q[i].n] = h.n[1].cnt;
    }
    for(int i = 0; i < N; ++i) {
        printf("%d\n", ans[i]);
    }

    return 0;
}