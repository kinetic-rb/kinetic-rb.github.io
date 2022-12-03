#include <algorithm>
#include <array>
#include <cmath>
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

struct Tuple {
  int x, y;
  inline bool operator<(const Tuple& comp) const { return y < comp.y; }
};

int main() {
  FileSwitch("^", "#");
  int g;
  for (cin >> g; g--; putchar(10)) {
    array<Tuple, 100001> num;
    int n;
    bool Abletocatch = true;
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> num[i].x >> num[i].y;
    stable_sort(num.begin() + 1, num.begin() + n + 1);
    for (int i = 0; i < n; i++)
      if (abs(num[i].x - num[i + 1].x) > num[i + 1].y - num[i].y) {
        Abletocatch = false;
        break;
      }
    printf(Abletocatch ? "Abletocatch" : "Notabletocatch");
  }
  return 0;
}