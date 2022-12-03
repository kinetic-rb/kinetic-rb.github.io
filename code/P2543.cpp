#include <iostream>

using namespace std;

int f[10001][10001];

int main() {
  string a, b;
  cin >> a >> b;
  for (int i = 1; i <= a.size(); i++)
    for (int j = 1; j <= b.size(); j++)
      f[i][j] = (a[i - 1] == b[j - 1] ? f[i - 1][j - 1] + 1
                                      : max(f[i][j - 1], f[i - 1][j]));
  cout << f[a.size()][b.size()];
  return 0;
}