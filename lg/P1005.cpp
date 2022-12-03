#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <list>
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

using namespace std;
using tp = int32_t;
using igt = __m256i;
constexpr tp Hat_S = 83;

tp v[Hat_S];
__int128 _2p[Hat_S], f[Hat_S][Hat_S];

signed main() {
  tp n, m;
  __int128 sum = 0;
  list<char> s;
  *_2p = 1;
  for (tp i = 1; i < Hat_S; ++i) {
    _2p[i] = _2p[i - 1] << 1ll;
  }
  cin >> n >> m;
  while (n--) {
    __int128 MAX = 0;
    memset(f, 0, sizeof f);
    for (tp i = 1; i <= m; ++i) {
      cin >> v[i];
    }
    for (tp i = 1; i <= m; ++i) {
      for (tp j = m; j >= i; --j) {
        f[i][j] = max(f[i - 1][j] + v[i - 1] * _2p[m - j + i - 1],
                      f[i][j + 1] + v[j + 1] * _2p[m - j + i - 1]);
      }
    }
    for (tp i = 1; i <= m; ++i) {
      MAX = max(MAX, f[i][i] + v[i] * _2p[m]);
    }
    sum += MAX;
  }
  while (sum) {
    s.push_front(sum % 10 ^ 48);
    sum /= 10;
  }
  for (auto&& i : s) {
    cout << i;
  }
  if (s.empty()) {
    cout << '0';
  }
  return 0;
}