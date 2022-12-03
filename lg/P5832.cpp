#include <iostream>
#include <map>
#define DEBUG 0

using namespace std;

inline void FileSwitch(const char* InputFileName) {
#if DEBUG
  FILE* STREAM;
  freopen_s(&STREAM, InputFileName, "r", stdin);
#endif
}

signed main() {
  FileSwitch("#1.in");
  int n;
  string s;
  cin >> n >> s;
  for (int l = 1;; l++) {
    bool can = true;
    map<string, int> mp;
    for (int i = 0, j = l; i < n && j <= n; i++, j = i + l) {
      string x = "";
      for (int k = i; k < j; k++)
        x += s[k];
      if (mp[x] == 1) {
        can = false;
        break;
      }
      mp[x] = true;
    }
    if (can) {
      cout << l;
      return 0;
    }
  }
  return 0;
}