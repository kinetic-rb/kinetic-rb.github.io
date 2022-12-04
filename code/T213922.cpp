#include <algorithm>
#include <cctype>
#include <cstdio>

using dt = long long;

constexpr dt N = 1 << 21, p = 81 << 21 | 1, g = 1167 << 12 | 1,
             h = 11443 << 12 | 1;

namespace basic_calc {
dt qpow(dt x, dt y) {
  dt pew = 1;
  for (; y; y >>= 1) {
    if (y & 1) {
      pew = pew * x % p;
    }
    x = x * x % p;
  }
  return pew;
}

void NTT(auto a, dt n, dt w) {
  dt* ntt_sup = new dt[N];
  auto b = ntt_sup, j = a, _j = a;
  dt _n = n >> 1, k, _k, _w;
  for (dt i = 1; i < n; i <<= 1) {
    for (k = 0, j = a, _j = a + _n, _w = 1; k != n; k += i) {
      for (_k = k, k += i; _k != k; ++j, ++_j, ++_k) {
        b[_k] = *j + *_j < 0 ? *j + *_j + p : *j + *_j - p;
        b[_k + i] = (*j - *_j) * _w % p;
      }
      _w = _w * w % p;
    }
    w = w * w % p;
    auto temp = a;
    a = b;
    b = temp;
  }
  if (b != ntt_sup) {
    std::copy(a, a + n, b);
  }
  delete[] ntt_sup;
}
}  // namespace basic_calc

dt n_a, n_b;
void Mul(auto a, auto b) {
  dt n = 1;
  for (; n < n_a + n_b; n <<= 1)
    ;
  basic_calc::NTT(a, n, basic_calc::qpow(g, (p - 1) / n));
  basic_calc::NTT(b, n, basic_calc::qpow(g, (p - 1) / n));
  for (dt i = 0; i < n; ++i) {
    a[i] = a[i] * b[i] % p;
  }
  basic_calc::NTT(a, n, basic_calc::qpow(h, (p - 1) / n));
  dt inv_n = basic_calc::qpow(n, p - 2);
  for (dt i = 0; i < n; ++i) {
    a[i] = a[i] * inv_n % p;
  }
  for (dt i = 0; i < n; ++i) {
    if (a[i] < 0) {
      a[i] += p;
    }
  }
}

dt a[N], b[N];

signed main() {
  bool f = true;
  char char_read;
  while (!isdigit(char_read = getchar()))
    ;
  do a[n_a++] = char_read ^ '0';
  while (isdigit(char_read = getchar()));
  while (!isdigit(char_read = getchar()))
    ;
  do b[n_b++] = char_read ^ '0';
  while (isdigit(char_read = getchar()));
  for (dt i = 0; i < n_a; ++i)
    if (a[i]) {
      f = false;
      break;
    }
  for (dt i = 0; i < n_b; ++i)
    if (b[i]) {
      f = false;
      break;
    }
  if (n_a == 1 && !*a) {
    printf("0");
    return 0;
  }
  if (n_b == 1 && !*b) {
    printf("0");
    return 0;
  }
  Mul(a, b);
  for (dt i = n_a + n_b - 2; i; --i) {
    a[i - 1] += a[i] / 10;
    a[i] %= 10;
  }
  for (dt i = 0; i < n_a + n_b - 1; ++i) printf("%lld", a[i]);
  return 0;
}