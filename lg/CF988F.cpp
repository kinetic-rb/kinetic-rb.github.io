#include <bitset>
#include <cstring>
#include <iostream>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 2003, Hat_M = 2003;

bitset<Hat_N> rain;
vt f[Hat_N][Hat_M], cost[Hat_M], UPC[Hat_M];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  memset(f, 0x7f, sizeof f);
  **f = 0;
  *cost = 0x7f7f7f7f7f7f7f7f;
  vt a, n, m, MIN = 0x7f7f7f7f7f7f7f7f;
  cin >> a >> n >> m;
  while (n--) {
    vt s, e;
    cin >> s >> e;
    for (++s; s <= e; ++s) {
      rain[s] = true;
    }
  }
  for (vt i = 1; i <= m; ++i) {
    vt x;
    cin >> x >> cost[i];
    if (cost[i] < cost[UPC[x]]) {  // \u627e\u5230 x \u5730\u6700\u5c0f\u82b1\u8d39\u7684\u96e8\u4f1e
      UPC[x] = i;
    }
  }
  for (vt i = 1; i <= a; ++i) {
    memset(f[i], 0x7f, sizeof f[i]);
    for (vt j = 0; j <= m; ++j) {
      if (!rain[i]) {
        f[i][0] = min(f[i][0], f[i - 1][j]);
      }
      if (j) {
        f[i][j] = min(f[i][j], f[i - 1][j] + cost[j]);
      }
      if (UPC[i - 1]) {
        f[i][UPC[i - 1]] = min(f[i][UPC[i - 1]], f[i - 1][j] + cost[UPC[i - 1]]);
      }
    }
  }
  for (vt i = 0; i <= m; ++i) {
    if (f[a][i] < MIN) {
      MIN = f[a][i];
    }
  }
  cout << (MIN == 0x7f7f7f7f7f7f7f7f ? -1 : MIN);
  return 0;
}

/*
f[i][j] \u8868\u793a\u8d70\u5230 i \u5730\u65f6\u624b\u91cc\u6709\u7b2c j \u628a\u4f1e\u65f6\u7684\u6700\u5c0f\u82b1\u8d39
\u8f6c\u79fb 1 : \u5982\u679c\u4e0d\u4e0b\u96e8\u5c31\u4e22\u6389\u4f1e
\u8f6c\u79fb 2 : \u5982\u679c\u8d70\u5230 i - 1 \u5730\u65f6\u624b\u4e0a\u6709\u4f1e\u5c31\u62ff\u7740\u624b\u4e0a\u8fd9\u628a\u4f1e\u7ee7\u7eed\u8d70
\u8f6c\u79fb 3 : \u5982\u679c\u8d70\u5230 i - 1 \u5730\u65f6\u5730\u4e0a\u6709\u4f1e\u5c31\u6362\u4e00\u628a\u4f1e
*/