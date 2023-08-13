#include "tp.cpp"

#define MAX_BIT_N 65536
#define R 16

extern void copy(int dst_reg, int src_reg);
extern void andop(int dst_reg, int src_reg);
extern void orop(int dst_reg, int src_reg);
extern void xorop(int dst_reg, int src_reg);

extern void lshiftop(int dst_reg, int val);
extern void rshiftop(int dst_reg, int val);

extern void setbit(int dst_reg, int pos, bool bit);
extern bool getbit(int dst_reg, int pos);

void add() {
	for (int i = 0; i < 20; ++i) {
		// SUM : XOR
		// CARRY : AND
		copy(14, 12); // 12: a, 14: sum, 15: carry
		copy(15, 12); // 13: b
		
		xorop(14, 13);
		andop(15, 13);
		lshiftop(15, 1);

		copy(12, 14); // sum -> a
		copy(13, 15); // carry -> b
	}
	// 결과: 0번에 저장
	copy(0, 12);
}

struct INIT {
	INIT() {
		for (int i = 0, step = 1; i < 10; ++i, step *= 2) {
			bool cursor = 0;
			for (register int c = 0; c < 65536; ++c) {
				if (c % step == 0) {
					cursor ^= 1;
				}
				setbit(i + 1, c, cursor); // 1 ~ 10은 미리 채워두기
			}
		}
		printf("INIT END!\n");
	}
} init;

//return the number of bits on reg[0]
int __builtout_popcount() {
	for (int i = 0, step = 1; i < 16; ++i, step *= 2) {
		int t = -1;
		if (i < 10) t = i + 1;
		else {
			t = 11;
			bool cursor = 0;
			for (register int c = 0; c < 65536; ++c) {
				if (c % step == 0) {
					cursor ^= 1;
				}
				setbit(11, c, cursor);
			}
		}
		copy(12, 0);
		copy(13, 0);
		rshiftop(13, step);

		andop(12, t);
		andop(13, t);

		add();
	}

	int res = 0;
	int mask = 1;
	for (int i = 0; i < 20; ++i, mask <<= 1) {
		if (getbit(0, i)) res |= mask;
	}
	return res;
}