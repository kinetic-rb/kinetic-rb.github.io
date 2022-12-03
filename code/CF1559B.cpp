#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int st = n - 1;
    char first = 'R';
    for (int i = 0; i < n; i++) {
      if (s[i] != '?') {
        st = i - 1;
        first = s[i] == 'R' ? 'B' : 'R';
        break;
      }
    }
    for (int i = st; i >= 0; i--) {
      s[i] = first;
      first = first == 'R' ? 'B' : 'R';
    }
    for (int i = st + 1; i < n; i++) {
      if (s[i] == '?') {
        s[i] = s[i - 1] == 'R' ? 'B' : 'R';
      }
    }
    cout << s << '\n';
  }
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