#include <algorithm>
#include <iostream>
#define fin cin
#define fout cout

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5 + 1;

Pii e[kMaxN];                     // \u5546\u5e97\uff0c\u5355\u4ef7\u548c\u6536\u8d2d\u91cf
int c[kMaxN], v[kMaxN], n, m, r;  // \u4ea7\u91cf\u3001\u79df\u4ef7
long long x, y, ans;

int main() {
  fin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    fin >> c[i];
  }
  for (int i = 1; i <= m; i++) {
    fin >> e[i].second >> e[i].first;
  }
  for (int i = 1; i <= r; i++) {
    fin >> v[i];
  }
  sort(c + 1, c + 1 + n);                                              // \u6309\u4ea7\u91cf\u6392\u5e8f
  sort(e + 1, e + 1 + m);                                              // \u6309\u5355\u4ef7\u6392\u5e8f
  sort(v + 1, v + 1 + max(r, n), [](int i, int j) { return i > j; });  // \u6309\u79df\u4ef7\u9006\u5e8f\u6392\u5e8f

  for (int i = 1; i <= n; i++) {  // \u8ba1\u7b97\u5168\u90e8\u79df\u51fa\u7684\u4ef7\u683c
    y += v[i];
  }
  ans = y;                                              // \u521d\u59cb\u5316\u7b54\u6848
  for (int i = n, j = m; i; i--) {                      // \u679a\u4e3e\u79df\u51fa\u5976\u725b\u6570\u91cf
    y -= v[i];                                          // \u51cf\u53bb\u79df\u4ef7
    for (int a = c[i], b; a && j; j -= !e[j].second) {  // \u7531\u9ad8\u5230\u4f4e\u5bf9\u4ea7\u5976\u8fdb\u884c\u9500\u552e
      b = min(a, e[j].second);                          // \u53ef\u552e\u51fa\u91cf
      a -= b, e[j].second -= b;                         // \u51cf\u5c11\u91cf
      x += 1LL * e[j].first * b;                        // \u589e\u52a0\u552e\u51fa\u4ef7\u683c
    }
    ans = max(ans, x + y);  // \u66f4\u65b0\u7b54\u6848
  }
  fout << ans;
  return 0;
}