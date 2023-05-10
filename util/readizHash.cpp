typedef enum
{
	NAME,
	NUMBER,
	BIRTHDAY,
	EMAIL,
	MEMO
} FIELD;

typedef struct
{
	int count;
	char str[20];
} RESULT;

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
#define printd(...)
#define MAX_RECORD_NUM 50000
#define MAX_TABLE 500000 // 10배로 잡아서 성능 올리자..

inline bool m_strcmp(const char *a, const char *b) {
	int i;
	for (i = 0; a[i] != '\0'; ++i) if (a[i] != b[i]) return false;
	return true;
}

inline void m_strcpy(char *dest, const char *src) {
	int i = 0;
	while (src[i] != '\0') { dest[i] = src[i]; i++; }
	dest[i] = src[i];
	dest[i + 1] = 0;
}

template<class T>
class DArray {
	int capacity;
	int size;
	T* n;
public:
	DArray() {
		size = 0;
		capacity = 2;
		n = new T[capacity];
	}
	void reset() {
		delete[] n;
		size = 0;
		capacity = 2;
		n = new T[capacity];
	}
	void push(T tNode) {
		if (size == capacity) { // 이미 DArray가 다 찼을 경우, 늘린다.
			T* newNodes = new T[capacity * 2];
			for (int i = 0; i < size; i++) {
				newNodes[i] = n[i];
			}
			delete[] n;
			n = newNodes;
			capacity *= 2;
		}
		n[size] = tNode;
		size++;
	}
	void pop() { // 마지막 노드를 지운다.
		size--;
	}
	int getSize() {
		return size;
	}
	T& operator[] (int idx) {
		if (idx >= size) {
			printd("[ERROR] DArray overflow! cannot access to idx: %d", idx);
		}
		return n[idx];
	}
	// DArray<T>& operator= (DArray<T>& d) {
	// 	for (int i = 0; i < d.getSize(); i++) {
	// 		this->push(d.n[i]);
	// 	}
	// 	return (*this);
	// }
	~DArray() {
		delete[] n;
	}
};

typedef struct __NODE {
	char name[21];
	char number[21];
	char birthday[21];
	char email[21];
	char memo[21];
	bool isDeleted;
} Record;

Record records[MAX_RECORD_NUM];

class HashTable {
	DArray<int> db[MAX_TABLE];
	int hash(const char *str)
	{
		unsigned int hash = 5381;
		int c;

		while (c = *str++)
		{
			hash = (((hash << 5) + hash) + c) % MAX_TABLE;
		}

		return (int) hash % MAX_TABLE;
	}
public:
	void init() {
		for (int i = 0; i < MAX_TABLE; i++) {
			db[i].reset();
		}
	}
	void addTable(char s[], int recordIdx) {
		int hVal = hash(s);
		// printd("      [INFO] %s -> %d\n", s, hVal);
		db[hVal].push(recordIdx);
	}
	DArray<int>& getDB(char s[]) {
		int hVal = hash(s);
		// printd("      [INFO] %s -> %d\n", s, hVal);
		return db[hVal];
	}
};

HashTable hTable[5]; // Array Index는 Field Num 임


