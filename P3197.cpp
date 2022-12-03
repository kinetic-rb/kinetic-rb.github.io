#include <iostream>

using namespace std;

inline long pow(long a) {
  return (a * a) % 100003;
}

inline long qmi(long a, long b) {
  if(!b)
        return 1;
  return (b & 1) ? pow(qmi(a, b >> 1)) * (a % 100003) % 100003 : pow(qmi(a, b >> 1));
}

int main() {
    long m, n;
    cin >> m >> n;
  long ans = qmi(m, n) - (m % 100003) * qmi(m - 1, n - 1) % 100003;
  while (ans < 0)
      ans += 100003;
    cout << ans % 100003;
  return 0;
}