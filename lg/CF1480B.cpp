#include <iostream>
#define int long long

using namespace std;

const int N = 1e5 + 5;

int t, n, hp[N], at[N], hh, ha;

signed main() {
  for (cin >> t; t--;) {
    bool f = false;
    int sum = 0;
    cin >> ha >> hh >> n;
    for (int i = 1; i <= n; i++)
      cin >> at[i];
    for (int i = 1; i <= n; i++)
      cin >> hp[i];
    for (int i = 1; i <= n; ++i)
      sum += at[i] * ((hp[i] + ha - 1) / ha);
    for (int i = 1; i <= n; ++i)
      if (hh - sum + at[i] > 0) {
        puts("YeS");
        f = true;
        break;
      }
    if (!f)
    \tputs("No");
  }
  return 0;
}