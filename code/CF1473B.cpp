#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  int q;
  for (cin >> q; q--;) {
    string s, t, ss = "", tt = "";
    cin >> s >> t;
     int x = __gcd(s.size(), t.size());
     int t1 = x * (s.size() / x) * (t.size() / x) / s.size(), t2 = x * (s.size() / x) * (t.size() / x) / t.size();
    for (int i = 0; i < t1; i++)
      ss += s;
    for (int i = 0; i < t2; i++)
      tt += t; 
    if (ss == tt)
      cout << ss << '\n';
    else
      puts("-1");
  }
  return 0;
}