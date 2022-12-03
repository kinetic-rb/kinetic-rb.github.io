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

inline void get(int& x, int& y) {
  int sx, sy, ex, ey;
  cin >> sx >> sy >> ex >> ey;
  x = ex - sx;
  y = ey - sy;
}

int main() {
  FileSwitch("^", "#");
  int x, y, dx = 0, dy = 0, n;
  get(x, y);
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    if (c == 'E' && y > 0)
      dy++;
    if (c == 'S' && x < 0)
      dx++;
    if (c == 'W' && y < 0)
      dy++;
    if (c == 'N' && x > 0)
      dx++;
  }
  cout << (dx >= abs(x) && dy >= abs(y) ? abs(x) + abs(y) : -1);
  return 0;
}