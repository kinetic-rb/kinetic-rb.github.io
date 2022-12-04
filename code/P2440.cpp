#include <algorithm>
#include <iostream>

using namespace std;

int lg[100005];

template <typename comp>
inline int fs(int mi, comp cmp) {
  int qloc = 0;
  for (int pew = 1 << mi; pew; pew >>= 1) {
    int loc = qloc + (pew);
    if (cmp(loc))
      qloc = loc;
  }
  return qloc;
}

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> lg[i];
  cout << fs(27, [&](int ml) {
    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += lg[i] / ml;
    return sum >= k;
  });
  return 0;
}