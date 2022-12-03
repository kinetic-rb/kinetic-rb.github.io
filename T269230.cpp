// \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8 | \u80d6\u5934\u9c7c
#include <algorithm>
#include <iostream>

using namespace std;
using Pii = pair<int, int>;

const int kMaxN = 1e5;

Pii p[kMaxN];
int n;

int operator*(Pii i, Pii j) {  // \u5411\u91cf\u53c9\u4e58
  return i.first * j.second - i.second * j.first;
}

bool Up(Pii i) {  // \u5224\u65ad\u662f\u5426\u5728\u4e0a\u534a\u5e73\u9762
  return i.second < 0 || !i.second && i.first < 0;
}

int D(Pii i) {  // \u8ba1\u7b97\u5411\u91cf\u957f\u5ea6\u7684\u5e73\u65b9
  return i.first * i.first + i.second * i.second;
}

bool Com(Pii &i, Pii &j) {  // \u5411\u91cf\u6bd4\u8f83\u5668\uff0c\u5148\u4e0a\u4e0b\u3001\u518d\u5de6\u53f3\u3001\u6700\u540e\u8ddd\u79bb
  int ui = Up(i), uj = Up(j), v = i * j;
  return ui < uj || (ui == uj && v > 0) || (ui == uj && !v && D(i) < D(j));
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p, p + n, Com);
  for (int i = 0; i < n; i++) {
    cout << p[i].first << ' ' << p[i].second << '\n';
  }
  return 0;
}