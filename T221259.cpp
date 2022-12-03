#include <iostream>
#define int long

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
  int n, m, x;
  cin >> n >> m >> x;
  for (int i = 0; i < n; i++) {
    char op;
    int temp;
    cin >> op >> temp;
    op == '1' ? x = (x + temp) % m : x = (x * temp) % m;
  }
  cout << x;
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