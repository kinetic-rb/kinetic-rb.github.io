#include <iostream>

using namespace std;

struct AC {
  int a, b;
  string s;
} m[10005];

int main() {
  string end;
  long long num = 0, ans = 0x7fffffffffffffff, n = 0;
  while (cin >> m[n].a >> m[n].b >> m[n].s)
    if (!m[n].b)
      break;
    else
      n++;
  for (int i = 0; i <= n; i++) {
    num = 0;
    for (int j = 0; j <= n; j++)
      num = num + (m[j].a * abs(m[j].b - m[i].b));
    if (ans >= num) {
      ans = num;
      end = m[i].s;
    }
  }
  cout << end << ' ' << ans;
  return 0;
}