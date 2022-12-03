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
    "mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,avx512f,popcnt,tune=native")

using namespace std;
using tp = int64_t;
using igt = __m256i;
using qgt = __m512i;
constexpr tp Hat_N = 2e6 + 3, Hat_T_Len = 2e6 + 3;

string s[Hat_N];
tp fcnt[Hat_T_Len], ID[Hat_T_Len], fail[Hat_T_Len], son[Hat_T_Len][29],
    rec[Hat_N], cnt[Hat_N], indeg[Hat_N];
tp tot, root;

void insert(string s, tp id) {
  tp now = root;
  for (tp i = 0; i < s.size(); ++i) {
    tp x = s[i] - 'a';
    if (!son[now][x]) {
      son[now][x] = ++tot;
    }
    now = son[now][x];
  }
  if (!ID[now]) {
    ID[now] = id;
  }
  rec[id] = ID[now];
}

void Calc_Fail() {
  list<tp> q;
  for (tp i = 0; i < 26; ++i) {
    if (son[root][i]) {
      q.push_back(son[root][i]);
    }
  }
  while (q.size()) {
    for (tp i = 0; i < 26; ++i) {
      if (son[q.front()][i]) {
        fail[son[q.front()][i]] = son[fail[q.front()]][i];
        q.push_back(son[q.front()][i]);
        ++indeg[fail[son[q.front()][i]]];
      } else {
        son[q.front()][i] = son[fail[q.front()]][i];
      }
    }
    q.pop_front();
  }
}

void topu() {
  list<tp> q;
  for (tp i = 1; i <= tot; ++i) {
    if (!indeg[i]) {
      q.push_back(i);
    }
  }
  while (q.size()) {
    fcnt[ID[q.front()]] = cnt[q.front()];
    cnt[fail[q.front()]] += cnt[q.front()];
    if (!--indeg[fail[q.front()]]) {
      q.push_back(fail[q.front()]);
    }
    q.pop_front();
  }
}

signed main() {
  tp n, now = root, tar = 0;
  cin >> n;
  string t;
  for (tp i = 1; i <= n; ++i) {
    cin >> s[i];
    insert(s[i], i);
  }
  Calc_Fail();
  cin >> t;
  for (auto&& i : t) {
    now = son[now][i - 'a'];
    ++cnt[now];
  }
  topu();
  for (tp i = 1; i <= n; ++i) {
    tar += !!fcnt[rec[i]];
  }
  cout << tar << '\n';
  return 0;
}