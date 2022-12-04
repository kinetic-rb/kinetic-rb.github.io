#include <algorithm>
#include <iostream>

using namespace std;
using vt = long long;
constexpr vt Hat_N = 100003;

template <typename Typex>
void _Merge(Typex* _S, Typex* _E, Typex* _A) {
  if (_E - _S < 2) {
    return;
  }
  Typex *_M = _S + (_E - _S >> 1), *_P1 = _S, *_P2 = _M, *_Ptr = _A;
  _Merge(_S, _M, _A);
  _Merge(_M, _E, _A);
  while (_P1 != _M && _P2 != _E) {
    *_Ptr++ = (*_P2 < *_P1 ? *_P2++ : *_P1++);
  }
  while (_P1 != _M) {
    *_Ptr++ = *_P1++;
  }
  while (_P2 != _E) {
    *_Ptr++ = *_P2++;
  }
  for (Typex* i = _A; _S != _E; ++i) {
    *_S++ = *i;
  }
}

template <typename Typex>
void merge(Typex* _S, Typex* _E) {
  Typex* _A = new Typex[_E - _S];
  _Merge(_S, _E, _A);
  delete[] _A;
}

vt num[Hat_N];

signed main() {
  vt n;
  cin >> n;
  for (vt i = 0; i < n; ++i) {
    cin >> num[i];
  }
  merge(num, num + n);
  for (vt i = 0; i < n; ++i) {
    cout << num[i] << ' ';
  }
  return 0;
}