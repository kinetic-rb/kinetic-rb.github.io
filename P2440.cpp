#include <iostream>
#define int long long

using namespace std;

int lg[100005];
int n, k;

inline bool small(int ml) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += lg[i] / ml;
  return sum >= k;
}

inline int search() {
  int qloc = 0;
  for (int i = 25; i > -1; i--) {
    int loc = qloc + (1 << i);
    if (small(loc)) {
      qloc = loc;
    }
  }
  return qloc;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> lg[i];
  cout << search();
  return 0;
}