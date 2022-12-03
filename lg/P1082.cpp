#include <iostream> 
#include <utility>

using namespace std;
using tp = long long;

void exgcd(tp a, tp b, tp& x, tp& y) {
  if (b) {
    exgcd(b, a % b, x, y);
    y = exchange(x, y) - a / b * y;
  } else {
    x = (y = 0) + 1;
  }
}

signed main() {
  tp a, b, x, y;
  cin >> a >> b;
  exgcd(a, b, x, y);
  cout << (x % b + b) % b << '\n';
  return 0;
}