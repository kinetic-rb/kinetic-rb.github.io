#include <iostream>

using namespace std;

int num[101];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < i; j++)
      if (num[j] < num[i])
        cnt++;
    cout << cnt << ' ';
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