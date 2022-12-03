#include <iostream>

using namespace std;

int num[50005];
int n, m, l;

inline bool small(int x) {
  int now = 0, s = 0;
  for (int i = 1; i <= n; i++)
    num[i] - num[now] < x ? s++ : now = i;
  return s <= m;
}

inline int search() {
  int qloc = 0, pew = 1 << 27;
  for (int i = 26; i > -1; i--) {
    int loc = qloc + (pew >>= 1);
    if (small(loc))
      qloc = loc;
  }
  return qloc;
}

int main() {
  cin >> l >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  num[++n] = l;
  cout << search();
  return 0;
}