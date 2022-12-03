#include <iostream>

using namespace std;

int num[] = {6, 8, 4, 2};

int main() {
  int n, ans = 1;
  for (cin >> n; n; ans = ans * num[n % 4] % 10) {
    for (int i = 1; i <= n % 10; i++)
      if (i != 5)
        ans = ans * i % 10;
    n /= 5;
  }
  cout << ans;
  return 0;
}