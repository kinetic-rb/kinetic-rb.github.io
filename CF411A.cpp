#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define rtp(__VALUE__) scanf("%lld", &__VALUE__)

namespace {
template <typename _Typex>
std::string tpt(_Typex __value = 1, const std::string& __type = "%lld") {
  size_t __count = static_cast<size_t>(__value);
  std::string __target;
  __target.reserve(__count * __type.size());
  while (__count--) {
    __target += __type;
  }
  return __target;
}

template <typename... _Typex>
signed sf(const std::string& __input, _Typex&... __value) {
  return ::scanf(__input.c_str(), &__value...);
}
}  // namespace

using namespace std;
using tp = long long;
constexpr bool __MTCS__ = 0;

namespace __SOL__ {
signed main() {
  string s;
  cin >> s;
  if (s.size() < 5) {
    puts("Too weak");
  } else if (!count_if(s.begin(), s.end(), [](auto&& x) { return x >= '0' && x <= '9'; })) {
    puts("Too weak");
  } else if (!count_if(s.begin(), s.end(), [](auto&& x) { return isupper(x); })) {
    puts("Too weak");
  } else if (!count_if(s.begin(), s.end(), [](auto&& x) { return islower(x); })) {
    puts("Too weak");
  } else {
    puts("Correct");
  }
  return 0;
}

signed PRE() {
  return 0;
}
}  // namespace __SOL__

signed main() {
  static tp __P__ = __SOL__::PRE(), __T__ = __MTCS__ ? (rtp(__T__), __T__) : 1;
  return __T__-- && (main() || __SOL__::main()) ? -1 : __P__;
}

//                                                               \
\u256d\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256e  \
\u2502   This Code Was Created By RBTree (https://rbtree.archi/)   \u2502  \
\u2570\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u2500\u256f
//