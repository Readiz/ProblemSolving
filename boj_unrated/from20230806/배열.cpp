#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;
#define FOR(i,a,b) for(int i=(a); ((i)^(b)); ++i)
#ifndef ONLINE_JUDGE
    bool isDebug = true;
    #define _D(...) printf(__VA_ARGS__)
#else
    bool isDebug = false;
    #define _D(...)
#endif

constexpr int INF = 987654321;

int N;
struct Node {
    int key;
    int data;
    Node* l;
    Node* r;
    Node* p;
    int sz;
    int rangeMin;
    int rangeMax;
    ll rangeSum;
    bool isFlip;

    void push() {
        if (isFlip == false) return;
        swap(l, r);

        if (l) {
            l->isFlip = !l->isFlip;
        }
        if (r) {
            r->isFlip = !r->isFlip;
        }
        isFlip = false;
    }
    void update() {
        sz = 1;
        rangeMin = data;
        rangeMax = data;
        rangeSum = data;
        if (l) {
            sz += l->sz;
            if (l->data != INF) rangeMin = min(rangeMin, l->rangeMin);
            if (l->data != INF) rangeMax = max(rangeMax, l->rangeMax);
            if (l->data != INF) rangeSum += l->rangeSum;
        }
        if (r) {
            sz += r->sz;
            if (r->data != INF) rangeMin = min(rangeMin, r->rangeMin);
            if (r->data != INF) rangeMax = max(rangeMax, r->rangeMax);
            if (r->data != INF) rangeSum += r->rangeSum;
        }
    }

    bool isLeft() {
        return (p->l == this);
    }
    void rotate() {
        Node* op = this->p;

        op->push(); // lazy는 부모부터 push
        push();

        if (isLeft()) {
            // 왼쪽 자식이면
            //     p             x
            //   x   c        a     p
            // a  b               b   c
            Node* b = r;
            op->l = b;
            if (b) b->p = op;
            this->r = op;
        } else {
            // 오른쪽 자식이면
            //     p                 x
            //  a     x           p    c
            //      b   c      a    b
            Node* b = l;
            op->r = b;
            if (b) b->p = op;
            this->l = op;
        }
        this->p = op->p;
        op->p = this;

        op->update(); // 이전 부모가 이제 자식이다
        update();

        // 부모의 부모 처리***
        if (this->p == 0) return;
        if (this->p->l == op)
            this->p->l = this;
        else
            this->p->r = this;
    }
    void splay() {
        while(p) {
            Node* g = p->p;
            if (g == 0) {
                // 조부모가 없으면 rotate 한번하면 root이다.
                rotate();
                break;
            }
            // g->p 방향과 p->x 방향이 같으면 Zig Zig 
            if (p->isLeft() == this->isLeft()) {
                p->rotate();
                rotate();
            } else {
            // 다르면, Zig Zag
                rotate();
                rotate();
            }
        }
    }

