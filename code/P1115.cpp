#include <iostream>

using namespace std;

int main() {
  int n, sum = 0, MAX = -0x7fffffff;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    sum += x;
    MAX = max(MAX, sum);
    sum = max(sum, 0);
  }
  cout << MAX;
  return 0;
}