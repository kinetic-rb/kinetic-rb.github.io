#include <iostream>

using namespace std;

inline static int qpew(int a, int n, int m) {
  if (n == 1) {
    return a % m;
  }
  if (!n) {
    return 1;
  }
  int r = qpew(a, n >> 1, m);
  r = r * r % m;
  return n & 1 ? a * r % m : r;
}

int main() {
  ios_base::sync_with_stdio(false);
  int t, a, n, m;
  for (cin >> t; t--; cout << qpew(a, n, m) << '\n') {
    cin >> a >> n >> m;
  }
  return 0;
}

/*
 ___       ___         ___________
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
    \|____________|       \|___|  |___|
*/