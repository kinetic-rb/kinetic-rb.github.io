// \u6e56\u5357\u5e08\u8303\u5927\u5b66\u9644\u5c5e\u4e2d\u5b66 | \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8
#include <cstdio>
#include <iostream>

using namespace std;

const int kMaxN = 16;
const int kMaxL = 1 << 16;

int l[kMaxL], p[kMaxL];
int n, m, x;
long long b;

int main() {
  cin >> n >> b;
  for (int i = 0; i < n; i++) {  // \u538b\u7f29\u8868\u793a
    cin >> x;
    l[1] |= x << i;
  }
  for (m = 1; !p[l[m]]; m++) {                                           // \u5bfb\u627e\u5faa\u73af\u8282
    p[l[m]] = m;                                                         // \u8bb0\u5f55\u4f4d\u7f6e
    l[m + 1] = l[m] ^ (l[m] << 1 & ((1 << n) - 1)) ^ (l[m] >> (n - 1));  // n\u4f4d\u5faa\u73af\u5de6\u79fb\u53d6\u4e0e
  }

  if (++b >= m) {  // \u8d85\u51fa\u5faa\u73af\u8282\u7684\u90e8\u5206\u53d6\u4f59
    b = (b - p[l[m]]) % (m - p[l[m]]) + p[l[m]];
  }
  for (int i = 0; i < n; i++) {  // \u62c6\u5206\u8f93\u51fa
    cout << (l[b] >> i & 1) << endl;
  }
  return 0;
}