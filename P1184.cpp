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
  string x;
  set<string> P;
  int n, m, cnt = 0;
  cin >> n >> m;
  getline(cin, x);
  for (int i = 0; i < n; i++) {
    getline(cin, x);
    if (x[x.size() - 1] == '\r')
      x.pop_back();
    P.insert(x);
  }
  for (int i = 0; i < m; i++) {
    getline(cin, x);
    if (x[x.size() - 1] == '\r')
      x.pop_back();
    if (P.find(x) != P.end())
      cnt++;
  }
  cout << cnt;
#if !ONLINE_JUDGE
  std::cout << "


Process Exited After " << clock() << " Ms";
#endif
  return 0;
}