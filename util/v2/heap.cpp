#include <stdio.h>

#define R register
#define _D(...) printf(__VA_ARGS__)

#define MAX_SIZE 20000

struct D {
    int idx;
    int data;
};

#define parent(x) ((x) >> 1)
#define left(x) ((x) << 1)
#define right(x) (((x) << 1) | 1)
struct H { // Heap
    D d[MAX_SIZE + 1];
    int sz;
    void init() {
        for (R int i = 0; i ^ (MAX_SIZE + 1); ++i) {
            d[i].idx = -1;
            d[i].data = 0x7FFFFFFF; // INT MAX
        }
        sz = 0; // +1 한 위치가 다음 데이터 위치가 되도록 조정
    }
    void push(D _) {
        d[++sz] = _;
        int p = sz;
        while (parent(p) > 0) {
            if (d[p].data < d[parent(p)].data) { // MIN HEAP 이므로 부모가 더 작아양 함
                D t = d[p];
                d[p] = d[parent(p)];
                d[parent(p)] = t;
            }
            p = parent(p);
        }
    }
    D pop() {
        D r = d[1]; // 항상 최소값이 맨 위에 있다.
        d[1] = d[sz--];
        int p = 1;

        while (true) {
            if (right(p) <= sz) { // right, left 모두 사용 가능
                if (d[p].data > d[left(p)].data || d[p].data > d[right(p)].data) {
                    if (d[left(p)].data < d[right(p)].data) {
                        D t = d[p];
                        d[p] = d[left(p)];
                        d[left(p)] = t;

                        p = left(p);
                    } else {
                        D t = d[p];
                        d[p] = d[right(p)];
                        d[right(p)] = t;

                        p = right(p);
                    }
                } else {
                    break;
                }
            } else if (left(p) <= sz) { // left만 사용 가능
                if (d[p].data > d[left(p)].data) {
                    D t = d[p];
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
        for (R int i = 1; i <= sz; i++) {
            _D("%d ", d[i].data);
        }
        _D("\n");
    }
    int getSize() {
        return sz;
    }
};

H h;

unsigned long long seed = 5;
static unsigned short rnd() {
    return (unsigned short)((seed = seed * 25214903917ULL + 11ULL) >> 16);
}


void quickSort(int start, int end, D arr[]) {
    if (start > end) return;
    int pivot = arr[(start + end) >> 1].data;
    int i = start;
    int j = end;
    while (true) {
        while (arr[i].data < pivot) i++;
        while (arr[j].data > pivot) j--;
        if (i > j) break; // 엇갈리면 break
        // 여기에 등호가 들어가게 되면, i++, j-- 이 한번 덜 수행되어 꼬인다.

        D t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;

        i++; j--;
    }
    quickSort(start, j, arr);
    quickSort(i, end, arr);
}


int main() {
    h.init();

    h.push({1, 5});
    h.push({2, 10});
    h.push({3, 2});
    h.push({4, 1});
    
    while (h.getSize() > 0) {
        D d = h.pop();
        _D("%d ", d.data);
    }
    _D("\n");

    // Validation
    
    D tc[10000];
    for (R int i = 0; i ^ 10000; ++i) {
        int num = (((unsigned int)rnd() << 16) | rnd()) % 100000;
        tc[i].data = num;
        tc[i].idx = i;
        h.push(tc[i]);
    }
    quickSort(0, 10000 - 1, tc);
    for (R int i = 0; i ^ 10000; ++i) {
        D c = h.pop();
        _D("%d ", c.data);
        if (c.data == tc[i].data) {
            
        } else {
            _D("VALIDATION FAILED at %d!!\n", i);
            break;
        }
    }
    _D("\n");

}