class RecordManager {
	int size;
public:
	RecordManager() {
		init();
	}
	void init() {
		size = 0;
		for (int i = 0; i < MAX_RECORD_NUM; i++) {
			records[i].isDeleted = false;
			records[i].name[0] = 0;
			records[i].number[0] = 0;
			records[i].birthday[0] = 0;
			records[i].email[0] = 0;
			records[i].memo[0] = 0;
		}
	}
	void addRecord(char* name, char* number, char* birthday, char* email, char* memo) {
		// Record에 아이템을 추가한다.
		int idx = size;
		m_strcpy(records[idx].name, name);
		m_strcpy(records[idx].number, number);
		m_strcpy(records[idx].birthday, birthday);
		m_strcpy(records[idx].email, email);
		m_strcpy(records[idx].memo, memo);
		size++;
		// 각 필드별로 해시값에 추가해준다.
		hTable[NAME].addTable(name, idx);
		hTable[NUMBER].addTable(number, idx);
		hTable[BIRTHDAY].addTable(birthday, idx);
		hTable[EMAIL].addTable(email, idx);
		hTable[MEMO].addTable(memo, idx);
		printd("      Record added, idx: %d\n", idx);
	}
	void internalSearch(FIELD field, char s[], DArray<int>& r) {
		DArray<int>& da = hTable[field].getDB(s);
		printd("      Searched Data(by record Idx): ");
		for (int i = 0; i < da.getSize(); i++) {
			printd("%d ", da[i]);
			// 해시 결과, 진짜로 같은 녀석들이고, 지워지지 않은 놈들만 추가
			if (records[da[i]].isDeleted == true) continue;
			switch (field) {
				case NAME:
				if (m_strcmp(records[da[i]].name, s)) {
					r.push(da[i]);
				}
				break;
				case NUMBER:
				if (m_strcmp(records[da[i]].number, s)) {
					r.push(da[i]);
				}
				break;
				case BIRTHDAY:
				if (m_strcmp(records[da[i]].birthday, s)) {
					r.push(da[i]);
				}
				break;
				case EMAIL:
				if (m_strcmp(records[da[i]].email, s)) {
					r.push(da[i]);
				}
				break;
				case MEMO:
				if (m_strcmp(records[da[i]].memo, s)) {
					r.push(da[i]);
				}
				break;
			}
		}
		printd("\n");
	}
	void searchRecord(FIELD field, char s[], FIELD rfield, RESULT& result) {
		DArray<int> r;
		internalSearch(field, s, r);

		// Result 구성
		result.count = r.getSize();
		if (result.count == 1) {
			switch (rfield) {
				case NAME:
				m_strcpy(result.str, records[r[0]].name);
				printd("      Checked Val: %s\n", records[r[0]].name);
				break;
				case NUMBER:
				m_strcpy(result.str, records[r[0]].number);
				printd("      Checked Val: %s\n", records[r[0]].number);
				break;
				case BIRTHDAY:
				m_strcpy(result.str, records[r[0]].birthday);
				printd("      Checked Val: %s\n", records[r[0]].birthday);
				break;
				case EMAIL:
				m_strcpy(result.str, records[r[0]].email);
				printd("      Checked Val: %s\n", records[r[0]].email);
				break;
				case MEMO:
				m_strcpy(result.str, records[r[0]].memo);
				printd("      Checked Val: %s\n", records[r[0]].memo);
				break;
			}
		}
		printd("      Result field str: %s\n", result.str);
	}
	int deleteRecord(FIELD field, char s[]) {
		DArray<int> r;
		internalSearch(field, s, r);

		for (int i = 0; i < r.getSize(); i++) {
			records[r[i]].isDeleted = true;
		}
		return r.getSize();
	}
	int changeRecord(FIELD field, char s[], FIELD rfield, char st[]) {
		DArray<int> r;
		internalSearch(field, s, r);

		for (int i = 0; i < r.getSize(); i++) {
			// 새롭게 변경된 값으로 hTable에 추가해야함을 잊지 말기
			hTable[rfield].getDB(st).push(r[i]);
			switch (rfield) {
				case NAME:
				m_strcpy(records[r[i]].name, st);
				break;
				case NUMBER:
				m_strcpy(records[r[i]].number, st);
				break;
				case BIRTHDAY:
				m_strcpy(records[r[i]].birthday, st);
				break;
				case EMAIL:
				m_strcpy(records[r[i]].email, st);
				break;
				case MEMO:
				m_strcpy(records[r[i]].memo, st);
				break;
			}
		}
		return r.getSize();
	}
};

RecordManager rManager;

void InitDB()
{
	printd("---------------------------------------------------------------\n");
	rManager.init();
	for (int i = 0; i < 5; i++) {
		hTable[i].init();
	}
}

void Add(char* name, char* number, char* birthday, char* email, char* memo)
{
	printd("[ADD] %s / %s / %s / %s / %s\n", name, number, birthday, email, memo);
	rManager.addRecord(name, number, birthday, email, memo);
}

int Delete(FIELD field, char* str)
{
	printd("[DELETE] field: %d / val: %s\n", field, str);
	int r = rManager.deleteRecord(field, str);
	return r;
}

int Change(FIELD field, char* str, FIELD changefield, char* changestr)
{
	printd("[CHANGE] field: %d / val: %s -> %s on %d\n", field, str, changestr, changefield);
	int r = rManager.changeRecord(field, str, changefield, changestr);
	return r;
}

RESULT sresult;
RESULT Search(FIELD field, char* str, FIELD ret_field)
{
	printd("[SEARCH] field: %d / val: %s\n", field, str);
	
	rManager.searchRecord(field, str, ret_field, sresult);
	return sresult;
}
