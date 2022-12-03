#include <iostream>

using namespace std;

int main() {
  int n, MAX = -0x7fffffff, MIN = 0x7fffffff;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    MIN = min(MIN, x);
    MAX = max(MAX, x);
  }
  cout << MAX - MIN;
  return 0;
}