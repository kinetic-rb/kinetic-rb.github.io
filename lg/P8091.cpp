#include <iostream>
#define rf(name) for (tp name(1); name != 11; ++name)

using namespace std;
using tp = long long;
const tp N = 4;

tp t, a[N], b[N];
tp cmp(tp* x, tp* y) {
  tp cnt = 0;
  for (tp i(0); i != N; ++i) {
    for (tp j(0); j != N; ++j) {
      cnt += x[i] > y[j];
    }
  }
  return cnt;
}

bool check(tp* x) {
  tp r1 = cmp(x, a), r2 = cmp(a, x), r3 = cmp(x, b), r4 = cmp(b, x),
     r5 = cmp(a, b), r6 = cmp(b, a);
  bool f1 = r1 > r2, f2 = r3 > r4, f3 = r5 > r6;
  return r1 != r2 && r3 != r4 && r5 != r6 &&
         (f1 && !f2 && f3 || !f1 && f2 && !f3);
}

bool find() {
  rf(i) {
    rf(j) {
      rf(k) {
        rf(p) {
          tp x[4] = {i, j, k, p};
          if (check(x)) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

signed main() {
  cin >> t;
  while (t--) {
    for (tp i = 0; i < N; ++i) {
      cin >> a[i];
    }
    for (tp i = 0; i < N; ++i) {
      cin >> b[i];
    }
    cout << (find() ? "yes
" : "no
");
  }
  return 0;
}