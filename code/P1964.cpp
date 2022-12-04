#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

struct it {
  int a, b, c;
  it() {};
  it(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

map<string, it> mp;
int m, n, dp[100];

int main() {
  cin >> m >> n;
  m = 21 - m;
  int a, b, c;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c >> s;
    if (mp.count(s) == 0) {
      mp.insert(pair<string, it>(s, it(a, b, c)));
    }
    else {
      mp[s].a += a;
    }
  }
  if (!m) {
    cout << "0
";
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
    cout << dp[m] << '\n';
  }
  return 0;
}