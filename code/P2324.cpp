#include <iostream>

using namespace std;

int num[5][5],
    ans[5][5] = {{1, 1, 1, 1, 1},
                 {0, 1, 1, 1, 1},
                 {0, 0, 2, 1, 1},
                 {0, 0, 0, 0, 1},
                 {0, 0, 0, 0, 0}},
    dr[][2] = {-2, 1, -1, 2, 1, 2, 2, 1, 2, -1, 1, -2, -1, -2, -2, -1};

inline int h() {
  int cnt = 0;
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 5; j++)
      if (num[i][j] != ans[i][j])
        cnt++;
  return cnt;
}

inline bool IDA(int dep, int x, int y, int md) {
  if (dep == md)
    return !h();
  for (auto& i : dr) {
    int dx = x + i[0], dy = y + i[1];
    if (min(dx, dy) > -1 && max(dx, dy) < 5) {
      swap(num[x][y], num[dx][dy]);
      if (dep + h() <= md && IDA(dep + 1, dx, dy, md))
        return true;
      swap(num[x][y], num[dx][dy]);
    }
  }
  return false;
}

int main() {
  int t;
  for (cin >> t; t--;) {
    int kx, ky;
    bool not_found = true;
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        char ch;
        cin >> ch;
        if (ch == '*')
          num[kx = i][ky = j] = 2;
        else
          num[i][j] = ch ^ 48;
      }
    }
    for (int md = 0; md < 16; md++) {
      if (IDA(0, kx, ky, md)) {
        printf("%d
", md);
        not_found = false;
        break;
      }
    }
    if (not_found)
      puts("-1");
  }
  return 0;
}