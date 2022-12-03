#include <cstring>
#include <cmath>
#include <iostream>
#define int long long

using namespace std;

int num[100001];

signed main() {
  int t;
  for (cin >> t; t--;) {
    int n, x, num1 = 0, num2 = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
      int b;
      cin >> b;
      num1 += (long long)ceil(b * 1.0 / x);
      num2 += b;
    }
    cout << (long long)ceil(num2 * 1.0 / x) << ' ' << num1 << '\n';
  }
  return 0;
}