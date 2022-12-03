#include <iostream>

using namespace std;

int lg[100005];
int n, k;

inline bool small(int ml) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += lg[i] / ml;
  return sum >= k;
}

inline void search() {
  int qloc = 0;
  for (int i = 29; i > -1; i--) {
    int loc = qloc + (1 << i);
    if (loc > 1e9)
        loc = 1e9;
    cout << loc << endl;
    int m;
    cin >> m;
    if (!m)
      return;
    if (m == -1)
      qloc = loc;
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  search();
  return 0;
}