#include <iostream>

using namespace std;

int main() {
  int n, a, b, c, MAX = 0;
  cin >> n >> a >> b >> c;
  if (!(n % min(a, min(b, c)))) {
    cout << n / min(a, min(b, c));
    return 0;
  }
  for (int i = 0; i * a <= n; i++) {
    int X = i * a;
    for (int j = 0; X + j * b <= n; j++) {
      int Y = j * b;
      for (int k = 0; X + Y + k * c <= n; k++)
        if (X + Y + k * c == n)
          MAX = max(MAX, i + j + k);
    }
  }
  cout << MAX;
  return 0;
}