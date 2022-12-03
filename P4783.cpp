#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#define SUB(x, y) x = ((x - y) % _MOD_ + _MOD_) % _MOD_

using namespace std;
using tp = long long;
constexpr bool __TEST_CASES__ = 0;
constexpr tp Hat_N = 803, _MOD_ = 1e9 + 7;

tp v[Hat_N][Hat_N];

signed __PRE__() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  return 0;
}

tp qpow(tp x, tp y, tp z) {
  tp tar = 1;
  while (y) {
    if (y & 1) {
      tar = tar * x % z;
    }
    x = x * x % z;
    y >>= 1;
  }
  return tar;
}

signed __CORE__() {
  tp n;
  cin >> n;
  for_each(v, v + n, [&](auto&& x) {
    for (tp i = 0; i < n; ++i) {
      cin >> x[i];
      x[&x - v + n] = 1;
    }
  });
  for (tp i = 0; i < n; ++i) {
    tp loc = i, inv;
    for (tp j = i + 1; j < n; ++j) {
      if (abs(v[j][i]) > abs(v[loc][i])) {
        loc = i;
      }
    }
    for (tp j = 0, endj = n << 1; j < endj; ++j) {
      swap(v[i][j], v[loc][j]);
    }
    if (!v[i][i]) {
      puts("No Solution");
      return 0;
    }
    inv = qpow(v[i][i], _MOD_ - 2, _MOD_);
    for (tp j = 0; j < n; ++j) {
      if (i != j) {
        tp p = v[j][i] * inv % _MOD_;
        for (tp k = i + 1, endk = n << 1; k < endk; ++k) {
          SUB(v[j][k], v[i][k] * p);
        }
      }
    }
    for (tp j = 1, endj = n << 1; j < endj; ++j) {
      v[i][j] = v[i][j] * inv % _MOD_;
    }
  }
  for_each(v, v + n, [&](auto&& x) {
    for (tp i = n, endi = n << 1; i < endi; ++i) {
      cout << x[i] << ' ';
    }
    cout << '\n';
  });
  return 0;
}

signed main() {
  static bool __NOT_READED__ = 1;
  static tp __TEST_COUNT__ = 1;
  if (__NOT_READED__) {
    if (__PRE__()) {
      return -1;
    }
    if (__TEST_CASES__) {
      cin >> __TEST_COUNT__;
    }
    __NOT_READED__ = 0;
  }
  if (__TEST_COUNT__-- && (main() || __CORE__())) {
    return -1;
  }
  return 0;
}