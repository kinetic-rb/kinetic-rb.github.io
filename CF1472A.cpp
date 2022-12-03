#include <cstring>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    int w, h, n, cnt = 0;
    cin >> w >> h >> n;
    while (!(w & 1)) {
      w >>= 1;
      cnt++;
    }
    while (!(h & 1)) {
      h >>= 1;
      cnt++;
    }
    puts((1 << cnt) >= n ? "YES" : "NO");
  }
  return 0;
}