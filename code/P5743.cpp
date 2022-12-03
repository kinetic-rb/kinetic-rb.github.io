#include <iostream>

using namespace std;

int main() {
  int n, now = 1;
  cin >> n;
  for (int i = 1; i < n; i++) {
    now = ((now + 1) << 1);
  }
  cout << now;
  return 0;
}