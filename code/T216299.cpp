#include <iostream>

using namespace std;
using vt = int;
const vt Hat_N = 200003;

vt f[Hat_N], s[Hat_N];

void init(vt n) {
  auto fp = f, sp = s;
  for (vt i = 1; i <= n; ++i) {
    *++fp = i;
    *++sp = 1;
  }
}

vt find(vt x) {
  return f[x] == x ? x : f[x] = find(f[x]);
}

void merge(vt u, vt v) {
  u = find(u);
  v = find(v);
  if (u == v)
    return;
  if (s[u] < s[v])
    u ^= v ^= u ^= v;
  s[f[v] = u] += s[v];
}

bool same(vt u, vt v) {
  return find(u) == find(v);
}

char res[20000000];

signed main() {
    vt n, m, cnt = -1;
    scanf("%d %d", &n, &m);
    init(n << 1);
    while (m--) {
      char op;
      vt u, v;
      scanf("
%c %d %d", &op, &u, &v);
      if (op == 'D') {
        merge(u, v + n);
        merge(u + n, v);
      } else {
        auto u1 = find(u), u2 = find(u + n),
             v1 = find(v), v2 = find(v + n);
        if (u1 == v2 || u2 == v1) {
          res[++cnt] = 'N';
        } else if (u1 == v1 || u2 == v2) {
          res[++cnt] = 'Y';
        } else {
          res[++cnt] = 'C';
        }
      }
    }
    fwrite(res, 1, cnt + 1, stdout);
  return 0;
}