#include <algorithm>
#include <iostream>

using namespace std;
int main() {
  int q;
  for (cin >> q; q--;) {
\t\tstring s, t, ss = "", tt = "";
    cin >> s >> t;
   \tint x = __gcd(s.size(), t.size());
   \tint t1 = x * (s.size() / x) * (t.size() / x) / s.size(), t2 = x * (s.size() / x) * (t.size() / x) / t.size();
    for (int i = 0; i < t1; i++)
    \tss += s;
\t\tfor (int i = 0; i < t2; i++)
    \ttt += t; 
\t\tif (ss == tt)
\t\t\tcout << ss << '\n';
\t\telse
\t\t\tputs("-1");
\t}
  return 0;
}