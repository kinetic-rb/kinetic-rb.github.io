#include <algorithm>
#include <iostream>

using namespace std;

struct CE {
  int val, id;
} f[100005];
int n;

inline int fs(int val, int Max) {
  int qloc = 0;
  for (int pew = Max; pew; pew >>= 1) {
    int loc = qloc + pew;
    if (loc <= n) {
      if (f[loc].val == val)
        return f[loc].id;
      if (f[loc].val < val)
        qloc = loc;
    }
  }
  return 0;
}

int main() {
  int m;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> f[i].val;
    f[i].id = i;
  }
  cin >> m;
  stable_sort(f + 1, f + n + 1,
              [](const CE& x, const CE& y) { return x.val < y.val; });
  for (int qs; m--; cout << fs(qs, 1 << 27) << '\n')
    cin >> qs;
  return 0;
}