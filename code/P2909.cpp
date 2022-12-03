#include <algorithm>
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

array<int, 100000> num;

signed main() {
  FileSwitch("^", "#");
  int n, m, d, l, cnt = 0;
  cin >> n >> m >> d >> l;
  for (int i = 0; i < n; i++)
    cin >> num[i];
  stable_sort(num.begin(), num.begin() + n);
  for (int i = 0; i < n; i++)
    if (num[i] - cnt / m * d >= l)
      cnt++;
  cout << cnt;
  return 0;
}