#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string x;
  cin >> x;
  if (x == "0") {
    cout << 0;
    return 0;
  }
  if (x[0] == '-') {
    cout << '-';
    reverse(x.begin() + 1, x.end());
  } else reverse(x.begin(), x.end());
  int y = x[0] == '-';
  while (x[y] == '0')
    y++;
  for (; y < x.size(); y++)
    cout << x[y];
  return 0;
}