// \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8 | \u80d6\u5934\u9c7c
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define fin cin
#define fout cout

using namespace std;

const int kMaxN = 1e3 + 1;

struct V {          // \u70b9
  vector<int> e;    // \u90bb\u70b9
  int d[kMaxN], q;  // \u5230\u5176\u4ed6\u70b9\u7684\u8ddd\u79bb
} v[kMaxN];
int l[kMaxN], f[kMaxN], n, m, e, x, ans;

void S(int s) {                                          // \u8ba1\u7b97s\u70b9\u5230\u5176\u4ed6\u70b9\u7684\u8ddd\u79bb
  queue<int> q;                                          // BFS\u961f\u5217
  for (v[s].d[s] = 1, q.push(s); !q.empty(); q.pop()) {  // \u5904\u7406\u961f\u5217\u4e2d\u6bcf\u4e2a\u70b9
    int x = q.front();                                   // \u53d6\u51fa\u961f\u5934\u7684\u70b9
    for (int i : v[x].e) {                               // \u679a\u4e3e\u90bb\u70b9
      if (!v[s].d[i]) {                                  // \u5c1a\u672a\u5230\u8fbe
        v[s].d[i] = v[s].d[x] + 1;                       // \u8ba1\u7b97\u8ddd\u79bb
        q.push(i);                                       // \u52a0\u5165\u961f\u5217
      }
    }
  }
}

int main() {
  fin >> n >> e;
  for (int i = 1; i <= n; i++) {
    fin >> v[i].q >> m;
    while (m--) {
      fin >> x;             // \u8bfb\u5165\u90bb\u70b9
      v[i].e.push_back(x);  // \u6dfb\u52a0\u8fb9
    }
    l[i] = i;  // \u521d\u59cb\u5316\u4e0b\u6807
  }
  for (int i = 1; i <= n; i++) {  // \u679a\u4e3e\u8d77\u70b9
    S(i);                         // \u8ba1\u7b97\u5230\u5176\u4ed6\u70b9\u8ddd\u79bb
  }

  sort(l + 1, l + 1 + n, [](int i, int j) { return v[i].q < v[j].q; });  // \u6309\u7167\u8d28\u91cf\u6392\u5e8f

  for (int i = 1; i <= n; i++) {                                      // \u679a\u4e3e\u5230\u8fbe\u8349\u5730
    for (int j = 1; j < i && v[l[j]].q < v[l[i]].q; j++) {            // \u679a\u4e3e\u4e0a\u4e00\u5757\u8349\u5730
      if (v[l[i]].d[l[j]]) {                                          // \u6709\u9053\u8def\u8fde\u63a5
        f[l[i]] = max(f[l[i]], f[l[j]] - (v[l[i]].d[l[j]] - 1) * e);  // \u66f4\u65b0\u6700\u503c
      }
    }
    ans = max(ans, f[l[i]] += v[l[i]].q);  // \u7d2f\u52a0\u5f53\u524d\u8349\u5730\u503c\uff0c\u66f4\u65b0\u7b54\u6848
  }
  fout << ans;
  return 0;
}
