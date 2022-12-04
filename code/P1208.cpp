#include <iostream>
#include <algorithm>

using namespace std;

struct milk {
  int p, a;
} mi[5005];

int main() {
  int n, m, ps = 0;
  cin >> n >> m;
  if (!n) {
    for (int i = 0; i < 9999999; i++);
    cout << 0;
    return 0;
  }
  for (int i = 0; i < m; i++)
    cin >> mi[i].p >> mi[i].a;
  stable_sort(mi, mi + m, [](milk x, milk y) {
    return x.p < y.p;
  });
  for (int i = 0;; ++i) {
      static auto ptr = mi;
    if (n <= ptr->a) {
      ps += ptr->p * n;
      break;
    }
    n -= ptr->a;
    ps += ptr->p * ptr->a;
    ++ptr;
  }
  cout << ps;
  return 0;
}