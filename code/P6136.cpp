#include <emmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>
#include <pmmintrin.h>
#include <xmmintrin.h>
#include <cstdint>
#include <ctime>
#include <iostream>
#pragma GCC target( \
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

using namespace std;
using tp = int;
using igt = __m256i;
using qgt = __m512i;
constexpr tp Hat_N = 1e6 + 1e5 + 3, __SEED = 32327;

namespace Anonymous {
constexpr tp __Buf_Size__ = 32767;
bool State = 1;

char *__buf = (char*)malloc(__Buf_Size__), *__s = __buf,
     *__e = __buf + fread(__buf, 1, __Buf_Size__, stdin);

template <typename Typex>
void re(Typex&&);
template <typename Typex, typename... Typey>
void re(Typex&&, Typey&&...);
}  // namespace Anonymous
using Anonymous::re;

template <typename Typex, size_t Hat_N, typename Compare = std::less<Typex>>
struct FHQ_Treap {
  size_t lson[Hat_N], rson[Hat_N], rnd[Hat_N], size[Hat_N];
  size_t root, tot;
  Typex data[Hat_N];
  FHQ_Treap() = default;

  time_t rd() {
    static time_t __seed = time(0);
    return __seed *= __SEED;
  }

  void pushup(size_t pos) { size[pos] = size[lson[pos]] + size[rson[pos]] + 1; }
  void split(size_t pos, const Typex& val, size_t& x, size_t& y) {
    if (!pos) {
      x = y = 0;
      return;
    }
    if (data[pos] <= val) {
      x = pos;
      split(rson[pos], val, rson[pos], y);
    } else {
      y = pos;
      split(lson[pos], val, x, lson[pos]);
    }
    pushup(pos);
  }

  void _SSplit(size_t pos, const Typex& val, size_t& x, size_t& y) {
    if (!pos) {
      x = y = 0;
      return;
    }
    if (data[pos] < val) {
      x = pos;
      _SSplit(rson[pos], val, rson[pos], y);
    } else {
      y = pos;
      _SSplit(lson[pos], val, x, lson[pos]);
    }
    pushup(pos);
  }

  size_t merge(size_t x, size_t y) {
    if (!x || !y) {
      return x ? x : y;
    }
    if (rnd[x] < rnd[y]) {
      rson[x] = merge(rson[x], y);
      pushup(x);
      return x;
    } else {
      lson[y] = merge(x, lson[y]);
      pushup(y);
      return y;
    }
  }

  void insert(const Typex& val) {
    size_t x, y, pos = ++tot;
    data[pos] = val;
    size[pos] = 1;
    rnd[pos] = rd();
    split(root, val, x, y);
    root = merge(merge(x, pos), y);
  }

  void remove(const Typex& val) {
    size_t x, y, z;
    _SSplit(root, val, x, y);
    split(y, val, y, z);
    if (y) {
      y = merge(lson[y], rson[y]);
      root = merge(x, merge(y, z));
    }
  }

  size_t query_rank(size_t val) {
    size_t x, y, ret;
    _SSplit(root, val, x, y);
    ret = size[x] + 1;
    root = merge(x, y);
    return ret;
  }

  const Typex& select(size_t kth) {
    size_t pos = root;
    while (kth != size[lson[pos]] + 1) {
      if (kth <= size[lson[pos]]) {
        pos = lson[pos];
      } else {
        kth -= size[lson[pos]] + 1;
        pos = rson[pos];
      }
    }
    return data[pos];
  }

  const Typex& pred(const Typex& val) {
    size_t pos = root;
    Typex* ret = nullptr;
    while (pos) {
      if (val <= data[pos]) {
        pos = lson[pos];
      } else {
        ret = &data[pos];
        pos = rson[pos];
      }
    }
    return *ret;
  }

  const Typex& succ(const Typex& val) {
    size_t pos = root;
    Typex* ret = nullptr;
    while (pos) {
      if (val >= data[pos]) {
        pos = rson[pos];
      } else {
        ret = &data[pos];
        pos = lson[pos];
      }
    }
    return *ret;
  }
};

signed main() {
  tp n, m, tar = 0;
  FHQ_Treap<tp, Hat_N> tr;
  re(n, m);
  for (tp x; n--; tr.insert(x)) {
    re(x);
  }
  while (m--) {
    static tp res = 0;
    tp op, x;
    re(op, x);
    x ^= res;
    if (op == 1) {
      tr.insert(x);
    } else if (op == 2) {
      tr.remove(x);
    } else {
      if (op == 3) {
        res = tr.query_rank(x);
      } else if (op == 4) {
        res = tr.select(x);
      } else if (op == 5) {
        res = tr.pred(x);
      } else {
        res = tr.succ(x);
      }
      tar ^= res;
    }
  }
  cout << tar;
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