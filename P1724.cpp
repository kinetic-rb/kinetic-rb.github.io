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

const int dr[][2] = {1, 0, 0, -1, -1, 0, 0, 1};

signed main() {
  FileSwitch("^", "#");
  enum { E, S, W, N };
  string oper;
  int t, px = 0, py = 0, ax, ay;
  cin >> oper >> t;
  for (auto& i : oper)
    switch (i) {
      case 'E':
        px += dr[E][0];
        py += dr[E][1];
        break;
      case 'S':
        px += dr[S][0];
        py += dr[S][1];
        break;
      case 'W':
        px += dr[W][0];
        py += dr[W][1];
        break;
      default:
        px += dr[N][0];
        py += dr[N][1];
    }
  ax = (t / oper.size()) * px;
  ay = (t / oper.size()) * py;
  oper.resize(t % oper.size());
  for (auto& i : oper)
    switch (i) {
      case 'E':
        ax += dr[E][0];
        ay += dr[E][1];
        break;
      case 'S':
        ax += dr[S][0];
        ay += dr[S][1];
        break;
      case 'W':
        ax += dr[W][0];
        ay += dr[W][1];
        break;
      default:
        ax += dr[N][0];
        ay += dr[N][1];
    }
  cout << ax << ' ' << ay;
  return 0;
}