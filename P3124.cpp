// \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8 | \u80d6\u5934\u9c7c
#include <algorithm>
#include <iostream>
#define fin cin
#define fout cout

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5 + 1, kInf = 1e9;

Pii e[kMaxN];  // \u5e72\u8349\u5806\uff0c\u4f4d\u7f6e\u548c\u91cd\u91cf
int l[kMaxN], n, b, p, ans = kInf;

int main() {
  fin >> n >> b;
  for (int i = 1; i <= n; i++) {
    fin >> e[i].second >> e[i].first;
    l[i] = i;  // \u521d\u59cb\u5316\u4e0b\u6807
  }
  sort(e + 1, e + 1 + n);
  for (p = 1; p <= n && e[p].first < b; p++) {  // \u627e\u5230\u5976\u725b\u53f3\u8fb9\u7684\u8349\u5806\u4e0b\u6807
  }
  // \u4fee\u6539\u70b9\u5728\u5de6\u8fb9
  sort(l + p, l + 1 + n, [](int i, int j) { return e[i].first - e[i].second < e[j].first - e[j].second; });
  for (int i = 1, j = p, mn = kInf; i < p; i++) {                         // \u7531\u5c0f\u5230\u5927\u679a\u4e3e\u4fee\u6539\u70b9
    for (; j <= n && e[l[j]].first - e[l[j]].second < e[i].first; j++) {  // \u8003\u8651\u66f4\u591a\u53ef\u7528\u53f3\u8fb9\u754c
      mn = min(mn, e[l[j]].first);                                        // \u66f4\u65b0\u6700\u503c
    }
    ans = min(ans, mn == kInf ? kInf : mn - e[i].first - e[i].second);  // \u66f4\u65b0\u7b54\u6848
  }
  // \u4fee\u6539\u70b9\u5728\u53f3\u8fb9
  sort(l + 1, l + p, [](int i, int j) { return e[i].first + e[i].second < e[j].first + e[j].second; });
  for (int i = n, j = p - 1, mx = -kInf; i >= p; i--) {                   // \u7531\u5927\u5230\u5c0f\u679a\u4e3e\u4fee\u6539\u5e26\u4f60
    for (; j >= 1 && e[l[j]].first + e[l[j]].second > e[i].first; j--) {  // \u8003\u8651\u66f4\u591a\u53ef\u7528\u5de6\u8fb9\u754c
      mx = max(mx, e[l[j]].first);                                        // \u66f4\u65b0\u6700\u503c
    }
    ans = min(ans, mx == -kInf ? kInf : e[i].first - e[i].second - mx);  // \u66f4\u65b0\u7b54\u6848
  }
  ans = max(ans, 0);
  fout << (ans == kInf ? -1 : ans);
  return 0;
}
