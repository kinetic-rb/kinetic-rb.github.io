#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct water{
  int time, no;
} t[1005];

int main() {
  double ans = 0;
  int n, sum = 0;
  cin >> n;
  for (int i = 0; i < n; t[i].no = ++i) {
    cin >> t[i].time;
    sum += t[i].time;
  }
  stable_sort(t, t + n, [](water x, water y) {
      return x.time < y.time;
  });
  for (int i = 0; i < n; i++)
    cout << t[i].no + 1 << " ";
  for (int i = 0; i < n; i++)
    ans += t[i].time * (n - i);
  ans -= sum;
  cout << '\n' << fixed << setprecision(2) << ans / n;
  return 0;
}