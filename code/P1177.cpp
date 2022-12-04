#include <algorithm>
#include <iostream>

using namespace std;
using vt = int;
constexpr vt Hat_N = 100003;

template <typename Typex>
void _Merge(Typex _S, Typex _E, Typex _A) {
  if (_E - _S < 64) {
    for (auto _D = _E - _S; _D; _D >>= 1) {
      for (auto td = 0ll; td < _D; ++td) {
        Typex N_S = _S + td;
        for (Typex td = N_S + _D; td < _E; td += _D) {
          for (Typex j = td, jmd = td - _D; j > N_S; j -= _D, jmd -= _D) {
            if (*j < *jmd) {
              auto temp = *j;
              *j = *jmd;
              *jmd = temp;
            } else {
              break;
            }
          }
        }
      }
    }
    return;
  }
  Typex _M = _S + (_E - _S >> 1), _P1 = _S, _P2 = _M, _Ptr = _A;
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
  for (Typex i = _A; _S != _E; ++i) {
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