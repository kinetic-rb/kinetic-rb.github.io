#include <algorithm>
#include <iostream>
#define SE(p) p.begin(), p.end()

using namespace std;
using tp = int64_t;

signed main() {
  tp n, targetc = 0x7fffffffffffffff;
  string s, p = "RGB", targets;
  stable_sort(SE(p));
  cin >> n >> s;
  do {
    tp count = 0, cnt = count_if(SE(s), [&](char c) { return c != p[count++ % 3]; });
    if (cnt < targetc) {
      targetc = cnt;
      targets = p;
    }
  } while (next_permutation(SE(p)));
  printf("%lld
", targetc);
  for (tp i = 0; i < n; ++i) {
    putchar(targets[i % 3]);
  }
  return 0;
}