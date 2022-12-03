#include <iostream>
#include <cmath>
#define int long

using namespace std;

int f[200];

inline int fx(int n) {
  \tif (f[n])
    \treturn f[n];
  \treturn f[n] = fx(n - 1) + fx(n - 2);
}

signed main() {
  \t*f = f[1] = 1;
  \tint x, i;
  \tcin >> x;
  \tfx(64);
  \tfor (i = 0; fx(i) + fx(i + 1) < x; i++);
  \tprintf("m=%d
n=%d", fx(i), fx(i + 1));
  \treturn 0;
}