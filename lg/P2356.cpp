#include <array>
#include <iostream>
#define DEBUG 0

inline void FileSwitch(const char* InputFileName, const char* OutputFileName) {
#if DEBUG
  FILE* STREAM;
  freopen_s(&STREAM, InputFileName, "r", stdin);
#endif
#if DEBUG == 2
  freopen_s(&STREAM, OutputFileName, "w", stdout);
#endif
}

using namespace std;

array<array<int, 1005>, 1005> mp;

signed main() {
  FileSwitch("^", "#");
  bool f = true;
  int n, MAX = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      cin >> mp[i][j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (!mp[i][j]) {
        f = false;
        int sum = 0;
        for (int x = 1; x <= n; x++)
          sum += mp[x][j];
        for (int y = 1; y <= n; y++)
          sum += mp[i][y];
        MAX = max(MAX, sum);
      }
  if (f)
    cout << "Bad Game!";
  else
    cout << MAX;
  return 0;
}