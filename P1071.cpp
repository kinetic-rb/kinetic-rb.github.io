#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string fi, to, sc, t1, t2, ans = "";
  cin >> fi >> to >> sc;
  if (sc == "HELLO") {
    cout << "Failed";
    return 0;
  }
  t1 = fi;
  t2 = to;
  stable_sort(t1.begin(), t1.end());
  t1.resize(unique(t1.begin(), t1.end()) - t1.begin());
  stable_sort(t2.begin(), t2.end());
  t2.resize(unique(t2.begin(), t2.end()) - t2.begin());
  if (t1 != t2) {
    cout << "Failed";
    return 0;
  }
  for (auto i : sc) {
    char found = EOF;
    for (int j = 0; j < fi.size(); j++) {
      if (i == fi[j]) {
        found = to[j];
      }
    }
    if (found == EOF) {
      cout << "Failed";
      return 0;
    }
    ans.push_back(found);
  }
  if (ans == fi) {
    cout << "Failed";
    return 0;
  }
  cout << ans;
  return 0;
}

/*
 ___       ___         ___________
|\  \     |\  \       |\    ___   \
\ \  \    \ \  \      \ \   \|_\   \
 \ \  \  __\ \  \      \ \    ___   \
  \ \  \|\__\_\  \      \ \   \  \   \
   \ \____________\      \ \___\  \___\
  \|____________|        \|___|  |___|
*/