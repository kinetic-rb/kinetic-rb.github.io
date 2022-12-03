// \u6e56\u5357\u5e08\u8303\u5927\u5b66\u9644\u5c5e\u4e2d\u5b66 | \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8
#include <cstdio>
#include <iostream>

using namespace std;

const int kMaxN = 101;

int a[kMaxN], l[kMaxN];
int n, k, a1, a2, b1, b2;

int C(int s) {  // \u8ba1\u7b97\u8d77\u59cb\u4f4d\u7f6e\u7684\u7ed3\u675f\u70b9
  int i = 0;
  do {
    l[i++] = s;                // \u8bb0\u5f55\u5f53\u524d\u4f4d\u7f6e
    if (s >= a1 && s <= a2) {  // \u7ffb\u8f6c1
      s = a1 + a2 - s;
    }
    if (s >= b1 && s <= b2) {  // \u7ffb\u8f6c2
      s = b1 + b2 - s;
    }
  } while (s != l[0]);  // \u76f4\u5230\u56de\u5230\u8d77\u70b9
  return l[k % i];      // \u8f93\u51fa\u5bf9\u5e94\u4f4d\u7f6e
}

int main() {
  //freopen("swap.in", "r", stdin);
  //freopen("swap.out", "w", stdout);
  cin >> n >> k >> a1 >> a2 >> b1 >> b2;
  for (int i = 1; i <= n; i++) {  // \u679a\u4e3e\u8d77\u59cb\u4f4d\u7f6e
    a[C(i)] = i;                  // \u8bb0\u5f55\u5728\u7ed3\u675f\u4f4d\u7f6e
  }
  for (int i = 1; i <= n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}