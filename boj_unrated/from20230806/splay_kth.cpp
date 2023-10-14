#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    int rangeSum;
    int lazy;
    Node* l;
    Node* r;
    Node* p;
    int sz;

    void push() {
        if (lazy == 0) return;
        value += lazy;
        if (l) {
            l->lazy += lazy;
        }
        if (r) {
            r->lazy += lazy;
        }
        lazy = 0;
    }
    void update() {
        sz = 1;
        rangeSum = value;
        if (l) {
            rangeSum += l->rangeSum;
            sz += l->sz;
        }
        if (r) {
            rangeSum += r->rangeSum;
            sz += r->sz;
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
        if (l) l->printInorder();
        printf("%d ", key);
        if (r) r->printInorder();
    }
};
Node* newNode(int key, int value) {
    Node* ret = new Node();
    ret->key = key;
    ret->sz = 1;
    ret->rangeSum = ret->value = value;
    ret->lazy = 0;
    ret->l = ret->r = ret->p = 0;
    return ret;
}

struct SplayTree {
    Node* root;
    SplayTree() {
        root = 0;
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
        printf("kth key: %d\n", cur->key);
        cur->splay();
        root = cur;
        return true;
    }
    int query(int l, int r) {
        kth(l - 1);
        auto oldRoot = root;
        root = root->r;
        root->p = 0; // 임시
        kth(r - l + 1);

        int ret = root->l->rangeSum;

        root->p = oldRoot;
        root = oldRoot;  
        return ret;
    }
    void rangeUpdate(int l, int r, int v) {
        kth(l - 1);
        auto oldRoot = root;
        root = root->r;
        root->p = 0; // 임시
        kth(r - l + 1);

        root->l->lazy += v;

        root->p = oldRoot;
        root = oldRoot;
    }
    bool insert(int key, int value) {
        auto newOne = newNode(key, value);
        if (root == 0) {
            root = newOne; // no need to splay
            return true;
        }
        auto cur = root;
        while(true) {
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
    void find(int key) {
        if (root == 0) return;
        auto cur = root;
        while(true) {
            if (cur->key == key) {
                // 중복 원소 존재!
                break;
            } else if (key < cur->key) {
                if (cur->l == 0) {
                    break;
                }
                cur = cur->l;
            } else {
                if (cur->r == 0) {
                    break;
                }
                cur = cur->r;
            }
        }
        cur->splay();
        root = cur;
    }
    bool erase(int key) {
        find(key);
        if (root == 0) return false;
        if (root->key != key) return false;

        // root에 key가 있다
        Node* l = root->l;
        Node* r = root->r;
        delete root;

        if (l) {
            l->p = 0;

            while(l->r) l = l->r;
            l->splay(); // left의 max를 splay 하면 우측 자식은 비어있다.
            l->r = r;
            if (r) {
                r->p = l;
            }
            root = l;
        } else if (r) {
            r->p = 0;

            root = r;
        } else {
            root = 0;
        }
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
                level[cur.second].push_back(cur.first->key);
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


int main() {
    // test code
    splay.insert(0, 0);
    for(int i = 1; i <= 10; ++i) {
        splay.insert(i, i);
    }
    splay.insert(11, 0);

    printf("[d] %d\n", splay.query(1, 10));
    splay.rangeUpdate(1, 10, 1);
    printf("[d] %d\n", splay.query(1, 10));
    return 0;
}