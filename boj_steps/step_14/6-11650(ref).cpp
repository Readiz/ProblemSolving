#include <algorithm>
#include <unistd.h>
using namespace std;

namespace io
{
	const int is = 1 << 15, os = 1 << 15;
	char ib[is + 8], ob[os + 8], t[8];
	char *i = ib, *o = ob, *e = ob + os;

	inline char get()
	{
		if(*i <= 0) ib[read(0, i = ib, is)] = 0;
		return *i;
	}
	inline char getc()
	{
		while(get() <= ' ') i++;
		return *i;
	}
	inline int scan()
	{
		int x = 0, n = 0;
		for(i += n = getc() == '-'; get() >= '0'; i++)
		x = (x * 10) + (*i & 15);
		return n ? -x : x;
	}

	inline void put()
	{
		*o = 0;
		write(1, o = ob, o - ob);
	}
	inline void print(char c)
	{
		*o++ = c;
		if(o >= e) put();
	}
	inline void print(int x)
	{
		int p = 0, n = 0;
		if(x < 0) n = 1, x = -x;
		do t[p++] = x % 10 | 48, x /= 10; while(x);
		if(n) *o++ = '-';
		while(p--) *o++ = t[p];
		*o++ = ' ';
		if(o >= e) put();
	}
	
	struct f{~f(){put();}} flusher;
}

int main()
{
  int n = io::scan();
  pair<int, int> a[100000];
  
  for(int i = 0; i < n; i++)
    a[i] = {io::scan(), io::scan()};
  
  sort(a, a + n);
  for(int i = 0; i < n; i++)
    io::print(a[i].first), io::print(a[i].second);
}
