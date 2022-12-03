#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = n; i > 0; i--) {
    static int now = 1;
    for (int j = 0; j < i; j++) {
      if (j + now < 10)
        cout << 0;
      cout << j + now;
    }
    now += i;
    cout << '\n';
  }
  return 0;
}