#include <iostream>

using namespace std;

int a[1005][1005], b[100005];
int n;

int main() {
    ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    a[x1][y1]++;
    a[x2 + 1][y1]--;
    a[x1][y2 + 1]--;
    a[x2 + 1][y2 + 1]++;
  }
  for (int i = 1; i < 1002; i++)
    for (int j = 1, s = 0; j < 1002; j++) {
      a[i][j] += a[i - 1][j];
      s += a[i][j];
      b[s]++;
    }
  for (int i = 1; i <= n; i++)
    cout << b[i] << ' ';
  return 0;
}