#include <iostream>

using namespace std;

bool b[30003];

int main() {
  ios_base::sync_with_stdio(false);
  int n, MIN, A(0), B(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    b[i] = x == 2;
    (b[i] ? A : B)++;
  }
  MIN = min(A, B);
  for (int f = 0; f < n; f++) {
    int sum = 0;
    for (int i = 0; i < f; i++) {
      if (b[i])
        sum++;
    }
    if (sum >= MIN)
      continue;
    for (int i = f; i < n; i++) {
      if (not b[i])
        sum++;
    }
    MIN = min(MIN, sum);
  }
  cout << MIN;
  return 0;
}