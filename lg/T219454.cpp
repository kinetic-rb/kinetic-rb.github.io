#include <iostream>
#include <map>

using namespace std;
using tp = int;
constexpr tp Hat_N = 100003;

struct TNode {
  tp v;
  TNode *p, *l, *r;

  TNode() = default;
  TNode(tp v) : v(v) { p = l = r = nullptr; }
} *Root;

map<tp, TNode*> al;
bool Rt[Hat_N];

TNode* Get(tp n) {
  if (!n) {
    return nullptr;
  }
  if (al[n]) {
    return al[n];
  }
  return al[n] = new TNode(n);
}

void dfs(TNode* now, tp type) {
  if (!now) {
    return;
  }
  if (!type) {
    cout << now->v << ' ';
  }
  dfs(now->l, type);
  if (type == 1) {
    cout << now->v << ' ';
  }
  dfs(now->r, type);
  if (type == 2) {
    cout << now->v << ' ';
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    tp l, r;
    cin >> l >> r;
    Rt[l] = Rt[r] = 1;
    TNode *p = Get(i), *lson = Get(l), *rson = Get(r);
    p->l = lson;
    p->r = rson;
  }
  for (tp i = 1; i <= n; ++i) {
    if (!Rt[i]) {
      Root = Get(i);
    }
  }
  dfs(Root, 0);
  cout << '\n';
  dfs(Root, 1);
  cout << '\n';
  dfs(Root, 2);
  return 0;
}