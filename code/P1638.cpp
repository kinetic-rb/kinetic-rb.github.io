#include <iostream>

using namespace std;

int p[1000001], c[2001];

int main() {
  int n, m, cnt = 0, MIN = 0x7fffffff;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> p[i];
  int a = 1, b = n;
  for (int i = 1, j = 0; i <= n;) {
    while (cnt < m and j < n) {
      j++;
      if (not c[p[j]])
        cnt++;
      c[p[j]]++;
    }
    c[p[i]]--;
    if (not c[p[i]])
      cnt--;
    if (j - i++ < MIN and cnt == m) {
      a = i;
      b = j;
      MIN = j - i + 1;
    }
  }
  cout << a << ' ' << b;
  return 0;
}