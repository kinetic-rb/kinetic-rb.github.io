// \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8 | \u80d6\u5934\u9c7c
#include <algorithm>
#include <iostream>
#define fin cin
#define fout cout

using namespace std;

const int kMaxN = 1e5 + 1;

struct E {
  int p, c[2];                 // \u5f53\u524d\u9009\u62e9\u7684\u4e0b\u6807\u3001\u559c\u6b22\u7684\u9ea6\u7247\u7f16\u53f7
} e[kMaxN] = {{2}};            // \u521d\u59cb\u5316\u8fb9\u754c
int a[kMaxN], b[kMaxN], n, m;  // \u7b54\u6848\u3001\u9009\u62e9\u6bcf\u79cd\u9ea6\u7247\u7684\u5976\u725b

int main() {
  fin >> n >> m;
  for (int i = 1; i <= n; i++) {
    fin >> e[i].c[0] >> e[i].c[1];
  }
  for (int i = n, s = 0; i >= 1; i--) {     // \u5012\u5e8f\u52a0\u5165\u5976\u725b
    for (int j = i; e[j].p < 2; s += !j) {  // \u4e0d\u65ad\u89e3\u51b3\u51b2\u7a81\uff0c\u7d2f\u52a0\u7b54\u6848
      int x = e[j].c[e[j].p++];             // \u5f53\u524d\u5976\u725b\u8981\u9009\u7684\u9ea6\u7247
      if (j < b[x] || !b[x]) {              // \u5f53\u524d\u5976\u725b\u4f18\u5148\u7ea7\u66f4\u9ad8
        swap(b[x], j);                      // \u5207\u6362\u9009\u62e9\uff0c\u7ee7\u7eed\u5904\u7406\u6362\u6389\u7684\u5976\u725b
      }
    }
    a[i] = s;  // \u8bb0\u5f55\u7b54\u6848
  }
  for (int i = 1; i <= n; i++) {
    fout << a[i] << '\n';
  }
  return 0;
}