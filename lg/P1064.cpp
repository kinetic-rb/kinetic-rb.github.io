#include <iostream>
#include <vector>
#pragma warning(disable : 4996)

using dt = long long;
using std::cin;
using std::cout;
using std::vector;

dt f[32003];

struct DX {
  dt w, v;

  DX() {}
  DX(dt w, dt v) : w(w), v(v) {}
};

bool Vis[63];

struct CE {
  dt v, k, f;
  vector<dt> s;
  vector<DX> val;
} T[63];

void DFS(dt x) {
  Vis[x] = true;
  T[x].val.clear();
  T[x].val.emplace_back(0, 0);
  T[x].val.emplace_back(T[x].v, T[x].v * T[x].k);
  for (auto&& to : T[x].s) {
    if (!Vis[to]) {
      DFS(to);
    }
    static vector<DX> tmp;
    tmp.clear();
    tmp.emplace_back(0, 0);
    for (auto&& p : T[to].val) {
      for (auto&& q : T[x].val) {
        if (q.w) {
          tmp.emplace_back(p.w + q.w, p.v + q.v);
        }
      }
    }
    T[x].val = tmp;
  }
}

signed main() {
  dt m, n, res = 0;
  cin >> n >> m;
  for (dt i = 1; i <= m; ++i) {
    cin >> T[i].v >> T[i].k >> T[i].f;
    if (T[i].f) {
      T[T[i].f].s.push_back(i);
    }
  }
  for (dt i = 1; i <= m; ++i) {
    if (!Vis[i]) {
      DFS(i);
    }
  }
  for (dt i = 1; i <= m; ++i) {
    if (!T[i].f) {
      for (dt j = n; ~j; --j) {
        for (auto&& p : T[i].val) {
          if (j >= p.w && f[j - p.w] + p.v > f[j]) {
            f[j] = f[j - p.w] + p.v;
          }
        }
      }
    }
  }
  for (dt i = 0; i <= n; ++i) {
    if (f[i] > res) {
      res = f[i];
    }
  }
  cout << res;
  return 0;
}