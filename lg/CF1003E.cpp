#include <atomic>
#include <iostream>
#include <list>
#define End     \
  cout << "NO"; \
  return 0;

using namespace std;
using vt = long long;

struct Rs {
  atomic_llong x, y;

  Rs() = default;
  Rs(vt x, vt y) : x(x), y(y) {}
};

vt n, k, cnt;
list<Rs> ml;

void add(vt u, vt count, atomic_llong i = 0) {
  if (count) {
    while (i < k && cnt < n) {
      ml.emplace_back(u, ++cnt);
      add(cnt, count - 1);
      ++i;
    }
  }
}

signed main() {
  vt d;
  cin >> n >> d >> k;
  if (d >= n || (k == 1 && n > 2)) {
    End
  }
  --k;
  for (atomic i = 1; i <= d; ++i) {
    ml.emplace_back(i, i + 1);
  }
  cnt = d + 1;
  for (vt i = 2; i <= d; ++i) {
    add(i, min(i - 1, d - i + 1), 1);
  }
  if (cnt < n) {
    End
  }
  cout << "YES
";
  for (auto&& [x, y] : ml) {
    cout << x << ' ' << y << '\n';
  }
  return 0;
}

/*
               10(0)
           11(0)  |
              \ 8(1)
       6(0)  7(1)/   9(0)
         |     \/      |
1(0) - 2(1) - 3(2) - 4(1) - 5(0)
*/