    void printInorder() {
        this->push();
        
        if (l) l->printInorder();
        if(key != 0 && key != N + 1) printf("%d ", key);
        if (r) r->printInorder();
    }
} n[300'010];
int nSz;
Node* newNode(int key, int value) {
    Node* ret = &n[nSz++];
    ret->key = key;
    ret->sz = 1;
    ret->isFlip = false;
    ret->data = ret->rangeMin = ret->rangeMax = ret->rangeSum = value;
    ret->l = ret->r = ret->p = 0;
    return ret;
}

struct SplayTree {
    Node* root;
    SplayTree() {
        init();
    }
    void init() {
        root = 0;
        nSz = 0;
    }

    int getPos(int number) {
        n[number].splay();
        root = &n[number];
        return root->l->sz;
    }
    int sz(Node* p) {
        if (p == 0) return 0;
        return p->sz;
    }
    bool kth(int k) {
        if (root == 0) return false;
        if (k < 0 || k >= root->sz) return false;
        auto cur = root;
        while(true) {
            // printf("checking sz: %d, k: %d\n", p->sz, k);
            cur->push();
            if (sz(cur->l) > k) {
                cur = cur->l;
                continue;
            }
            k -= sz(cur->l);
            // printf("k -> %d\n", k);
            if (k == 0) break;
            --k; // in order, 현재 보고 있는 녀석 자기 자신임
            if (cur->r) cur = cur->r;
            else break;
        }
        cur->splay();
        root = cur;
        return true;
    }
    void gather(int l, int r) {
        // using find
        kth(l - 1);
        auto oldRoot = root;
        root = root->r;
        root->p = 0; // 임시
        kth(r - l + 1);

        root->p = oldRoot;
        oldRoot->r = root;
        root = oldRoot;
    }
    void flip(int l, int r) {
        // _D("flip: %d ~ %d\n", l, r);
        if (l >= r) return;
        gather(l, r);
        // printLevel();
        // _D("root: %c(%d)\n", root->value, root->key);
        // _D("root->r: %c(%d)\n", root->r->value, root->r->key);
        root->r->l->isFlip = !root->r->l->isFlip;
        root->r->l->push();
    }
    void shift(int l, int r, int v) {
        // v: 음수 -> 왼쪽 shift / v: 양수 -> 오른쪽 shift
        if (v == 0) return;
        int len = r - l + 1;
        if (v > 0) {
            // 제일 끝항이 N을 넘어서는지 확인
            if (r + v <= N) {
                // 안넘친다
                flip(l, r+v);
                flip(r+v-len+1,r+v);
                flip(l,r+v-len);
            } else {
                int overflowLen = r + v - N;
                int safeLen = len - overflowLen;
                flip(l, N);
                flip(N - safeLen + 1, N);
                flip(l, N - safeLen);

                // int overflowStart = r - overflowLen + 1;
                flip(1, l + overflowLen - 1);
                flip(1, overflowLen);
                flip(overflowLen + 1, l + overflowLen - 1);
            }
        } else {
            // 제일 왼쪽항이 1보다 작아지는지 확인
            v *= -1; // 생각하기 쉽게 양수로 생각하자,, v만큼 왼쪽으로 간다.
            if (l - v > 0) {
                // 안넘친다
                flip(l-v,r);
                flip(l-v,l-v+len-1);
                flip(l-v+len,r);
            } else {
                int overflowLen = l - v + 1;
                int safeLen = len - overflowLen;
                flip(1, r);
                flip(1, 1 + safeLen - 1);
                flip(safeLen + 1, r);

                flip(l + safeLen, N);
                flip(N - overflowLen + 1, N);
                flip(l + safeLen, N - overflowLen);
            }
        }
    }
    bool insert(int key, int value) {
        auto newOne = newNode(key, value);
        if (root == 0) {
            root = newOne; // no need to splay
            return true;
        }
        auto cur = root;
        while(true) {
            cur->push();
            if (cur->key == key) {
                cur->splay(); // 중복 원소 존재, root로 올려주고 종료
                return false;
            } else if (key < cur->key) {
                if (cur->l == 0) {
                    cur->l = newOne;
                    newOne->p = cur;
                    break;
                }
                cur = cur->l;
            } else {
                if (cur->r == 0) {
                    cur->r = newOne;
                    newOne->p = cur;
                    break;
                }
                cur = cur->r;
            }
        }
        newOne->splay();
        root = newOne;
        return true;
    }
    void print() {
        if(root) root->printInorder();
        printf("\n");
    }
    void printLevel() {
        if (root == 0) return;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        vector<int> level[1000];
        bool hasLevel[1000] = {false, };
        int levelMax = 0;
        while(q.size()) {
            auto cur = q.front(); q.pop();
            if(cur.second >= 1 && hasLevel[cur.second - 1] == false) break;
            if (cur.first) {
                level[cur.second].push_back(cur.first->data);
                hasLevel[cur.second] = true;
                levelMax = cur.second;
            } else {
                level[cur.second].push_back(-1);
            }
            // printf("%d(%d) ", cur.first->key, cur.second);
            if(cur.first && cur.first->l) {
                q.push({cur.first->l, cur.second + 1});
            } else {
                q.push({0, cur.second + 1});
            }
            if(cur.first && cur.first->r) {
                q.push({cur.first->r, cur.second + 1});
            } else {
                q.push({0, cur.second + 1});
            }
        }
        // printf("\n");
        printf("---------------\n");
        for(int i = 0; i <= levelMax; ++i) {
            if (level[i].size()) {
                printf("[%3d] ", i);
            } else break;
            for(int k = 0; k < levelMax - i - 1; ++k) {
                // printf("    ");
            }
            for(auto& item: level[i]) {
                if (item != -1)
                    printf("%4d", item);
                else
                    printf("   -");
            }
            printf("\n");
        }
        printf("---------------\n");
    }
} splay;

void solve() {
    int Q; scanf("%d %d", &N, &Q);
    splay.init();

    splay.insert(0, INF); // guard
    for(int i = 1; i <= N; ++i) {
        splay.insert(i, i); // n[i] -> i번째 추가된 녀석
    }
    splay.insert(N + 1, INF); // guard

    // printf("3 pos: %d\n", n[3].getPos());
    // splay.printLevel();

    for(int q = 0; q < Q; ++q) {
        int cmd; scanf("%d", &cmd);
        if (cmd == 1) {
            int l, r; scanf("%d %d", &l, &r);
            splay.flip(l, r);
            auto range = splay.root->r->l;
            printf("%d %d %lld\n", range->rangeMin, range->rangeMax, range->rangeSum);
        } else if (cmd == 2) {
            int l, r, x; scanf("%d %d %d", &l, &r, &x);
            splay.gather(l, r);
            auto range = splay.root->r->l;
            printf("%d %d %lld\n", range->rangeMin, range->rangeMax, range->rangeSum);
            splay.shift(l, r, x);
        } else if (cmd == 3) {
            int v; scanf("%d", &v);
            splay.kth(v);
            printf("%d\n", splay.root->key);
        } else if (cmd == 4) {
            int v; scanf("%d", &v);
            printf("%d\n", splay.getPos(v));
        }
    }
    splay.print();
}

int main() {
    solve();
    return 0;
}