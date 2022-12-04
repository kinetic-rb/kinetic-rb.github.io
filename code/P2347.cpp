#include <iostream>
#define DEBUG 0

inline void FileSwitch(const char* InputFileName, const char* OutputFileName) {
#if DEBUG
  freopen(InputFileName, "r", stdin);
#endif
#if DEBUG == 2
  freopen(OutputFileName, "w", stdout);
#endif
}

using namespace std;

bool vis[1003];

signed main() {
  FileSwitch("^", "#");
  int a1, a2, a3, a4, a5, a6, cnt = 0;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  for (int _1 = 0; _1 <= a1; _1++)
    for (int _2 = 0; _2 <= a2; _2++) {
      int c2 = _2 << 1;
      for (int _3 = 0; _3 <= a3; _3++) {
        int c3 = _3 * 3;
        for (int _4 = 0; _4 <= a4; _4++) {
          int c4 = _4 * 5;
          for (int _5 = 0; _5 <= a5; _5++) {
            int c5 = _5 * 10;
            for (int _6 = 0; _6 <= a6; _6++)
              vis[_1 + c2 + c3 + c4 + c5 + _6 * 20] = true;
          }
        }
      }
    }
  for (int i = 1; i < 1003; i++)
    if (vis[i])
      cnt++;
  cout << "Total=" << cnt;
  return 0;
}