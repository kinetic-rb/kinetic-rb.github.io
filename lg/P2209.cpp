#include <algorithm>
#include <iostream>

using namespace std;
using LL = long long;

const int kMaxN = 5e4 + 2;

struct E {                                                // \u52a0\u6cb9\u7ad9
  int x, y, p;                                            // \u4f4d\u7f6e\u3001\u4ef7\u683c\u3001\u6700\u8fd1\u7684\u66f4\u4f18\u52a0\u6cb9\u7ad9
  bool operator<(const E &_e) const { return x < _e.x; }  // \u6309\u7167\u5750\u6807\u6392\u5e8f
} e[kMaxN];
int a[kMaxN], n, g, b, d, m;

LL C() {                     // \u8ba1\u7b97\u7b54\u6848
  LL r = 0;                  // \u521d\u59cb\u5316\u7b54\u6848
  b -= e[1].x;               // \u5148\u79fb\u52a8\u5230\u7b2c1\u4e2a\u7ad9
  for (int i = 1; i < n;) {  // \u4ece\u4f4d\u7f6e1\u5f00\u59cb\u76f4\u5230n
    if (b < 0) {             // \u6cb9\u7bb1\u5bb9\u91cf\u4e0d\u8db3
      return -1;             // \u65e0\u89e3
    }
    if (e[e[i].p].x - e[i].x <= g) {            // \u5f53\u524d\u6cb9\u7bb1\u5bb9\u91cf\u8db3\u591f\u5230\u8fbe\u66f4\u4f18\u7ad9
      LL v = max(0, e[e[i].p].x - e[i].x - b);  // \u9700\u8981\u52a0\u7684\u6cb9
      r += v * e[i].y;                          // \u7d2f\u52a0\u8d39\u7528
      b += v - (e[e[i].p].x - e[i].x);          // \u6d88\u8017\u6cb9\u91cf
      i = e[i].p;                               // \u79fb\u52a8\u5230\u66f4\u4f18\u7ad9
    } else {                                    // \u4e0d\u8db3\u4ee5\u5230\u8fbe\u66f4\u4f18\u7ad9
      r += 1LL * (g - b) * e[i].y;              // \u52a0\u6ee1\u6cb9\u7684\u8d39\u7528
      b = g - (e[i + 1].x - e[i].x);            // \u79fb\u52a8\u540e\u5269\u4e0b\u7684\u6cb9\u91cf
      i++;                                      // \u79fb\u52a8\u5230\u4e0b\u4e2a\u76f8\u90bb\u7ad9
    }
  }
  return b < 0 ? -1 : r;
}

int main() {
  cin >> n >> g >> b >> d;
  for (int i = 1; i <= n; i++) {
    cin >> e[i].x >> e[i].y;
  }

  sort(e + 1, e + 1 + n);

  e[++n] = {d};                              // \u52a0\u5165\u7ec8\u70b9
  for (int i = 1; i <= n; i++) {             // \u8ba1\u7b97\u6bcf\u4e2a\u7ad9\u7684\u6700\u8fd1\u66f4\u4f18\u7ad9
    for (; m && e[i].y <= e[a[m]].y; m--) {  // \u5f53\u524d\u7ad9\u6bd4\u4e4b\u524d\u7684\u66f4\u4f18\u5219\u5220\u9664\u6808\u5c3e
      e[a[m]].p = i;                         // \u8bb0\u5f55
    }
    a[++m] = i;  // \u52a0\u5165\u5f53\u524d\u7ad9
  }
  cout << C();
  return 0;
}