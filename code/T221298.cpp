#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, MAX = 1;
  cin >> n;
  vector<int> num(n), f(n, 1);
  for (auto& i : num)
    cin >> i;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++)
      if (num[j] < num[i])
        f[i] = max(f[j] + 1, f[i]);
    MAX = max(MAX, f[i]);
  }
  cout << MAX;
  return 0;
}