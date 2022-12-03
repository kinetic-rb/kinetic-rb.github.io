#include <iostream>

using namespace std;

int num[1000000];

int main() {
  int n, cnt = 0, temp = 2;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
  }
  for (int i = 1; i < n; i++) {
    if (num[i] > num[i - 1]) {
      temp++;
      continue;
    }
    cnt = max(cnt, temp);
    temp = 1;
  }
  cout << cnt;
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