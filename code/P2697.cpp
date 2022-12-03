#include <iostream>

using namespace std;

int ps[1000001];

int main() {
    ios::sync_with_stdio(false);
  int n = 0, MAX = 0;
  for (char ch; cin >> ch; ps[n] = ps[n - 1] + (ch == 'R' ? 1 : -1))
    n++;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      if (!(ps[j] - ps[i - 1]))
        MAX = max(MAX, j - i + 1);
    }
  }
  cout << MAX;
  return 0;
}