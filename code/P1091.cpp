#include <iostream>
#include <algorithm>

using namespace std;

int up[1001], down[1001], num[1001];

int main() {
  int n, MAX = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    up[i] = down[i] = 1;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      if (num[j] < num[i])
        up[i] = max(up[i], up[j] + 1);
    }
  for (int i = n - 1; i > -1; i--)
    for (int j = i; j < n; j++) {
      if (num[j] < num[i])
        down[i] = max(down[i], down[j] + 1);
    }
  for (int i = 0; i < n; i++) {
    MAX = max(MAX, up[i] + down[i] - 1);
  }
  cout << n - MAX;
  return 0;
}