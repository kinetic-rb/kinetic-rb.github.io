#include <iostream>
#include <algorithm>

using namespace std;

struct AC {
  int num, mark;
} p[10000];

int main() {
  int m, n;
  cin >> n >> m;
  for (int i = 1; i <= n; cin >> p[i].num >> p[i++].mark);
  stable_sort(p + 1, p + n + 1, [](const AC& x, const AC& y) {
    if (x.mark == y.mark)
      return x.num < y.num;
    return (x.mark > y.mark);
  });
  for (m *= 1.5; p[m].mark == p[m + 1].mark; m = m + 1);
  cout << p[m].mark << ' ' << m << '\n';
  for (int i = 1; i <= m; i++) {
    cout << p[i].num << ' ' << p[i].mark << '\n';
  }
  return 0;
}