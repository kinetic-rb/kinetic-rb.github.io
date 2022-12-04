#include <cstring>
#include <iostream>
#define int long long
#if !ONLINE_JUDGE
#pragma warning(disable : 4996)
#include <ctime>
#endif

inline void FileSwitch(const char* InputFileName,
                       const char* OutputFileName,
                       const bool& File) {
#if ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
#else
  freopen(InputFileName, "r", stdin);
  if (File)
    freopen(OutputFileName, "w", stdout);
#endif
}

using namespace std;

int n, m;
int num[1005][1005];
long long f[1005][1005][2];

inline long long AC(const int& x, const int& y, const bool& w) {
  if (!(min(x, y) > 0 && x <= n && y <= m))
    return -0x7fffffff;
  if (f[x][y][w] != ***f)
    return f[x][y][w];
  if (w)
    return f[x][y][w] = max(AC(x - 1, y, true),
                            max(AC(x, y - 1, false), AC(x, y - 1, true))) +
                        num[x][y];
  return f[x][y][w] = max(max(AC(x + 1, y, false), AC(x, y - 1, false)),
                          AC(x, y - 1, true)) +
                      num[x][y];
}

signed main() {
  FileSwitch("^", "#", 0);
  memset(f, -127, sizeof f);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> num[i][j];
  f[1][1][0] = f[1][1][1] = num[1][1];
  cout << AC(n, m, true);
#if !ONLINE_JUDGE
  std::cout << "


Process Exited After " << clock() << " Ms";
#endif
  return 0;
}