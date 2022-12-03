#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
// #define __NEGATIVE_NUMBER__
using namespace std;
using tp = long long;
FILE* __STREAM__ = stdin;
constexpr bool __MTCS__ = 0;
constexpr size_t __Buf_Size__ = 114514'1;
constexpr char __RV__[] = "%lld";

namespace {
namespace __SOLUTION_LAND__ {
signed main();
signed PRE();
}  // namespace __SOLUTION_LAND__

template <typename _Type>
bool rv(_Type& __value) {
  return ~scanf(__RV__, &__value);
}

template <typename _Typex, typename... _Typey>
bool rv(_Typex& __value, _Typey&... __other) {
  return rv(__value) ? rv(__other...) : 0;
}

tp rv() {
  tp __value;
  rv(__value);
  return __value;
}
}  // namespace
signed main() {
  static signed __P__ = __SOLUTION_LAND__::PRE(), __T__ = __MTCS__ ? rv() : 1;
  return __T__-- && (main() || __SOLUTION_LAND__::main()) ? -1 : __P__;
}

/** @note The following is the main part. **/

/** @note The following is the core of the main part. **/

struct TNode {
  tp left, right, size;

  TNode() = default;
};

vector<tp> root;
vector<TNode> tree;

void modify(tp x, tp& now_ver, tp ver, tp l, tp r) {
  now_ver = tree.size();
  tree.push_back(tree[ver]);
  ++tree.back().size;
  if (l >= r) {
    return;
  }
  if (x <= (l + r >> 1)) {
    modify(x, tree.back().left, tree[ver].left, l, l + r >> 1);
  } else {
    modify(x, tree.back().right, tree[ver].right, l + r + 2 >> 1, r);
  }
}

tp query(tp x, tp ver_left, tp ver_right, tp l, tp r) {
  if (l >= r) {
    return l;
  } else {
    tp gap = tree[tree[ver_right].left].size - tree[tree[ver_left].left].size;
    if (x > gap) {
      return query(x - gap, tree[ver_left].right, tree[ver_right].right,
                   l + r + 2 >> 1, r);
    } else {
      return query(x, tree[ver_left].left, tree[ver_right].left, l, l + r >> 1);
    }
  }
}

signed __SOLUTION_LAND__::main() {
  tp n = rv(), m = rv();
  vector<tp> v(n + 1), ord(n + 1);
  for (tp i = 1; i <= n; ++i) {
    v[i] = ord[i] = rv();
  }
  root.resize(1);
  tree.resize(1);
  stable_sort(ord.begin() + 1, ord.end());
  for (tp i = 1; i <= n; ++i) {
    root.push_back(1145141919810);
    modify(lower_bound(ord.begin() + 1, ord.end(), v[i]) - ord.begin(), root[i],
           root[i - 1], 1, n);
  }
  while (m--) {
    tp l = rv(), r = rv(), x = rv();
    cout << ord[query(x, root[l - 1], root[r], 1, n)] << '\n';
  }
  return 0;
}

signed __SOLUTION_LAND__::PRE() {
  return 0;
}