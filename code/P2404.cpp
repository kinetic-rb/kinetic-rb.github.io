#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

int cho[300] = {1};
int n;

inline void dfs(int s, int t) {
  for (int i = cho[t - 1]; i <= s; i++)
    if (i < n) {
      cho[t] = i;
      s -= i;
      if (!s) {
        for (int i = 1; i < t; i++)
          cout << cho[i] << '+';
        cout << cho[t] << '\n';
      }
      else
        dfs(s, t + 1);
      s += i;
    }
}

int main() {
  cin >> n;
  dfs(n, 1);
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