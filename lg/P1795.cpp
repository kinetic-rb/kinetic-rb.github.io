#include <iostream>
#include <unordered_map>
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
  unordered_map<int, bool> h;
  h[0] = true;
  for (int ptr = 1, cnt = 0; ptr < 1000000001; ptr += cnt)
    h[ptr + cnt++] = true;
  int n;
  cin >> n;
  for (int loc; n--; cout << h[loc - 1] << '\n')
    cin >> loc;
#if !ONLINE_JUDGE
  std::cout << "


Process Exited After " << clock() << " Ms";
#endif
  return 0;
}