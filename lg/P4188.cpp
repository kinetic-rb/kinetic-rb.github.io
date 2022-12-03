#include <algorithm>
#include <iostream>
#define fin cin
#define fout cout

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5 + 2;

Pii e[kMaxN];  // \u533a\u95f4
int n, t;

int F() {                                                                       // \u8ba1\u7b97\u4e00\u53ea\u5976\u725b\u72ec\u5360\u7684\u6700\u77ed\u65f6\u95f4
  int v = 1e9;                                                                  // \u521d\u59cb\u5316\u6700\u503c
  e[0].second = e[1].first, e[n + 1] = {e[n].second, 1e9};                      // \u6784\u9020\u5de6\u53f3\u8fb9\u754c\u533a\u95f4
  for (int i = 1; i <= n; i++) {                                                // \u9010\u4e2a\u5904\u7406\u533a\u95f4
    if (e[i].second <= e[i - 1].second || e[i + 1].first <= e[i - 1].second) {  // \u88ab\u4e0a\u4e2a\u533a\u95f4\u5305\u542b\uff0c\u6216\u76f8\u90bb\u533a\u95f4\u63a5\u4e0a\u4e86
      return 0;
    }
    v = min(v, min(e[i + 1].first, e[i].second) - max(e[i - 1].second, e[i].first));  // \u53bb\u9664\u5f53\u524d\u533a\u95f4\u91cd\u53e0\u7684\u90e8\u5206
  }
  return v;
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> e[i].first >> e[i].second;
  }

  sort(e + 1, e + 1 + n);

  for (int i = 1, r = e[1].first; i <= n; i++) {    // \u9010\u4e2a\u533a\u95f4\u7d2f\u52a0\u65b0\u589e\u957f\u5ea6
    t += max(e[i].second - max(e[i].first, r), 0);  // \u4ece\u5df2\u8986\u76d6\u53f3\u8fb9\u754c\u5f00\u59cb\u8ba1\u7b97\u65b0\u957f\u5ea6
    r = max(r, e[i].second);                        // \u66f4\u65b0\u5df2\u8986\u76d6\u53f3\u8fb9\u754c
  }
  fout << t - F();
  return 0;
}