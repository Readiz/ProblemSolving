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

struct Data {
    int val;
    int idx;
    bool operator<(const Data& t) const {
        if (val != t.val) return val < t.val;
        return idx < t.idx;
    }
};

int N;
struct Node {
    int key;
    Data data;
    Node* l;
    Node* r;
    Node* p;
    int sz;
    Data rangeMin;
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
        if (l) {
            sz += l->sz;
            rangeMin = min(rangeMin, l->rangeMin);
        }
        if (r) {
            sz += r->sz;
            rangeMin = min(rangeMin, r->rangeMin);
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
} n[100'010];
int nSz;
Node* newNode(int key, int value) {
    Node* ret = &n[nSz++];
    ret->key = key;
    ret->sz = 1;
    ret->isFlip = false;
    ret->data = ret->rangeMin = {value, key};
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
    Data rangeMin(int l, int r) {
        gather(l, r);
        return root->r->l->rangeMin;
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
                level[cur.second].push_back(cur.first->data.val);
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

    splay.insert(0, 987654321); // guard
    for(int i = 1; i <= N; ++i) {
        splay.insert(i, i); // n[i] -> i번째 추가된 녀석
    }
    splay.insert(N + 1, 987654321); // guard

    // printf("3 pos: %d\n", n[3].getPos());
    // splay.printLevel();

    for(int q = 0; q < Q; ++q) {
        int num, toNum; scanf("%d %d", &num, &toNum);
        int curPos = splay.getPos(num);
        int toPos = splay.getPos(toNum);
        // printf("[d] cur: %d / pos: %d\n", num, curPos);
        // printf("[d] cur: %d / topos: %d\n", toNum, toPos);

        if (curPos < toPos) {
            splay.flip(curPos, toPos);
            splay.flip(curPos, toPos - 1);
            printf("%d\n", toPos - curPos);
        } else {
            splay.flip(toPos + 1, curPos);
            splay.flip(toPos + 2, curPos);
            printf("%d\n", toPos - curPos + 1);
        }
    }
    splay.print();
}

int main() {
    solve();
    return 0;
}