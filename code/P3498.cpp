// \u6e56\u5357\u5e08\u8303\u5927\u5b66\u9644\u5c5e\u4e2d\u5b66 | \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8
#include <iostream>
#include <vector>
#define int LL

using namespace std;
using LL = long long;

const int kM = 10000007;   // \u5927\u8d28\u6570
const LL kB = 19260817;  // \u8fdb\u5236\u5e95\u6570
const int kMaxN = 2e5 + 1;

int a[kMaxN], h[kM];                 // \u5e8f\u5217\u3001\u54c8\u5e0c\u8868
LL pr[kMaxN], su[kMaxN], po[kMaxN];  // \u524d\u7f00\u54c8\u5e0c\u548c\u3001\u540e\u7f00\u54c8\u5e0c\u548c\u3001\u5e95\u6570\u5e42
vector<int> l;                       // \u7b54\u6848\u4f4d\u7f6e
int n, m, ans;

void Init() {  // \u521d\u59cb\u5316\u54c8\u5e0c\u548c
  po[0] = 1;
  for (int i = 1; i <= n; i++) {
    po[i] = po[i - 1] * kB % kM;           // \u6307\u6570\u7d2f\u4e58
    pr[i] = (pr[i - 1] * kB + a[i]) % kM;  // \u524d\u7f00\u7d2f\u52a0
  }
  for (int i = n; i >= 1; i--) {
    su[i] = (su[i + 1] * kB + a[i]) % kM;  // \u540e\u7f00\u7d2f\u52a0
  }
}

signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  Init();
  for (int k = 1; n / k >= ans; k++) {  // \u5207\u5272\u957f\u5ea6
    int c = 0;
    for (int i = k; i <= n; i += k) {                               // \u5207\u5272
      int v0 = (pr[i] - pr[i - k] * po[k] % kM + kM) % kM;          // \u6b63\u5411\u5e8f\u5217\u54c8\u5e0c
      int v1 = (su[i - k + 1] - su[i + 1] * po[k] % kM + kM) % kM;  // \u53cd\u5411\u5e8f\u5217\u54c8\u5e0c
      if (h[v0] != k) {                                             // \u6ca1\u6709\u51fa\u73b0\u8fc7
        c++;
        h[v0] = h[v1] = k;
      }
    }
    if (c > ans) {         // \u66f4\u4f18\u7b54\u6848
      ans = c, l.clear();  // \u66f4\u65b0\u7b54\u6848\uff0c\u6e05\u7a7a\u4f4d\u7f6e
    }
    if (c == ans) {  // \u76f8\u540c\u7b54\u6848
      l.push_back(k);
    }
  }
  cout << ans << " " << l.size() << endl;  // \u8f93\u51fa\u7b54\u6848
  for (int i : l) {                        // \u8f93\u51fa\u4f4d\u7f6e
    cout << i << " ";
  }
  return 0;
}