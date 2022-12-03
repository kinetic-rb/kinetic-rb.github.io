#include <iostream>

using namespace std;

int val[100001];

int main() {
  int n, MAX = -0x7fffffff;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> val[i] ;
    MAX = max(val[i] = max(val[i], val[i] + val[i - 1]), MAX);
  }
  cout << MAX;
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