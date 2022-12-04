#include <iostream>
#define int long long

using namespace std;

// \u5728 L ~ R \u4e2d\u9009\u4e00\u4e2a\u6570\uff0c\u4f7f\u5b83 % n \u7684\u4f59\u6570\u6700\u5927 

signed main() {
  int L, R, n, MAX = -1;
  scanf("%lld%lld%lld", &n, &L, &R);
  if (R - L >= n) {
    printf("%lld", n - 1);
    return 0;
  }
  for (int i = L; i < R; i++)
    MAX = max(MAX, i % n);
  printf("%lld", max(MAX, R % n));
  return 0;
}
