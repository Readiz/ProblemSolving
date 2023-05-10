#include <cstdio>

int main() {
	int n;
	scanf("%d", &n);
	n += 0xABFF;
	printf(
		"%c%c%c\n",
		0xE0 | (n >> 0xC),
		0x80 | (n >> 0x6 & 0x3F),
		0x80 | (n & 0x3F)
	);
}