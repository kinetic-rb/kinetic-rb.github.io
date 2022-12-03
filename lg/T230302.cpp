#include <iostream>

using namespace std;
using tp = int64_t;

signed main() {
  tp a, b, c;
  cin >> a >> b;
  a ^= 9961;
  b ^= 9961;
  a += 17;
  b += 17;
  b += a;
  a *= 81;
  b *= 81;
  c = a + b - 4;
  c = (c / 10 * 10 + 1) % 9;
  cout << c;
  return 0;
}