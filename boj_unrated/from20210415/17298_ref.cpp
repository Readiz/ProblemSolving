// Copyright 2020 <jehan.yoon>
#include <cstdio>
#include <algorithm>
namespace fio {
  constexpr size_t BUF_SIZ = 0x8'0000, SPARE = 20;
  char buf_i[BUF_SIZ], *p_in = buf_i, *p_max = p_in;

  inline char getCh(void) {
    if (p_in == p_max) {
      p_max = buf_i + fread(buf_i, 1, BUF_SIZ, stdin);
      p_in = buf_i;
    }
    return (p_in != p_max) ? *(p_in++) : -1;
  }

  template<typename T>
  inline T get(void) {
    int t, sign = 1;
    T r = 0;
    do {
      t = getCh();
    } while (t != '-' && (t < '0' || t > '9'));
    if (t == '-')  sign = -1, t = getCh();
    while (true) {
      r = r * 10 + t - '0'; t = getCh();
      if (t < '0' || t > '9')    break;
    }
    return r * sign;
  }

  char buf_o[BUF_SIZ + SPARE], *p_out = buf_o;

  template<typename T>
  void prt(T n, char delim = ' ') {
    if (n < 0) n = -n, *p_out++ = '-';
    char *ptr = p_out;
    do { *ptr++ = n % 10 + '0';  n /= 10; } while (n);
    std::reverse(p_out, ptr);
    *ptr++ = delim;
    if (ptr < buf_o + BUF_SIZ) {
      p_out = ptr;
    } else {
      fwrite(buf_o, ptr - buf_o, 1, stdout); p_out = buf_o;
    }
  }

  inline void prtn(void) {
    *p_out++ = '\n';
    if (p_out >= buf_o + BUF_SIZ)
    { fwrite(buf_o, p_out - buf_o, 1, stdout); p_out = buf_o; }
  }

  void flush(void) {
    fwrite(buf_o, p_out - buf_o, 1, stdout);
    p_out = buf_o;
  }
};  // namespace fio
///////////////////////////
#include <vector>
#include <stack>
#include <utility>
using std::stack, std::vector;
typedef std::pair<int, int> p_ii;
constexpr int INF = 1'000'000'000, MAXN = 1'000'000;

int main(void) {
#ifdef JH_DEBUG
  freopen("17298_input.txt", "rt", stdin);
#endif
  int N = fio::get<int>(), num;

  vector<int> ans(N + 1, -1);
  stack<p_ii> stk;
  stk.emplace(INF, 0);
  for (int n = 1; n <= N; n++) {
    num = fio::get<int>();
    while (num > stk.top().first) {
      ans[stk.top().second] = num;
      stk.pop();
    }
    stk.emplace(num, n);
  }
  for (int i = 1; i <= N; i++)  fio::prt(ans[i]);
  fio::flush();

  return 0;
}
