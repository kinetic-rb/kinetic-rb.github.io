#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
struct it{
  int a, b, c;  //n, w, v;
  it(){}
  it(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};
map<string, it>mp;
int m, n, dp[100];
int main() {
  cin >> m >> n;
  m = 21 - m;  // V 
  int a, b, c;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c >> s;
    if (mp.count(s) == 0) {  //\u4e0d\u5b58\u5728 
      mp.insert(pair<string, it>(s, it(a, b, c)));
    } else {
      mp[s].a += a;
    }
  }
  if (m == 0) {
    cout << 0 << endl;
  } else {
    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
      it temp = iter->second;
      for (int j = m; j > 0; j--) {
        for (int k = 0; k <= temp.a; k++) {
          if (k <= temp.c) {
            dp[j] = max(dp[j - 1] + k * temp.b, dp[j]);
          }
        }
      }
    }
    cout << dp[m] << endl;
  }
  return 0;
} 