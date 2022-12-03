#include <cstdint>
#include <iostream>

using namespace std;
using tp = int64_t;
constexpr tp Hat_N = 1.1e7 + 3;

char s[Hat_N << 1];
tp p[Hat_N << 1];
tp n;

void Read() {
  char *t = new char[Hat_N], *ptr = t;
  cin.rdbuf()->sgetn(t, Hat_N);
  s[++n] = '#';
  s[++n] = '\a';
  while (*ptr) {
    s[++n] = *ptr++;
    s[++n] = '\a';
  }
  delete[] t;
}

signed main() {
  tp tar = 0;
  Read();
  for (tp i = 2; i <= n; ++i) {
    static tp mr = 0, mid = 0;
    p[i] = (i <= mr ? min(p[mid * 2 - i], mr - i + 1) : 1);
    while (s[i - p[i]] == s[i + p[i]]) {
      ++p[i];
    }
    if (tar = max(tar, p[i]); i + p[i] > mr) {
      mr = i + p[i] - 1;
      mid = i;
    }
  }
  cout << tar - 1;
  return 0;
}