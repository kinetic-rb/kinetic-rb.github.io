#include <algorithm>
#include <iostream>

using namespace std;

const int kMaxN = 102, kMaxL = 31;

struct P {          // \u5c5e\u6027\u79cd\u7c7b
  int r, w;         // \u4f4d\u6743\u3001\u8fdb\u7387
  string s[kMaxN];  // \u4f4d\u4e0a\u7684\u6570\u5bf9\u5e94\u7684\u5c5e\u6027\u503c
} p[kMaxL];
string s[kMaxN][kMaxL], str;
int b[kMaxN][kMaxL], v[kMaxN], n, k, l, x;

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> str >> str >> str >> str;
    for (l = 0;; l++) {  // \u8bfb\u5165\u5c5e\u6027
      cin >> str;
      if (str == "cow.") {  // \u5c5e\u6027\u7ed3\u675f
        break;
      }
      s[i][l] = str, b[i][l] = 1;       // \u8bb0\u5f55\u5c5e\u6027\u3001\u521d\u59cb\u5316\u9996\u6b21\u51fa\u73b0\u6807\u8bb0
      for (int j = 1; j < i; j++) {     // \u679a\u4e3e\u4e4b\u524d\u7684\u540c\u7c7b\u5c5e\u6027
        b[i][l] &= s[j][l] != s[i][l];  // \u5224\u91cd\u6807\u8bb0\u662f\u5426\u9996\u6b21\u51fa\u73b0
      }
    }
  }
  for (int k = l - 1; k >= 0; k--) {                    // \u6743\u91cd\u7531\u4f4e\u5230\u9ad8\u679a\u4e3e\u5c5e\u6027\u7c7b\u578b
    p[k].w = k == l - 1 ? 1 : p[k + 1].w * p[k + 1].r;  // \u8ba1\u7b97\u5f53\u524d\u5c5e\u6027\u7684\u4f4d\u6743
    for (int i = 1; i <= n; i++) {                      // \u679a\u4e3e\u6bcf\u53ea\u5976\u725b
      int c = 0;                                        // \u521d\u59cb\u5316\u4f4d\u4e0a\u7684\u503c
      for (int j = 1; j <= n; j++) {                    // \u679a\u4e3e\u5176\u4ed6\u5976\u725b
        c += b[j][k] && s[j][k] < s[i][k];              // \u8ba1\u7b97\u8f83\u5c0f\u540c\u7c7b\u5c5e\u6027\u6570\u91cf
      }
      p[k].r = max(p[k].r, c + 1);  // \u66f4\u65b0\u8fdb\u7387
      p[k].s[c] = s[i][k];          // \u8bb0\u5f55\u503c\u5bf9\u5e94\u7684\u5c5e\u6027
      v[i] += c * p[k].w;           // \u7d2f\u52a0\u4f4d\u5bf9\u5e94\u7684\u503c
    }
  }
  sort(v + 1, v + 1 + n);             // \u5c06\u62e5\u6709\u7684\u5976\u725b\u6309\u503c\u6392\u5e8f
  v[0] = -1, v[n + 1] = 1e9 + 1;      // \u521d\u59cb\u5316\u8fb9\u754c
  for (int i = 1; i <= n + 1; i++) {  // \u679a\u4e3e\u7f1d\u9699\u5bfb\u627e\u7b2ck\u53ea
    if (k <= v[i] - v[i - 1] - 1) {   // \u5728\u5f53\u524d\u7f1d\u9699\u4e2d
      x = v[i - 1] + k;
      break;
    } else {
      k -= v[i] - v[i - 1] - 1;  // \u51cf\u53bb\u5f53\u524d\u7f1d\u9699\u957f\u5ea6
    }
  }
  for (int i = 0; i < l; i++) {   // \u503c\u8f6c\u6df7\u5408\u8fdb\u5236
    int y = x / p[i].w % p[i].r;  // \u8ba1\u7b97\u4f4d\u4e0a\u7684\u503c
    cout << (i ? " " : "") << p[i].s[y];
  }
  return 0;
}