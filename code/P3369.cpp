#include <bits/stdc++.h>
#define update(u) \
  if (u->lf->size) u->size = u->lf->size + u->rf->size, u->val = u->rf->val
#define new_Node(a, b, c, d) (new Node(a, b, c, d))
#define merge(a, b) new_Node(a->size + b->size, b->val, a, b)
#define ratio 4
using namespace std;

inline int Min(const int x, const int y) { return x < y ? x : y; }

inline int Max(const int x, const int y) { return x > y ? x : y; }

int n, cnt;

struct Node {
  int size, val;
  Node *lf, *rf;

  Node(int a, int b, Node *l, Node *r) : size(a), val(b), lf(l), rf(r) {}

  Node() {}
};

Node *root, *null;

inline void rotate(Node *u) {
  if (u->lf->size > u->rf->size * ratio) {
    auto t = u->lf;
    u->rf = merge(u->lf->rf, u->rf), u->lf = u->lf->lf;
    delete t;
  }
  if (u->rf->size > u->lf->size * ratio) {
    auto t = u->rf;
    u->lf = merge(u->lf, u->rf->lf), u->rf = u->rf->rf;
    delete t;
  }
}

inline void insert(Node *u, int x) {
  if (u->size == 1)
    u->lf = new_Node(1, Min(u->val, x), null, null),
    u->rf = new_Node(1, Max(u->val, x), null, null);
  else
    insert(x > u->lf->val ? u->rf : u->lf, x);
  update(u), rotate(u);
}

inline void erase(Node *u, int x) {
  if (u->lf->size == 1 && u->lf->val == x) {
    auto x = u->rf;
    delete u->lf;
    *u = *u->rf;
    delete x;
  } else if (u->rf->size == 1 && u->rf->val == x) {
    auto x = u->lf;
    delete u->rf;
    *u = *u->lf;
    delete x;
  } else
    erase(x > u->lf->val ? u->rf : u->lf, x);
  update(u), rotate(u);
}

inline int find(Node *u, int x) {
  if (u->size == 1) return u->val;
  return u->lf->size < x ? find(u->rf, x - u->lf->size) : find(u->lf, x);
}

inline int Rank(Node *u, int x) {
  if (u->size == 1) return 1;
  return u->lf->val < x ? u->lf->size + Rank(u->rf, x) : Rank(u->lf, x);
}

inline int pre(int x) { return find(root, Rank(root, x) - 1); }

inline int nxt(int x) { return find(root, Rank(root, x + 1)); }

int main() {
  scanf("%d", &n);
  cnt = 0;
  null = new Node(0, 0, 0, 0);
  root = new Node(1, INT_MAX, null, null);
  for (register int i = 1; i <= n; i++) {
    register int t, a;
    scanf("%d%d", &t, &a);
    if (t == 1)
      insert(root, a);
    else if (t == 2)
      erase(root, a);
    else if (t == 3)
      printf("%d
", Rank(root, a));
    else if (t == 4)
      printf("%d
", find(root, a));
    else if (t == 5)
      printf("%d
", pre(a));
    else if (t == 6)
      printf("%d
", nxt(a));
  }
  return 0;
}
