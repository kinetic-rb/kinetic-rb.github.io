#include <iostream>

using namespace std;

int MIN;

inline void dfs(int a, int b, int step) {
  if (step > MIN)
    return;
  if (!a) {
    MIN = min(MIN, step);
    return;
  }
  if (b != 1)
    dfs(a / b, b, step + 1);
  dfs(a, b + 1, step + 1);
}

int main() {
  int t;
  for (cin >> t; t--; cout << MIN << '\n') {
    int a, b;
    cin >> a >> b;
    MIN = a + 1;
    dfs(a, b, 0);
  }
  return 0;
}