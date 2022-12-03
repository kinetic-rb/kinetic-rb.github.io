// \u6e56\u5357\u5e08\u8303\u5927\u5b66\u9644\u5c5e\u4e2d\u5b66 | \u72c2\u72fc\u7535\u7ade\u4ff1\u4e50\u90e8
#include <cstdio>
#include <iostream>

using namespace std;

int n, ans;
string s, t;

int main() {
  //freopen("breedflip.in", "r", stdin);
  //freopen("breedflip.out", "w", stdout);
  cin >> n;
  cin >> s >> t;
  for (int i = 0; i < n; i++) {
    ans += s[i] != t[i] && (!i || s[i - 1] == t[i - 1]);  // \u5224\u65ad\u662f\u5426\u65b0\u5f00\u4e00\u4e2a\u5b50\u6bb5
  }
  cout << ans;
  return 0;
}