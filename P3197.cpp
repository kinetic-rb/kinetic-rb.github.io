#include <iostream>

using namespace std;

inline long pow(long a) {
\treturn (a * a) % 100003;
}

inline long qmi(long a, long b) {
\tif(!b)
      \treturn 1;
\treturn (b & 1) ? pow(qmi(a, b >> 1)) * (a % 100003) % 100003 : pow(qmi(a, b >> 1));
}

int main() {
  \tlong m, n;
  \tcin >> m >> n;
\tlong ans = qmi(m, n) - (m % 100003) * qmi(m - 1, n - 1) % 100003;
\twhile (ans < 0)
      ans += 100003;
  \tcout << ans % 100003;
\treturn 0;
}