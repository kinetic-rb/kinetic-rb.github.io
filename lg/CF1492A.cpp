#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    long long p, a, b, c;
    cin >> p >> a >> b >> c;
    cout << min(min((a - p % a) % a, (b - p % b) % b), (c - p % c) % c) << '\n';
  }
  return 0;
}