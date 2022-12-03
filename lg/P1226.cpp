#include <iostream>
#define int long

using namespace std;

inline int qpew(int a, int n, int m) {
\tint ans = 1;
\ta %= m;
\twhile (n) {
\t\tif (n & 1)
\t\t\tans = ans * a % m;
\t\tn >>= 1;
\t\ta = (a * a) % m;
\t}
\treturn ans;
}

signed main() {
\tint a, n, m;
\tcin >> a >> n >> m;
  \tprintf("%d^%d mod %d=%d", a, n, m, qpew(a, n, m));
\treturn 0;
}