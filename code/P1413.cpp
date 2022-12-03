#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct AC {
  int p, t;
} z[2010];

int main()
{
  int a[7], ans = 0, n;
  cin >> n;
  memset(a, -60, sizeof(a));
  for (int i = 0; i < n; i++)
    cin >> z[i].p >> z[i].t;
  stable_sort(z, z + n, [](const AC& x, const AC& y) {
    return x.t < y.t;
  });
  for (int i = 0; i < n; i++)
    if (!(a[z[i].p] < z[i].t && a[z[i].p] + 60 >= z[i].t)) {
      ans++;
      a[z[i].p] = z[i].t - 1;
    }
  cout << ans;
  return 0;
}