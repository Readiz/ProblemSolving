#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <time.h>
static unsigned long long seed = 70;
static unsigned int random() {
	seed = seed * 214013 + 2531011;
	return (unsigned int)((seed >> 16) & 0x7fff);
}
static int nextint(int s, int t) {
	if (t - s + 1 <= 0x7fff) {
		return (int)(random() % (t - s + 1)) + s;
	}
	else {
		return (int)(((random() << 15) | random()) % (t - s + 1)) + s;
	}
}
typedef unsigned long long int ulld;
#define MAX_BIT_N 65536
#define N 1024
#define R 16
class CUSTOM_BITSET {
private:
	static int cnt;
	ulld a[N];
public:
	CUSTOM_BITSET() { for (register int i = 0; i < N; i++)a[i] = 0; }

	CUSTOM_BITSET& operator =(const CUSTOM_BITSET& z) {
		for (register int i = 0; i < N; i++)a[i] = z.a[i];
		return *this;
	}

	void operator &=(const CUSTOM_BITSET& z){
		for (register int i = 0; i < N; i++) {
			a[i] &= z.a[i];
		}
	}
	void operator |=(const CUSTOM_BITSET& z) {
		for (register int i = 0; i < N; i++) {
			a[i] |= z.a[i];
		}
	}
	void operator ^=(const CUSTOM_BITSET& z) {
		for (register int i = 0; i < N; i++) {
			a[i] ^= z.a[i];
		}
	}
	void operator <<=(const int xx) {
		if (xx <= 0)return;
		if (xx >= MAX_BIT_N) {
			for (register int i = 0; i < N; i++)a[i] = 0;
			return;
		}
		int big_step = xx >> 6;
		int small_step = xx & 63;
		ulld small_mask = (1uLL << small_step) - 1;
		for (register int i = N - 1; i - big_step - 1 >= 0; i--) {
			a[i] = (a[i - big_step] << small_step) | ((a[i - big_step - 1] & small_mask) >> (64 - small_step));
		}
		{
			register int i = big_step;
			a[i] = (a[i - big_step] << small_step);
		}
		for (register int i = big_step - 1; i >= 0; i--) {
			a[i] = 0;
		}
	}
	void operator >>=(const int xx) {
		if (xx <= 0)return;
		if (xx >= MAX_BIT_N) {
			for (register int i = 0; i < N; i++)a[i] = 0;
			return;
		}
		int big_step = xx >> 6;
		int small_step = xx & 63;
		ulld small_mask = (1uLL << small_step) - 1;
		for (register int i = 0; i + big_step + 1 < N; i++) {
			a[i] = (a[i + big_step] >> small_step) | ((a[i + big_step + 1] & small_mask) << (64 - small_step));
		}
		{
			register int i = N - big_step - 1;
			a[i] = (a[i + big_step] >> small_step);
		}
		for (register int i = N - big_step; i < N; i++) {
			a[i] = 0;
		}
	}

	void setbit(int i, bool v) {
		if (v) { a[i >> 6] |= 1uLL << (i & 63); }
		else{ a[i >> 6] &= ~(1uLL << (i & 63)); }
	}
	void setvalue(int i, ulld x) {
		a[i] = x;
	}
	bool getbit(int i) {
		cnt++;
		return (a[i >> 6] >> (i & 63)) & 1;
	}
	static int getcnt() {
		return cnt;
	}
};
extern int __builtout_popcount();

static CUSTOM_BITSET reg[R];
void copy(int dst_reg, int src_reg) {
	if (dst_reg < 0 && dst_reg >= R)return;
	if (src_reg < 0 && src_reg >= R)return;
	reg[dst_reg] = reg[src_reg];
}
void andop(int dst_reg, int src_reg) {
	if (dst_reg < 0 && dst_reg >= R)return;
	if (src_reg < 0 && src_reg >= R)return;
	reg[dst_reg] &= reg[src_reg];
}
void orop(int dst_reg, int src_reg) {
	if (dst_reg < 0 && dst_reg >= R)return;
	if (src_reg < 0 && src_reg >= R)return;
	reg[dst_reg] |= reg[src_reg];
}
void xorop(int dst_reg, int src_reg) {
	if (dst_reg < 0 && dst_reg >= R)return;
	if (src_reg < 0 && src_reg >= R)return;
	reg[dst_reg] ^= reg[src_reg];
}

