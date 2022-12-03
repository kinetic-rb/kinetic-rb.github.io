#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <cstdint>
#include <iostream>
#define cin ERROR
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

namespace Anonymous {
constexpr size_t __Buf_Size__ = 32767;
bool State = 1;
char *__buf = (char*)malloc(__Buf_Size__), *__s = __buf,
     *__e = __buf + fread(__buf, 1, __Buf_Size__, stdin);

template <typename Typex>
void re(Typex&&);
template <typename Typex, typename... Typey>
void re(Typex&&, Typey&&...);
}  // namespace Anonymous
using Anonymous::re;
using namespace std;
using tp = long long;
using igt = __m256i;
using qgt = __m512i;
constexpr bool __TEST_CASES__ = 0;
constexpr tp Hat_N = 100003;

template <typename Typex, size_t _Size, typename Compare = std::less<Typex>>
class Leftist_Tree {
  Compare comp;
  bool* __removed;
  size_t *__f, *__left, *__right, *__dist;
  Typex* __v;

  size_t _Merge(size_t item1, size_t item2) {
    if (item1 && item2) {
      if (comp(__v[item2], __v[item1])) {
        std::swap(item1, item2);
      }
      __right[item1] = _Merge(__right[item1], item2);
      if (__dist[__left[item1]] < __dist[__right[item1]]) {
        std::swap(__left[item1], __right[item1]);
      }
      __dist[item1] = __dist[__right[item1]] + 1;
      return item1;
    } else {
      return item1 + item2;
    }
  }

 public:
  Leftist_Tree() {
    __removed = new bool[_Size];
    __f = new size_t[_Size];
    __left = new size_t[_Size];
    __right = new size_t[_Size];
    __dist = new size_t[_Size];
    __v = new Typex[_Size];
    for (size_t __i = 0; __i < _Size; ++__i) {
      __f[__i] = __i;
    }
  }

  void set(size_t item, const Typex& _Value) { __v[item] = _Value; }

  size_t find(size_t item) {
    return __f[item] == item ? item : __f[item] = find(__f[item]);
  }

  bool merge(size_t item1, size_t item2) {
    if (__removed[item1] || __removed[item2]) {
      return 1;
    }
    item1 = find(item1);
    item2 = find(item2);
    if (item1 != item2) {
      __f[item1] = __f[item2] = _Merge(item1, item2);
    }
    return 0;
  }

  bool minimum(size_t item, Typex& _Value) {
    if (__removed[item]) {
      return 1;
    }
    _Value = __v[find(item)];
    return 0;
  }

  bool remove(size_t item) {
    if (__removed[item]) {
      return 1;
    }
    item = find(item);
    __removed[item] = 1;
    __f[__left[item]] = __f[__right[item]] = __f[item] =
        _Merge(__left[item], __right[item]);
    __left[item] = __right[item] = __dist[item] = 0;
    return 0;
  }
};

struct Item_t {
  tp v, id;

  Item_t() = default;
  Item_t(tp _v, tp _id) : v(_v), id(_id) {}
  bool operator<(const Item_t& comp) const {
    if (v != comp.v) {
      return v < comp.v;
    }
    return id < comp.id;
  }
};

void __CORE__() {
  tp n, m;
  Leftist_Tree<Item_t, Hat_N> h;
  re(n, m);
  for (tp i = 1; i <= n; ++i) {
    tp x;
    re(x);
    h.set(i, Item_t(x, i));
  }
  while (m--) {
    tp op, x;
    re(op, x);
    if (op == 1) {
      tp y;
      re(y);
      h.merge(x, y);
    } else {
      Item_t v;
      if (h.minimum(x, v)) {
        cout << -1 << '\n';
      } else {
        cout << v.v << '\n';
        h.remove(x);
      }
    }
  }
}

signed main() {
  static bool __NOT_READED__ = __TEST_CASES__;
  static tp __TEST_COUNT__ = 1;
  if (__NOT_READED__) {
    re(__TEST_COUNT__);
    __NOT_READED__ = 0;
  }
  if (__TEST_COUNT__--) {
    main();
    __CORE__();
  }
  return 0;
}

namespace Anonymous {
template <typename Typex>
void re(Typex&& __v) {
  bool f = 0;
  char __ch;
  auto __fetch = [&__ch]() {
    if (__s == __e) {
      __s = __buf;
      __e = __s + fread(__buf, 1, __Buf_Size__, stdin);
      if (__s == __e) {
        State = 0;
        __ch = -1;
      }
    }
    __ch = *__s++;
  };
  for (__fetch(); __ch < 48 || __ch > 57; __fetch()) {
    f |= __ch == 45;
  }
  __v = __ch & 15;
  for (__fetch(); __ch > 47 && __ch < 58; __fetch()) {
    __v += __v << 2;
    __v += __v + (__ch & 15);
  }
  if (f) {
    __v = (~__v) + 1;
  }
}

template <typename Typex, typename... Typey>
void re(Typex&& __v, Typey&&... __V) {
  re(__v);
  if (State) {
    re(__V...);
  }
}
}  // namespace Anonymous