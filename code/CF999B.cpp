#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using bt = long long;

vector<bt> fac;

void fact(bt n) {
  bt i = 2;
  for (fac.push_back(n); i * i < n; ++i) {
    if (!(n % i)) {
      fac.push_back(i);
      fac.push_back(n / i);
    }
  }
  if (i * i == n) {
    fac.push_back(i);
  }
  stable_sort(fac.begin(), fac.end());
}

signed main() {
  bt n;
  string x;
  cin >> n >> x;
  fact(n);
  for (auto&& i : fac) {
    reverse(x.begin(), x.begin() + i);
  }
  cout << x;
  return 0;
}