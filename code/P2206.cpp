// \u6e56\u5357\u5e08\u8303\u5927\u5b66\u9644\u5c5e\u4e2d\u5b66 | \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int kD[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // 0-\u5317\uff0c1-\u4e1c\uff0c2-\u5357\uff0c3-\u897f

struct P {  // \u56db\u80a2\u4f4d\u7f6e\uff0c0-\u5de6\u524d\u30011-\u53f3\u524d\u30012-\u5de6\u540e\u30013-\u53f3\u540e
  int x, y;
} p[4] = {{0, 1}, {1, 1}, {0, 0}, {1, 0}};  // \u521d\u59cb\u4f4d\u7f6e(0,0)\u5230(1,1)

int dt[256];                       // \u65b9\u5411\u5b57\u7b26\u8f6c\u7f16\u53f7
int n, xl, xr = 1, yl, yr = 1, d;  // \u5750\u6807\u8303\u56f4\u548c\u65b9\u5411
string s;

int T(char a, char b) {  // \u56db\u80a2\u5b57\u7b26\u8f6c\u7f16\u53f7
  return (a == 'R') * 2 + (b == 'R');
}

void R(int o) {  // \u4ee5o\u4e3a\u4e2d\u5fc3\u53f3\u65cb
  for (int i = 0; i <= 3; i++) {
    p[i] = {p[o].x + p[i].y - p[o].y, p[o].y - p[i].x + p[o].x};
  }
}

void M(int o, int i) {  // o\u671d\u65b9\u5411i\u8fdb\u884c\u79fb\u52a8
  p[o] = {p[o].x + kD[i][0], p[o].y + kD[i][1]};
}

bool C(int o) {  // \u68c0\u67e5o
  for (int i = 0; i <= 3; i++) {
    xl = min(xl, p[i].x), xr = max(xr, p[i].x);            // \u66f4\u65b0x\u754c
    yl = min(yl, p[i].y), yr = max(yr, p[i].y);            // \u66f4\u65b0y\u754c
    if (i != o && p[i].x == p[o].x && p[i].y == p[o].y) {  // \u4e24\u80a2\u91cd\u53e0
      return 0;
    }
  }
  return 1;
}

bool W() {  // \u6a21\u62df\u5e76\u5224\u65ad\u662f\u5426\u4f1a\u7eca\u5012
  for (int i = 1; i <= n; i++) {
    cin >> s;
    int o = T(s[0], s[1]);  // \u8ba1\u7b97\u80a2\u7f16\u53f7
    if (s[2] == 'P') {
      d = (d + 1) % 4;  // \u8f6c\u5411
      R(o);
    } else {
      M(o, (d + dt[s[2]]) % 4);  // \u76f8\u5bf9\u65b9\u5411\u8f6c\u7edd\u5bf9
    }
    if (!C(o)) {  // \u6821\u9a8c
      return 0;
    }
  }
  return 1;
}

int main() {
  dt['R'] = 1, dt['B'] = 2, dt['L'] = 3;  // \u521d\u59cb\u5316\u65b9\u5411\u8f6c\u6362
  cin >> n;
  cout << (W() ? (xr - xl + 1) * (yr - yl + 1) : -1);
  return 0;
}