#include <iostream>

using namespace std;

long f[30003], s[30003], b[30003];

long find(const long& o) {
  if (f[o] == o)
    return o;
  long t = f[o];
  f[o] = find(f[o]);
  s[o] += s[t];
  b[o] = b[f[o]];
  return f[o];
}

signed main() {
  long n;
  cin >> n;
  for (long i = 1; i < 30002; i++)
    b[f[i] = i] = 1;
  while (n--) {
    char ch;
    long x, y;
    cin >> ch >> x >> y;
    if (ch == 'M') {
      x = find(x);
      y = find(y);
      f[x] = y;
      s[x] += b[y];
      b[x] += b[y];
      b[y] = b[x];
    } else
      cout << (find(x) == find(y) ? abs(s[x] - s[y]) : 0) - 1 << '\n';
  }
  return 0;
}