#include <iostream>

using namespace std;

long long fact[2000002];

long long qpow(long long x, long long y) {
  long long _Pow = 1;
  for (y <<= 1; y >>= 1; x = x * x % 20100403)
    if (y & 1)
      _Pow = _Pow * x % 20100403;
  return _Pow;
}

long long C(long long n, long long m) {
  return (fact[n] * qpow(fact[n - m], 20100401) % 20100403 *
          qpow(fact[m], 20100401) % 20100403);
}

signed main() {
  long long n, m, s;
  cin >> n >> m;
  *fact = 1;
  s = n + m;
  for (long long i = 1; i <= s; i++)
    fact[i] = fact[i - 1] * i % 20100403;
  cout << (C(s, m) - C(s, m - 1) + 20100403) % 20100403;
  return 0;
}