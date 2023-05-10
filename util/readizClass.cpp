class DicString {
public:
    char str[52];
    int length;
    DicString(char* mStr) {
        for (int p = 0; ; p++) {
            str[p] = mStr[p];
            if (mStr[p] == 0) {
                length = p;
                break;
            }
        }
    }
    bool operator==(DicString p) {
        if (this->length != p.length) return false;

        for (int i = 0; i < p.length; i++) {
            if (this->str[i] == p.str[i]) continue;
            else return false;
        }
        return true;
    }
    bool operator!=(DicString p) {
        return !(*this == p);
    }
    bool operator<(DicString p) {
        if (this->length != p.length) {
            return this->length < p.length;
        } else {
            for (int i = 0; i < p.length; i++) {
                if (this->str[i] == p.str[i]) continue;
                else return this->str[i] < p.str[i];
            }
            return false;
        }
    }
};

class Member {
public:
    char name[102];
    int age;
    int id;
    Member(int id, int age, char* mName) {
        this->id = id;
        this->age = age;
        for (int p = 0; ; p++) {
            this->name[p] = mName[p];
            if (mName[p] == 0) { // NULL 까지 복사가 되어야 하므로.
                break;
            }
        }
    }

    bool operator<(Member p) {
        if (this->age != p.age) {
            return this->age < p.age;
        } else {
            return this->id < p.id;
        }
    }
};

template<class T>
class DArray {
    T* n;
    int capacity;
public:
    int size;
    DArray() {
        size = 0;
        capacity = 100;
        n = new T[capacity];
    }
    void push(T item) {
        // 공간 다 찼을 경우.. 늘린다.
        if (size == capacity) {
            capacity *= 2; // 두배로 늘린다.
            T* newNodes = new T[capacity];
            for (int i = 0; i < size; i++) {
                newNodes[i] = n[i]; // 기존 값 복사
            }
            delete[] n;
            n = newNodes;
        }
        n[size++] = item;
    }
    T& pop() {
        return n[--size];
    }
    T& operator[] (int idx) {
        return n[idx];
    }
    ~DArray() {
        delete[] n;
    }
};

// DArray가 사실 Stack 그 자체임.
template<class T>
class Stack {
    DArray<T> db;
public:
    Stack() {
    };
    void push(T n) {
        db.push(n);
    }
    T& pop() {
        return db.pop();
    }
    int getSize() {
        return db.size;
    }
};

template<class T>
class Queue {
    DArray<T> db;
    int startPos;
public:
    Queue() {
        startPos = 0;
    };
    void enqueue(T n) {
        db.push(n);
    }
    T& dequeue() {
        return db[startPos++];
    }
    int getSize() {
        return db.size - startPos;
    }
};


// Queue version 2
typedef struct {
    int x;
    int y;
} Point;

template<class T>
class Queue {
    T* n;
    int cap;
    int size;
    int startPos;
public:
    Queue() {
        init();
    }
    void init() {
        cap = 1000;
        size = 0;
        startPos = 0;
        n = new T[cap];
    }
    void enqueue(T data) {
        if (size == cap) {
            cap *= 2;
            T* newNodes = new T[cap];
            for (int i = 0; i < size; i++) {
                newNodes[i] = n[i];
            }
            delete[] n;
            n = newNodes;
        }
        n[size++] = data;
    }
    T& dequeue() {
        return n[startPos++];
    }
    int getSize() {
        return size - startPos;
    }
};
Queue<Point> q;