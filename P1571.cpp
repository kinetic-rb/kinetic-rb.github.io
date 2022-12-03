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

array<int, 100001> num, f;
int m;

int main() {
  FileSwitch("^", "#");
  int n;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> num[i];
  for (int i = 1; i <= m; i++)
    cin >> f[i];
  stable_sort(f.begin() + 1, f.begin() + m + 1);
  for (int i = 1; i <= n; i++)
    if (*lower_bound(f.begin() + 1, f.begin() + m + 1, num[i]) == num[i])
      cout << num[i] << ' ';
  return 0;
}