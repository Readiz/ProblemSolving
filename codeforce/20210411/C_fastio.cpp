#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
#define SZ 1'000'000'000
char read_buf[SZ], write_buf[SZ];

namespace IO {
	int read_idx, next_idx, write_idx;
	bool __END_FLAG__;
	inline bool is_blank(char c) { return c == ' ' || c == '\n'; }
	inline bool is_end(char c) { return c == '\0'; }
	inline char _readChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	inline char readChar() {
		char ret = _readChar();
		while (is_blank(ret)) ret = _readChar();
		return ret;
	}
	template<typename T>
	inline T _readInt() {
		T ret = 0;
		char cur = _readChar();
		bool flag = 0;
		while (is_blank(cur)) cur = _readChar();
		if (cur == '-') flag = 1, cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret = 10 * ret + cur - '0', cur = _readChar();
		if (is_end(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	inline int readInt() { return _readInt<int>(); }
	inline long long readLL() { return _readInt<long long>(); }
	inline string readString() {
		string ret;
		char cur = _readChar();
		while (is_blank(cur)) cur = _readChar();
		while (!is_blank(cur) && !is_end(cur)) ret.push_back(cur), cur = _readChar();
		if (is_end(cur)) __END_FLAG__ = 1;
		return ret;
	}
	inline double readDouble() {
		string ret = readString();
		return stod(ret);
	}
	template<typename T>
	inline int getSize(T n) {
		int ret = 1;
		if (n < 0) n = -n;
		while (n >= 10) ret++, n /= 10;
		return ret;
	}
	inline void bflush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	inline void writeChar(char c) {
		if (write_idx == SZ) bflush();
		write_buf[write_idx++] = c;
	}
	inline void newLine() { writeChar('\n'); }
	template<typename T>
	inline void _writeInt(T n) {
		int sz = getSize(n);
		if (write_idx + sz >= SZ) bflush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz - 1; i >= 0; i--) write_buf[write_idx + i] = n % 10 + '0', n /= 10;
		write_idx += sz;
	}
	inline void writeInt(int n) { _writeInt<int>(n); }
	inline void writeLL(long long n) { _writeInt<long long>(n); }
	inline void writeString(string s) { for (auto& c : s) writeChar(c); }
	inline void writeDouble(double d) { writeString(to_string(d)); }
}
using namespace IO;

#undef fastio
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT

struct INPUT{ explicit operator bool() { return !__END_FLAG__; } } _in;
INPUT& operator>> (INPUT& in, char& i) { i = readChar(); return in; }
INPUT& operator>> (INPUT& in, int& i) { i = readInt(); return in; }
INPUT& operator>> (INPUT& in, long long& i) { i = readLL(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = readString(); return in; }
INPUT& operator>> (INPUT& in, double& i) { i = readDouble(); return in; }

struct OUTPUT{ ~OUTPUT() { bflush(); } } _out;
OUTPUT& operator<< (OUTPUT& out, char i) { writeChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, int i) { writeInt(i); return out; }
OUTPUT& operator<< (OUTPUT& out, long long i) { writeLL(i); return out; }
OUTPUT& operator<< (OUTPUT& out, size_t i) { writeInt(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { writeString(i); return out; }
OUTPUT& operator<< (OUTPUT& out, double i) { writeDouble(i); return out; }
/////////////////////////////////////////////////////////////////////////////////////////////

#define MOD 1'000'000'007
typedef long long ll;

int main() {
    fastio;
    int tc;
    cin >> tc;
    for (register int TC = 0; TC < tc; TC++) {
        int N, M;
        cin >> N >> M;
        ll dp[10];
        for (register int i = 0; i < 10; i++) dp[i] = 0ll;
        while (N > 0) {
            dp[N % 10]++;
            N /= 10;
        }
        int p = 9;
        // 초기값 세팅
        ll sum = 0ll;
        for (register int i = 0; i < 10; i++) {
            sum = (sum + dp[i]) % MOD;
        }
        for (register int i = 0; i < M; i++) {
            dp[(p + 2) % 10] = (dp[(p + 2) % 10] + dp[p]) % MOD;
            sum = (sum + dp[p]) % MOD;
            p--;
            if (p < 0) p = 9;
        }
        cout << sum << '\n';
    }
    return 0;
}