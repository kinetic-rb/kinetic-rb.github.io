#if false
#include <fstream>
std::ifstream cin("beta.in");
std::ofstream cout(stdout);
#else
#include <iostream>
#endif
#include <cstring>
#define int long

using namespace std;

signed main() {
  int n, m, y, sum = 0, *f = new int[100001];
  memset(f, 0, 400004);
  cin >> n >> m >> y;
  for (int i = 2; i <= m; i++) {
    int x;
    cin >> x;
    f[min(x, y)]++;
    f[max(x, y)]--;
    y = x;
  }
  for (int i = 1; i < n; i++) {
    static int k = 0;
    int a, b, c;
    cin >> a >> b >> c;
    k += f[i];
    sum += min(a * k, b * k + c);
  }
  cout << sum;
  return 0;
}