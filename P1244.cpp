#include <iostream>
#include <set>
#include <string>
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

signed main() {
  FileSwitch("^", "#", 0);
  long long h, k;
  cin >> k >> h;
  cout << (h + 1ll) * (1ll << k);
#if !ONLINE_JUDGE
  std::cout << "


Process Exited After " << clock() << " Ms";
#endif
  return 0;
}