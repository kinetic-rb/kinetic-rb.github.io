#include <iostream>

using namespace std;
using dt = long long;

int main() {
  dt a, b, c, d, e, f, g, h, i;
  cin >> a >> b >> c >> d >> e >> f >> g >> h >> i;
  cout << (50 + a + b + c + d + e + f + g + h * 5 >= i ? "AKIOI" : "AFO");
  return 0;
}