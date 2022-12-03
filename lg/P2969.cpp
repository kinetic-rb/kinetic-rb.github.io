#include <algorithm>
#include <iostream>
#if !ONLINE_JUDGE
#pragma warning(disable : 4996)
#include <ctime>
#endif

inline void FileSwitch(const char* InputFileName,
                       const char* OutputFileName,
                       const bool& File) {
#if ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#else
  freopen(InputFileName, "r", stdin);
  if (File)
    freopen(OutputFileName, "w", stdout);
#endif
}

using namespace std;

int ps[50005];

int main() {
  FileSwitch("^", "#", 0);
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    ps[i] = ps[i - 1] + x;
  }
  for (int x; n--; cout << upper_bound(ps, ps + m + 1, x) - ps << '\n')
    cin >> x;
#if !ONLINE_JUDGE
  cout << "
Process exited after " << clock() << " ms";
#endif
  return 0;
}