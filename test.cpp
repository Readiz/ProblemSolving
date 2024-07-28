#include <stdio.h>

#define _D(...) printf(__VA_ARGS__)
#define FOR(i,a,b) for(register int i=(a);i<(b);++i)


unsigned int seed = 5;
int prand() {
	seed = seed * 214013 + 2531011;
	return (seed >> 16) & 0x7FFF;
}

template <typename T>
struct Vector {
	T* d;
	int sz, capa;
	Vector() { sz = 0; capa = 1; d = new T[capa]; }
	void clear() {
		sz = 0;
	};
	~Vector() { delete[] d; }
	void push_back(T x) {
		if (capa == sz) {
			capa <<= 1;
			auto nd = new T[capa];
			FOR(i, 0, sz) nd[i] = d[i];
			delete[] d;
			d = nd;
		}
		d[sz++] = x;
	}
	void removeAt(int i) {
		d[i] = d[--sz];
	}
	T* begin() { return &d[0]; }
	T* end() { return &d[sz]; }
	T& operator[](int idx) { return d[idx]; }
};
template <typename T>
void zwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
struct MinHeap {
	int sz;
	Vector<T> h;
	MinHeap(T x) { h.push_back(x); sz = 0; } // add dummy
	void push(T x) {
		h.push_back(x); ++sz;
		int c = sz;
		for (; c > 1; c >>= 1) {
			int p = c >> 1;
			if (h[p] > h[c]) zwap(h[p], h[c]);
			else break;
		}
	}
	T pop() {
		T ret = h[1];
		h.removeAt(1); --sz;
		int c = 2;
		for (; c <= sz; c <<= 1) {
			if (c + 1 <= sz && h[c + 1] < h[c]) c++;
			int p = c >> 1;
			if (h[p] > h[c]) zwap(h[p], h[c]);
			else break;
		}
		return ret;
	}
};

int main() {
	MinHeap<int> h1(0);
	FOR(i, 0, 100) {
		int a = prand();
		h1.push(a);
	}


	while (h1.sz) {
 		auto top = h1.pop();
		_D("%d\n", top);
	}


	return 0;
}