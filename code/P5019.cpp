#include <iostream>

using namespace std;

int main() {
  unsigned long long n, ans = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    static long long b = 0, a;
    cin >> a;
    if (a > b)
      ans += (a - b);
    b = a;
  }
  cout << ans;
  return 0;
}