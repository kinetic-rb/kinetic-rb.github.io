#include <algorithm>
#include <iostream>

using namespace std;

int f[1000005];
int n;

inline int fs(int val, int Max) {
  int qloc = 0;
  for (int pew = Max; pew; pew >>= 1) {
    int loc = qloc + pew;
    if (loc <= n) {
      if (f[loc] == val)
        return loc;
      if (f[loc] < val)
        qloc = loc;
    }
  }
  return 0;
}

int main() {
  int m;
  cin >> n;
  cin >> m;
  for (int i = 1; i <= n; i++)
    cin >> f[i];
  stable_sort(f + 1, f + n + 1);
  for (int qs; m--; cout << fs(qs, 1 << 27) << '\n')
    cin >> qs;
  return 0;
}