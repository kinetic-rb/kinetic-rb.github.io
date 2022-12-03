#include <iostream>

using namespace std;

char b[101][101], ans[101][101];
int dr[][2] = { 1, 0, 0, 1, 1, 1, -1, 0, 0, -1, -1, -1, 1, -1, -1, 1 };
int n;

inline string fs(int x, int y, int px, int py) {
  string s = "";
  for (int cnt = 0; min(x, y) > -1 and max(x, y) < n and cnt < 7; cnt++, x += px, y += py)
    s.push_back(b[x][y]);
  return s;
}

inline void tc(int x, int y, int px, int py) {
  for (int cnt = 0; min(x, y) > -1 and max(x, y) < n and cnt < 7; cnt++, x += px, y += py)
    ans[x][y] = b[x][y];
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> b[i][j];
      ans[i][j] = '*';
    }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (b[i][j] == 'y' || b[i][j] == 'g') {
        for (auto d : dr) {
          if (fs(i, j, d[0], d[1]) == "yizhong" || fs(i, j, d[0], d[1]) == "gnohziy") {
            tc(i, j, d[0], d[1]);
          }
        }
      }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << ans[i][j];
    cout << '\n';
  }
  return 0;
}