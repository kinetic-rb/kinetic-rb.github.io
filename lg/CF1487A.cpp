#include <iostream>
#include <algorithm>

using namespace std;

int d[10000];

int main() {
\tint t;
  for (cin >> t; t--;) {
    int n, cnt = 0, m;
    cin >> n;
    for (int i = 0; i < n; i++)
\t\t\tcin >> d[i];
    m = *min_element(d, d + n);
    for (int i = 0; i < n; i++)
\t\t\tif (d[i] != m)
\t\t\t\tcnt++;
\t\tcout << cnt << '\n';
  }
  return 0;
}