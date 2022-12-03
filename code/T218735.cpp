#include <iostream>

using namespace std;
using tp = int;
constexpr tp Hat_S = 500003;

struct Rs {
  char c;
  tp p, n;
} l[Hat_S];

tp h, t, m, n;

tp find(tp x) {
  tp i = x <= 11 ? h : t;
  if (x <= 11) {
    while (--x) {
      i = l[i].n;
    }
  } else {
    x = m - x + 1;
    while (--x) {
      i = l[i].p;
    }
  }
  return i;
}

void insert(tp x) {
  cin >> l[++n].c;
  if (!h) {
    [[unlikely]];
    h = t = n;
  } else if (!x) {
    l[n].n = h;
    l[h].p = n;
    h = n;
  } else {
    [[likely]];
    tp i = find(x);
    l[n].p = i;
    l[n].n = l[i].n;
    if (i == t) {
      t = n;
    } else {
      l[l[i].n].p = n;
    }
    l[i].n = n;
  }
  ++m;
}

void remove(tp x) {
  tp i = find(x);
  if (i == h && h == t) {
    h = t = 0;
  } else if (i == h) {
    h = l[i].n;
    l[h].p = 0;
  } else if (i == t) {
    t = l[i].p;
    l[t].n = 0;
  } else {
    l[l[i].n].p = l[i].p;
    l[l[i].p].n = l[i].n;
  }
  --m;
}

signed main() {
  tp q;
  cin >> q;
  while (q--) {
    char op;
    tp x;
    cin >> op >> x;
    if (op == 'I') {
      insert(x);
    } else {
      remove(x);
    }
  }
  for (tp i = h; i; i = l[i].n) {
    cout << l[i].c;
  }
  return 0;
}