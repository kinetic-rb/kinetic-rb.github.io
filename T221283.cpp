#include <iostream>

using namespace std;

inline void move(int x, char a, char b, char c) {
  if (!x)
    return;
  move(x - 1, a, c, b);
  printf("%d %c %c
", x, a, b);
  move(x - 1, c, b, a);
}

int main() {
  int n;
  cin >> n;
  move(n, 'A', 'B', 'C');
  return 0;
}