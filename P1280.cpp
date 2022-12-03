#include <iostream>
#include <vector>

using namespace std;

int f[10002];
vector<int> v[10001];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    int s, t;
    cin >> s >> t;
    v[s].push_back(t);
  }
  for (int i = n; i; i--)
    if (v[i].size())
      for (auto& j : v[i])
        f[i] = max(f[i], f[i + j]);
    else
      f[i] = f[i + 1] + 1;
  cout << f[1];
  return 0;
}