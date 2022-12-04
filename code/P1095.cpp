#include <iostream>

using namespace std;

int f[300006];

int main() {
  int m, s, t;
  cin >> m >> s >> t;
  for (int i = 1; i <= t; i++) {
    if (m > 9) {
      f[i] = f[i - 1] + 60;
      m -= 10;
      continue;
    }
    f[i] = f[i - 1];
    m += 4;
  }
  for (int i = 1; i <= t; i++) {
    f[i] = max(f[i], f[i - 1] + 17);
    if (f[i] >= s) {
      cout << "Yes
" << i;
      return 0;
    }
  }
  cout << "No
" << f[t];
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