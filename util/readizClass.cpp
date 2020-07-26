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
