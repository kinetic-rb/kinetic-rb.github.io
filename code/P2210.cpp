// \u6e56\u5357\u5e08\u8303\u5927\u5b66\u9644\u5c5e\u4e2d\u5b66 | \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8
#include <cstdio>
#include <iostream>

using namespace std;

const int kMaxN = 13;

int p[kMaxN], l[kMaxN][3];
int n, ans = 1e9;

void F(int x, int s, int c, int v) {  // x\u5f53\u524d\u4f4d\u7f6e\uff0cs\u5f53\u524d\u4ee3\u4ef7\uff0cc\u672a\u914d\u5bf9\u7684\u7ebf\u8def\u6570\uff0cv\u672a\u914d\u5bf9\u7ebf\u8def\u7684\u4ee3\u4ef7
  if (s + v >= ans) {                 // \u5f53\u524d\u4ee3\u4ef7\u52a0\u5269\u4f59\u4ee3\u4ef7\u4e0d\u4f1a\u66f4\u4f18
    return;
  }
  if (x > n) {  // \u5b89\u6392\u597d\u4e86n\u53ea\u725b
    ans = s;    // \u66f4\u65b0\u7b54\u6848
    return;
  }
  for (int i = 1; i <= n; i++) {  // \u679a\u4e3e\u5f53\u524d\u4f4d\u7f6e\u653e\u7684\u725b
    if (!p[i]) {
      p[i] = x;
      int ns = 0, nc = 0;             // \u4ee3\u4ef7\u589e\u91cf\uff0c\u672a\u914d\u5bf9\u7ebf\u8def\u6570\u589e\u91cf
      for (int j = 0; j <= 2; j++) {  // \u679a\u4e3e\u597d\u53cb
        if (p[l[i][j]]) {             // \u5df2\u5b89\u6392\u4f4d\u7f6e
          ns += x - p[l[i][j]];       // \u7d2f\u52a0\u589e\u91cf
          nc--;                       // \u51cf\u5c11\u672a\u914d\u5bf9\u7ebf\u8def\u6570
        } else {                      // \u672a\u5b89\u6392\u4f4d\u7f6e
          nc++;                       // \u589e\u52a0\u672a\u914d\u5bf9\u7ebf\u8def\u6570
        }
      }
      F(x + 1, s + ns, c + nc, v - ns + c + nc);  // \u672a\u914d\u5bf9\u4ee3\u4ef7\u8981\u51cf\u53bb\u5df2\u5b8c\u6210\u914d\u5bf9\u7684\u4ee3\u4ef7
      p[i] = 0;
    }
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> l[i][0] >> l[i][1] >> l[i][2];
  }
  F(1, 0, 0, 0);
  cout << ans;
  return 0;
}
