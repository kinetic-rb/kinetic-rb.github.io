// \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8 | \u80d6\u5934\u9c7c
#include <algorithm>
#include <iostream>
#define fin cin
#define fout cout

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5 + 1;

Pii e[kMaxN];
int s[kMaxN] = {1 << 30}, n, t;

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> e[i].first >> e[i].second;
  }
  sort(e + 1, e + 1 + n);
  for (int i = 1; i <= n; i++) {
    if (e[i].second < s[t]) {
      s[++t] = e[i].second;
    } else {
      for (; t > 1 && e[i].second >= s[t - 1]; t--) {
        s[t - 1] = s[t];
      }
    }
  }
  fout << t;
  return 0;
}