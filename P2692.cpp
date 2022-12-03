#if false
#include <fstream>
std::ifstream cin("beta.in");
std::ofstream cout(stdout);
#else
#include <iostream>
#endif

using namespace std;

bool row[5005], col[5005];

int main(void) {
  int n, m, b, g, cnt = 0;
  cin >> n >> m >> b >> g;
  for (int i = 0; i < b; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = x; j <= y; j++)
      row[j] = true;
  }
  for (int i = 0; i < g; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = x; j <= y; j++)
      col[j] = true;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (row[i] || col[j])
        cnt++;
  cout << cnt;
  return 0;
}