#include <iostream>

using namespace std;

string up, down;

inline bool cu(int x) {
  if (up[x] != '0')
    return true;
  up[x] = 0;
  return false;
}

inline bool cd(int x) {
  if (down[x] != '0')
    return true;
  down[x] = 0;
  return false;
}

int main() {
  int t;
  for (cin >> t; t; t--) {
    int n;
    cin >> n >> up >> down;
    bool flag = true;
    if ((up[0] == '1' && cd(0) && cu(1)) || (down[0] == '1' && cu(0) && cd(1)))
      flag = false;
    for (int i = 1; i < n; i++)
      if ((up[i] == '1' && cu(i - 1) && cd(i) && cu(i + 1)) ||
          (down[i] == '1' && cd(i - 1) && cu(i) && cd(i + 1))) {
        flag = false;
        break;
      }
    puts(flag ? "RP" : "++");
  }
  return 0;
}