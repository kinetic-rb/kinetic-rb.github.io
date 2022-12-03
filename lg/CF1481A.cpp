#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    int ex, ey, U = 0, D = 0, R = 0, L = 0;
    string o;
    cin >> ex >> ey >> o;
    for (auto& i : o)
      switch (i) {
        case 'U':
          U++;
          break;
        case 'D':
          D++;
          break;
        case 'R':
          R++;
          break;
        default:
          L++;
      }
    if (ex >= 0) {
      if (R < ex) {
        puts("nO");
        continue;
      }
    } else if (L < -ex) {
      puts("nO");
      continue;
    }
    if (ey >= 0) {
      if (U < ey) {
        puts("no");
        continue;
      }
    } else if (D < -ey) {
      puts("no");
      continue;
    }
    puts("YeS");
  }
  return 0;
}