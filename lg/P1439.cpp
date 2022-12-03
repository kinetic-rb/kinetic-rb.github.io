#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int pos[100001], c[100001], p[100001];

int main() {
  int n, len = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    c[i] = pos[x];
  }
  for (int i = 1; i <= n; i++)
    p[c[i] > p[len] ? ++len : lower_bound(p + 1, p + len + 1, c[i]) - p] = c[i];
  cout << len;
  return 0;
}