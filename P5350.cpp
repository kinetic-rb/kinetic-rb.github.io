#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct node {
  int l, r;
  mutable int val;
  inline bool operator < (const node& comp) const {
    return l < comp.l;
  }
};

set<node> s;

inline void out() {
  for (node i : s)
    for (int j = i.l; j <= i.r; j++)
      printf("%d ", i.val);
  putchar('\n');
}

inline void insert(int l, int r = 0, int v = 0) {
  s.insert({ l, r, v });
}

inline set<node>::iterator split(int pos) {
  set<node>::iterator it = s.lower_bound({ pos });
  if (it != s.end() && it->l == pos)
    return it;
  const int l = (--it)->l, r = it->r, v = it->val;
  s.erase(it);
  s.insert({ l, pos - 1, v });
  return s.insert({ pos, r, v }).first;
}

inline int sum(int l, int r) {
  int ret = 0;
  for (set<node>::iterator R = split(r + 1), L = split(l); L != R; L++)
    ret = (ret + (L->r - L->l + 1LL) * L->val) % 1000000007;
  return ret;
}

inline void assign(int l, int r, int val) {
  set<node>::iterator R = split(r + 1), L = split(l);
  s.erase(L, R);
  s.insert({ l, r, val });
}

inline void add(int l, int r, int v) {
  for (set<node>::iterator R = split(r + 1), L = split(l); L != R; L++) {
    L->val += v;
    L->val += L->val >> 31 & 1000000007;
  }
}

inline void clone(int l1, int r1, int l2, int r2) {
  static vector<node> vec;
  vec.clear();
  for (set<node>::iterator R = split(r1 + 1), L = split(l1); L != R; L++)
    vec.push_back(*L);
  set<node>::iterator R = split(r2 + 1), L = split(l2);
  s.erase(L, R);
  for (node i : vec)
    s.insert({ i.l - l1 + l2, i.r - l1 + l2, i.val });
}

inline void swap(int l1, int r1, int l2, int r2) {
  if (l1 > l2) {
    l1 ^= l2 ^= l1 ^= l2;
    r1 ^= r2 ^= r1 ^= r2;
  }
  static vector<node> v1, v2;
  v1.clear();
  v2.clear();
  for (set<node>::iterator R = split(r1 + 1), L = split(l1); L != R; ++L)
    v1.push_back(*L);
  for (set<node>::iterator R = split(r2 + 1), L = split(l2); L != R; ++L)
    v2.push_back(*L);
  set<node>::iterator R = split(r1 + 1), L = split(l1);
  s.erase(L, R);
  R = split(r2 + 1);
  L = split(l2);
  s.erase(L, R);
  for (node i : v1)
    insert(i.l - l1 + l2, i.r - l1 + l2, i.val);
  for (node i : v2)
    insert(i.l - l2 + l1, i.r - l2 + l1, i.val);
}

inline void reverse(int l, int r) {
  static vector<node> vec;
  vec.clear();
  for (set<node>::iterator R = split(r + 1), L = split(l); L != R; L++)
    vec.push_back(*L);
  set<node>::iterator R = split(r + 1), L = split(l);
  s.erase(L, R);
  for (node i : vec)
    s.insert({ r - i.r + l, r - i.l + l, i.val });
}

int main() {
    ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    insert(i, i, t);
  }
  insert(n + 1);
  while (m--) {
    int op;
    cin >> op;
    switch (op) {
      case 1: {
        int l, r;
        cin >> l >> r;
        printf("%d
", sum(l, r));
        break;
      }
      case 2: {
        int l, r, v;
        cin >> l >> r >> v;
        assign(l, r, v);
        break;
      }
      case 3: {
        int l, r, v;
        cin >> l >> r >> v;
        add(l, r, v - 1000000007);
        break;
      }
      case 4: {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        clone(l1, r1, l2, r2);
        break;
      }
      case 5: {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        swap(l1, r1, l2, r2);
        break;
      }
      case 6: {
        int l, r;
        cin >> l >> r;
        reverse(l, r);
        break;
      }
    }
  }
  out();
  return 0;
}