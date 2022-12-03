#if false
#include <fstream>
std::ifstream cin("beta.in");
std::ofstream cout(stdout);
#else
#include <iostream>
#endif
#define int long

using namespace std;

signed main() {
  int n, k, MAX = -0x7fffffff, *sum = new int[2000002];
  cin >> n >> k;
  *sum = 0;
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    sum[i] = sum[i - 1] + x;
  }
  for (int i = 1; i < n; i++)
    MAX = max(MAX, i + k < n ? sum[i + k - 1] - sum[i - 1]
                             : sum[n - 1] - sum[n - k - 1]);
  cout << sum[n - 1] - MAX;
  return 0;
}