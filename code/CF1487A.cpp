#include <iostream>
#include <algorithm>

using namespace std;

int d[10000];

int main() {
  int t;
  for (cin >> t; t--;) {
    int n, cnt = 0, m;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> d[i];
    m = *min_element(d, d + n);
    for (int i = 0; i < n; i++)
      if (d[i] != m)
        cnt++;
    cout << cnt << '\n';
  }
  return 0;
}