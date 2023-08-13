#include <stdio.h>

#define R register
#define _D(...) printf(__VA_ARGS__)

#define MAX_KIND 30 // 알파벳은 대략 26자
#define EMPTY 0

struct N { // Huffman Node
    char c;
    int val;
    N* l;
    N* r;
};

// 1부터 시작하는 Heap
#define parent(x) ((x) >> 1)
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) | 1)

// 최소힙
struct H {
    N d[MAX_KIND + 1]; // 1 ~ sz 접근 가능
    int sz; // 사이즈이자 마지막에 들어간 원소의 위치

    H() {
        sz = 0;
    }

    void push(N n) {
        d[++sz] = n;
        int p = sz;
        while (parent(p) > 0) {
            if (d[parent(p)].val > d[p].val) {
                N t = d[p];
                d[p] = d[parent(p)];
                d[parent(p)] = t;

                p = parent(p);
            } else {
                break;
            }
        }
    }

    N pop() {
        N r = d[1];
        d[1] = d[sz--];
        int p = 1;
        while (true) {
            if (right(p) <= sz) { // 좌 우 자식 비교 가능
                if (d[p].val > d[left(p)].val || d[p].val > d[right(p)].val) {
                    if (d[left(p)].val < d[right(p)].val) { // right 우선 스왑
                        N t = d[p];
                        d[p] = d[left(p)];
                        d[left(p)] = t;

                        p = left(p);
                    } else {
                        N t = d[p];
                        d[p] = d[right(p)];
                        d[right(p)] = t;

                        p = right(p);
                    }
                } else {
                    break;
                }
            } else if (left(p) <= sz) { // 좌측 자식만 비교 가능
                if (d[p].val > d[left(p)].val) {
                    N t = d[p];
                    d[p] = d[left(p)];
                    d[left(p)] = t;

                    p = left(p);
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        return r;
    }
    

    void print() {
        _D("---- PRINT -----\n");
        for (R int i = 1; i <= sz; ++i) {
            _D("[%3d] %c %d\n", i, d[i].c, d[i].val);
        }
        _D("---- PRINT END -----\n");
    }
};
H h;

int stack[1000];
int sp;

void travel(N* n) {
    if (n->l) {
        stack[sp++] = 0;
        travel(n->l);
        --sp;
    }
    if (n->r) {
        stack[sp++] = 1;
        travel(n->r);
        --sp;
    }
    if(n->c != EMPTY) {
        printf("%c: ", n->c);
        for (R int i = 0; i < sp; ++i) {
            printf("%d", stack[i]);
        }
        printf("\n");
    }
}
// encode string
char* str = "effective";
int main() {
    int cnt[300] = {0, };
    int l;
    for (l = 0; str[l] != 0; l++) {
        cnt[str[l]]++;
    }
    _D("LEN: %d\n", l);

    for (int p = 0; p < 300; ++p) {
        if (cnt[p] == 0) continue;
        _D("[%c] CNT: %d\n", p, cnt[p]);
        h.push({(char)p, cnt[p], NULL, NULL});
    }

    h.print();
    while (h.sz > 1) {
        _D("-------------------\nSZ: %d\n", h.sz);
        N* n1 = new N(h.pop());
        N* n2 = new N(h.pop());
        h.push({EMPTY, n1->val + n2->val, n1, n2});
        h.print();
    }
    _D("RESULT-----------------------------------\n");
    travel(&h.d[1]);
}