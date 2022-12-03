#include <iostream>

using namespace std;

int main() {
  int x;
  cin >> x;
  printf("Today, I ate %d apple", x);
  if (x > 1)
    cout << 's';
  cout << '.';
  return 0;
}