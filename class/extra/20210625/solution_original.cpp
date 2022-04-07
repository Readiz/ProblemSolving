#include "main.cpp"
#include <stdio.h>

#include <list>
using namespace std;

#define printd(...) // printf(__VA_ARGS__)
bool isDebug = false;
#define R register
#define MAX_CACHE 100000

list<int> db;
int cache[MAX_CACHE];
// cache[12340] <- mHeight이 2, 3, 4, 5, 1 로 왔을 때 해당 값이 1 증가.

inline int makeHashVal(list<int>::iterator itr) {
	// Min 값을 찾는다
	int min = *itr;
	int v[5] = {0, 0, 0, 0, min};
	for (R int i = 3; i >= 0; i--) {
		if (itr == db.begin()) return -1;
		itr--;
		v[i] = *itr;
		if (v[i] < min) min = v[i];
	}
	int r = (v[0] - min) * 10000 + (v[1] - min) * 1000 + (v[2] - min) * 100 + (v[3] - min) * 10 + (v[4] - min);
	return r;
}
inline int makeHashVal(int v[5]) {
	// Min 값을 찾는다
	int min = v[4];
	for (R int i = 3; i >= 0; i--) {
		if (v[i] < min) min = v[i];
	}
	int r = (v[0] - min) * 10000 + (v[1] - min) * 1000 + (v[2] - min) * 100 + (v[3] - min) * 10 + (v[4] - min);
	// printd("[HASH] result: %05d\n", r);
	return r;
}

inline void addCacheVal(int v) {
    if (v >= 0) cache[v] += 1;
}

inline void deleteCacheVal(int v) {
	if (v >= 0) cache[v] -= 1;
}

// 기존과 맞물리는 녀석이 있는지 확인
// ex)
// 01222이 cache 되어 있는 상태를 가정,
// 이 경우 맞물리려면 54333, 43222, 32111, 21000 등이 맞물리게 된다.
// 맞물리는 값을 구하려면, 최소값을 뺀 다음, 최대값과의 차이를 구하면 된다.
// * 뒤집혀서 꽂히게 되는 것에 유의.
inline int checkCache(int v[5]) {
	// 뒤집기
	int t1 = v[4], t2 = v[3];
	v[4] = v[0]; v[3] = v[1];
	v[0] = t1; v[1] = t2;

	// 최대최소 구하기
	int min = v[0], max = v[0];
	for (R int i = 1; i < 5; i++) {
		if (v[i] < min) min = v[i];
		if (v[i] > max) max = v[i];
	}
	max -= min;

	// 최소값 빼기 + 최대값과의 차이 구하기
	for (R int i = 0; i < 5; i++) {
		v[i] -= min;
		v[i] = max - v[i];
	}

	int r = makeHashVal(v);
	if (cache[r] == 0) { // Not found
		return -1;
	} else {
		return r;
	}
}

void init()
{
	printd("------------------------------------------ Init\n");
	db.clear();
	for (R int i = 0; i < MAX_CACHE; i++) {
        cache[i] = 0;
    }
}

void makeWall(int mHeights[5])
{
	printd("[MAKE] --------- Input: %d, %d, %d, %d, %d\n", mHeights[0], mHeights[1], mHeights[2], mHeights[3], mHeights[4]);
	if (db.size() == 0) {
		// 맨 처음 값을 넣는 경우 -> cache에 값 1개밖에 들어가지 않는다.
		for (R int i = 0; i < 5; i++) {
			db.push_back(mHeights[i]);
		}
		addCacheVal(makeHashVal(--db.end()));
	} else {
		// 이 경우에는 이미 값이 1개 이상 있는 경우이기 때문에 다섯번 cache 된다.
		for (R int i = 0; i < 5; i++) {
			db.push_back(mHeights[i]);
			addCacheVal(makeHashVal(--db.end()));
		}
	}
}

int matchPiece(int mHeights[5])
{
	printd("[MATCH] --------- Input: %d, %d, %d, %d, %d\n", mHeights[0], mHeights[1], mHeights[2], mHeights[3], mHeights[4]);

	if (isDebug) {
		printd("     Current db(size: %d): ", db.size());
		for (list<int>::iterator itr = db.begin(); itr != db.end(); itr++) {
			printd("%d ", *itr);
		}
		printd("\n");
	}

	int c = checkCache(mHeights);
	if (c == -1) {
		printd("[MATCH] No result matched, skip.\n");
		return -1;
	}

	// 캐시된 데이터에 해당 항목이 있으므로, 찾기 시작한다. (일단 있다는 것까지는 확인됨)
	printd("[MATCH] find matched!!!! checkVal: %05d\n", c);
	int p = db.size() - 4; // 뒤 부터 순회함
	for (list<int>::iterator itr = --db.end(); itr != db.begin(); itr--) {
		int curHash = makeHashVal(itr);
		// printd("[MATCH] pos: %d, curHash: %05d, checkVal: %05d\n", p, curHash, c);
		if (curHash == c) {
			printd("[MATCH] Found pos!!! pos: %d\n", p);

			// Cache 삭제 (현재 위치 + 좌측으로 4개 + 우측으로 4개 -> 총 9개)
			list<int>::iterator citr = itr;
			for (R int i = 0; i < 4; i++) {
				citr++;
				if (citr == db.end()) break;
				deleteCacheVal(makeHashVal(citr));
			}
			citr = itr;
			deleteCacheVal(makeHashVal(citr));
			for (R int i = 0; i < 4; i++) {
				if (citr == db.begin()) break;
				citr--;
				deleteCacheVal(makeHashVal(citr));
			}

			// List 에서 아이템 삭제 (5개)
			for (R int i = 0; i < 5; i++) {
				list<int>::iterator nextitr = --itr; // 삭제 후의 iterator는 날아가기 때문에, 복사하여 사용한다.
				db.erase(++itr);
				itr = nextitr;
			}

			// Cache 추가 (새로 붙는 부분)
			citr = itr;
			for (R int i = 0; i < 4; i++) { // 5는 자기 자신이고 이미 포함되어 있으므로 넣지 않는다.
				citr++;
				if (citr == db.end()) break; // 우측으로는 없을 수도 있으므로 확인
				addCacheVal(makeHashVal(citr));
			}

			// position 리턴
			return p;
		}
		p--;
		if (p <= 0) break;
	}

	printd("[DEBUG PT!], cache failed!\n");
	return -1;
}