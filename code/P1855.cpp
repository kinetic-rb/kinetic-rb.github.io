#include <iostream>

using namespace std;

int n, tim, mon;
int t[101], m[101], f[201][201];

int main() {
  cin >> n >> mon >> tim;
  for (int i = 1; i <= n; i++)
    cin >> m[i] >> t[i];
  for (int i = 1; i <= n; i++)
    for (int j = mon; j >= m[i]; j--)
      for (int k = tim; k >= t[i]; k--)
        f[j][k] = max(f[j][k], f[j - m[i]][k - t[i]] + 1);
  cout << f[mon][tim];
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