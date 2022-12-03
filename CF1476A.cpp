#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    int n, k, c, sum;
    cin >> n >> k;
    c = n / k;
    if (n % k)
      c++;
    sum = k * c;
    cout << sum / n + bool(sum % n) << '\n';
  }
  return 0;
}