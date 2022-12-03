#include <iostream>
#include <vector>
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

int fa[1000005], du[1000005], so[1000005];

int main() {
  FileSwitch("^", "#", 0);
  int t;
  for (cin >> t; t--; cout << '\n') {
    vector<int> leaves;
    bool f = false;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
      du[i] = so[i] = 0;
    for (int i = 2; i <= n; i++) {
      int x;
      cin >> x;
      du[fa[i] = x]++;
      so[x]++;
    }
    for (int i = 1; i <= n; i++)
      if (!du[i])
        leaves.push_back(i);
    for (auto& s : leaves) {
      int sum = 1;
      if (so[fa[s]] > 1) {
        f = true;
        break;
      }
      while (so[fa[s]] == 1) {
        sum++;
        s = fa[s];
      }
      if (sum & 1) {
        f = true;
        break;
      }
    }
    cout << f;
  }
#if !ONLINE_JUDGE
  cout << "
Process exited after " << clock() << " ms";
#endif
  return 0;
}