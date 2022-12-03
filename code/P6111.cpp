#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
using tp = long long;
constexpr tp Hat_N = 5003;

template <typename Typex>
struct mvec {
  struct LNode {
    LNode* next;
    Typex val;
    
    LNode() = default;
  } * head, *end;
  
  mvec() { head = end = nullptr; }
  
  void push_back(const Typex& v) {
    if (head) {
      LNode* t = new LNode;
      t->val = v;
      end->next = t;
      end = t;
    } else {
      head = end = new LNode;
      head->val = v;
    }
  }
};

struct Rs {
  tp t, c;
  
  Rs() = default;
  Rs(tp t, tp c) : t(t), c(c) {}
};

mvec<Rs> g[Hat_N];
bool vis[Hat_N];
tp k, cnt;

void dfs(tp x, tp r = 0x7fffffffffffffff) {
  if (vis[x]) {
    return;
  }
  if (r >= k) {
    ++cnt;
  }
  vis[x] = 1;
  for (mvec<Rs>::LNode* it = g[x].head; it != g[x].end; it = it->next) {
    dfs(it->val.t, min(r, it->val.c));
  }
  if (g[x].end) {
    dfs(g[x].end->val.t, min(r, g[x].end->val.c));
  }
}

signed main() {
  tp n, q;
  cin >> n >> q;
  for (tp i = 1; i < n; ++i) {
    tp u, v, d;
    cin >> u >> v >> d;
    g[u].push_back(Rs(v, d));
    g[v].push_back(Rs(u, d));
  }
  while (q--) {
    tp x;
    cin >> k >> x;
    cnt = -1;
    memset(vis, 0, sizeof vis);
    dfs(x);
    cout << cnt << '\n';
  }
  return 0;
}