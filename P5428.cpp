// \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8 | \u80d6\u5934\u9c7c
#include <algorithm>
#include <iostream>
#include <set>
#define fin cin
#define fout cout

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5 + 1;

Pii p[kMaxN * 2];
int l[kMaxN * 2], n;

Pii operator-(const Pii &a, const Pii &b) { return {a.first - b.first, a.second - b.second}; }  // \u5411\u91cf\u51cf\u6cd5

int operator*(const Pii &x, const Pii &y) {  // \u5411\u91cf\u53c9\u4e58\u7684\u7b26\u53f7
  long long v = 1LL * x.first * y.second - 1LL * x.second * y.first;
  return v < 0 ? -1 : v > 0;
}

bool C(int i, int j) {  // \u5224\u65ad\u7ebf\u6bb5\u4ea4\uff0c\u4e92\u76f8\u6a2a\u8de8
  return ((p[i + n] - p[i]) * (p[j] - p[i])) * ((p[i + n] - p[i]) * (p[j + n] - p[i])) <= 0 &&
         ((p[j + n] - p[j]) * (p[i] - p[j])) * ((p[j + n] - p[j]) * (p[i + n] - p[j])) <= 0;
}

Pii F() {                                           // \u5bfb\u627e\u76f8\u4ea4\u7684\u7ebf\u6bb5
  set<Pii> s;                                       // \u6309\u7167y\u6392\u5e8f\u7684\u5750\u6807\u548c\u7f16\u53f7
  for (int i = 1; i <= 2 * n; i++) {                // \u626b\u63cf\u6bcf\u4e2a\u70b9
    if (l[i] <= n) {                                // \u5de6\u7aef\u70b9
      auto j = s.lower_bound({p[l[i]].second, 0});  // \u4e0a\u65b9\u90bb\u70b9
      if (j != s.end() && C(l[i], j->second)) {
        return {l[i], j->second};
      }
      if (j != s.begin() && C(l[i], (--j)->second)) {  // \u4e0b\u65b9\u90bb\u70b9
        return {l[i], j->second};
      }
      s.insert({p[l[i]].second, l[i]});                        // \u63d2\u5165\u96c6\u5408
    } else {                                                   // \u53f3\u7aef\u70b9
      s.erase({p[l[i] - n].second, l[i] - n});                 // \u5c06\u5de6\u7aef\u70b9\u4ece\u96c6\u5408\u4e2d\u5220\u9664
      auto j = s.lower_bound({p[l[i] - n].second, 0}), k = j;  // \u4e0a\u65b9\u90bb\u70b9
      if (j != s.end() && j != s.begin() && C(j->second, (--k)->second)) {
        return {j->second, k->second};
      }
    }
  }
  return {0, 0};
}

int W(int i) {                    // \u8ba1\u7b97\u7ebf\u6bb5\u76f8\u4ea4\u6570\u91cf
  int c = 0;                      // \u521d\u59cb\u5316\u6570\u91cf
  for (int j = 1; j <= n; j++) {  // \u679a\u4e3e\u5176\u4ed6\u7ebf\u6bb5
    c += i != j && C(i, j);       // \u7d2f\u52a0\u6570\u91cf
  }
  return c;
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> p[i].first >> p[i].second >> p[i + n].first >> p[i + n].second;
    if (p[i].first > p[i + n].first) {
      swap(p[i], p[i + n]);  // \u5c06\u5de6\u7aef\u70b9\u8c03\u6574\u5230\u524d\u9762
    }
    l[i] = i, l[i + n] = i + n;  // \u521d\u59cb\u5316\u7f16\u53f7
  }

  sort(l + 1, l + 1 + 2 * n, [](int i, int j) { return p[i] < p[j]; });

  Pii ans = F();
  if (ans.first > ans.second) {
    swap(ans.first, ans.second);  // \u8f83\u5c0f\u7f16\u53f7\u653e\u524d\u9762
  }
  fout << (W(ans.second) > 1 ? ans.second : ans.first);
  return 0;
}