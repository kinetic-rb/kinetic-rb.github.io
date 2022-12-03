#include <algorithm>
#include <iostream>
#define fin cin
#define fout cout

using namespace std;

const int kMaxN = 1e5 + 1;

int a[kMaxN], n, v;

int C() {
  for (int i = 1, j = 1; i <= n; i++) {           // \u679a\u4e3e\u5de6\u8fb9\u754c
    for (; j <= n && a[j] - a[i] + 1 < n; j++) {  // \u7ef4\u62a4\u53f3\u8fb9\u754c\uff0c\u4f7f\u5f97\u957f\u5ea6\u8fbe\u5230n
    }
    if (j <= n && (a[j] == a[i] + n - 1 || a[j - 1] - a[i] + 2 != n)) {  // \u53f3\u8fb9\u754c\u5b58\u5728\uff0c\u8981\u4e48\u6b63\u597d\u5728\u70b9\u4e0a\uff0c\u8981\u4e48\u5de6\u8fb9\u6709\u7f1d\u9699
      v = max(v, j - i + (a[j] - a[i] + 1 == n));                        // \u66f4\u65b0\u533a\u95f4\u5185\u6700\u5927\u70b9\u6570
    }
  }
  return n - v;  // \u533a\u95f4\u5185\u6700\u5c11\u7a7a\u4f4d
}

int main() {
  fin >> n;
  for (int i = 1; i <= n; i++) {
    fin >> a[i];
  }

  sort(a + 1, a + 1 + n);

  fout << C() << '\n';                                              // \u6700\u5c0f\u6b21\u6570
  fout << a[n] - a[1] + 2 - n - min(a[2] - a[1], a[n] - a[n - 1]);  // \u6700\u5927\u6b21\u6570\uff0c\u9009\u62e9\u8f83\u5c0f\u7f1d\u9699\u5220\u9664
  return 0;
}