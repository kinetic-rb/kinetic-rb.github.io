#include <iostream>

using namespace std;

int cnt[10];

int main() {
  int n, m;
  for (cin >> n >> m; n <= m; n++) {
    for (int temp = n; temp; temp /= 10)
      cnt[temp % 10]++;
  }
  for (auto& i : cnt)
    cout << i << ' ';
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