void lshiftop(int dst_reg, int val) {
	if (dst_reg < 0 && dst_reg >= R)return;
	if (val < 0)return;
	reg[dst_reg] <<= val;
}
void rshiftop(int dst_reg, int val) {
	if (dst_reg < 0 && dst_reg >= R)return;
	if (val < 0)return;
	reg[dst_reg] >>= val;
}

void setbit(int dst_reg, int pos, bool bit) {
	if (dst_reg < 0 && dst_reg >= R)return;
	if (pos < 0 || pos >= MAX_BIT_N)return;
	reg[dst_reg].setbit(pos, bit);
}
bool getbit(int dst_reg, int pos) {
	if (dst_reg < 0 && dst_reg >= R)return false;
	if (pos < 0 || pos >= MAX_BIT_N)return false;
	return reg[dst_reg].getbit(pos);
}

// TC generate area

int CUSTOM_BITSET::cnt = 0;
static int ans;
static int ret;
static int tv = 0;
static int prev_cnt;
static int next_cnt;
static long runtime = 0;
const static int T = 100;
static int TC_PARAM[T][2] = {
	{0, 0},	{16, 16}, {0, 3},
	{4, 7},	{8, 11}, {12, 15},
	{0, 1}, {15, 16}, {8, 8},
	{2, 3}, {5, 11}, {1, 15},
	{0, 16}, {-1, -1},
};
static int TC_ORDER[T];
static int VALUE_CNT_CACHE[65536];
static int VALUE_TABLE[17][65536];
static int VL[17];
static void local_init() {
	// init VALUE_TABLE
	for (register int i = 0; i <= 16; i++) {
		VL[i] = 0;
	}
	VALUE_CNT_CACHE[0] = 0;
	VALUE_TABLE[0][VL[0]++] = 0;
	for (register int i = 1; i < (1 << 16); i++) {
		VALUE_CNT_CACHE[i] = VALUE_CNT_CACHE[i & (i - 1)] + 1;
		VALUE_TABLE[VALUE_CNT_CACHE[i]][VL[VALUE_CNT_CACHE[i]]++] = i;
	}

	for (register int i = 0; i < T; i++) {
		if (TC_PARAM[i][0] == -1) {
			while (i < T) {
				TC_PARAM[i][0] = TC_PARAM[i - 1][0];
				TC_PARAM[i][1] = TC_PARAM[i - 1][1];
				i++;
			}
		}
	}
	for (register int i = 0; i < T; i++) {
		TC_ORDER[i] = i;
	}
	for (register int i = 0; i < T - 1; i++) {
		register int ti = nextint(i, T - 1);
		if (i != ti) {
			int tmp = TC_ORDER[i];
			TC_ORDER[i] = TC_ORDER[ti];
			TC_ORDER[ti] = tmp;
		}
	}
}

static void build()
{
	ans = 0;
	for (register int i = 0; i < N; i++) {
		ulld x = 0;
		for (register int j = 0; j < 4; j++) {
			int ti = TC_ORDER[tv];
			int cnt = nextint(TC_PARAM[ti][0], TC_PARAM[ti][1]);
			ans += cnt;
			x <<= 16;
			x |= VALUE_TABLE[cnt][nextint(0, VL[cnt] - 1)];
		}
		reg[0].setvalue(i, x);
	}
}
static int run()
{
	prev_cnt = CUSTOM_BITSET::getcnt();
	long t1 = clock();
	ret = __builtout_popcount();
	long t2 = clock();
	runtime += (t2 - t1);
	next_cnt = CUSTOM_BITSET::getcnt();
	if (next_cnt - prev_cnt > 20) return 0;
	return ret == ans ? 1 : 0;
}


int main()
{
	int t = T;
	int mark = 0;
	int score = 100;

	seed = (unsigned long long int)time(NULL);

	scanf("%d", &mark);
	local_init();
	while (tv < t) {
		build();
		if (run() == 0) {
			score = 0;
			break;
		}
		tv++;
	}
	if (score == 100) {
		printf("PASS\n");
	}
	else {
		printf("FAIL!\n");
		if (mark == 0) {
			printf("ret : %d ans : %d call_cnt : %d\n", ret, ans, next_cnt - prev_cnt);
		}
	}
	if (mark == 0) {
		printf("run %d / %d\n", tv, t);
		printf("runtime : %ld ms\n", runtime * 1000 / CLOCKS_PER_SEC);
	}
	return 0;
}
