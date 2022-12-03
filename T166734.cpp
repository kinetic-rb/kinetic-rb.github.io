// \u6e56\u5357\u5e08\u8303\u5927\u5b66\u9644\u5c5e\u4e2d\u5b66 | \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int kMaxN = 101;

struct P {  // \u70b9
  int x, y;
} p[kMaxN];
int n, s;

int main() {
  //freopen("triangles.in", "r", stdin);
  //freopen("triangles.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int k = 1; k <= n; k++) {                                               // \u679a\u4e3e\u4e09\u4e2a\u70b9\uff0ci\u4e3a\u76f4\u89d2\u70b9
        if (i != j && j != k && k != i && p[i].x == p[j].x && p[i].y == p[k].y) {  // \u5224\u65ad\u76f4\u89d2
          s = max(s, abs(p[i].y - p[j].y) * abs(p[i].x - p[k].x));
        }
      }
    }
  }
  cout << s;
  return 0;
}