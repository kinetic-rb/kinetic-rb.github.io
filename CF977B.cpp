#include <cstdio>
#include <string>

using namespace std;
using i32 = int;
using i64 = long long;
using ui32 = unsigned int;
using ui64 = unsigned long long;

i64 cnt[128][128];

i32 main() {
  i64 n, MAX = 0;
  string s;
  scanf("%lld
", &n);
  s.reserve(n);
  for (i64 i = 0; i < n; ++i) {
    char ch;
    scanf("%c", &ch);
    s.push_back(ch);
  }
  for (i64 i = 1; i < n; ++i)
    ++cnt[s[i - 1]][s[i]];
  for (i64 i = 0; i < 128; ++i)
    for (i64 j = 0; j < 128; ++j)
      if (cnt[i][j] > MAX)
        MAX = cnt[i][j];
  for (i64 i = 0; i < 128; ++i)
    for (i64 j = 0; j < 128; ++j)
      if (cnt[i][j] == MAX) {
        putchar(i);
        putchar(j);
        return 0;
      }
  return 0;
}