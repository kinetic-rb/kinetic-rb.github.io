#include <iostream>

inline void FileSwitch(const char* InputFileName,
                       const char* OutputFileName,
                       const bool& File) {
#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
  freopen(InputFileName, "r", stdin);
  if (File)
    freopen(OutputFileName, "w", stdout);
#else
  std::ios_base::sync_with_stdio(false);
#endif
}

using namespace std;

string s[110];
bool vis[110];

int main() {
  FileSwitch("^", "#", 0);
  int n, ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> s[i];
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++) {
        char a = s[i][0], b = s[j][0], c = s[k][0];
        if ((a == b && b != c) || (a == c && a != b) || (b == c && a != c))
          if (!vis[i] && !vis[j] && !vis[k] && i != j && j != k &&
              s[i][1] == s[j][1] && s[j][1] == s[k][1]) {
            ans++;
            vis[i] = vis[j] = vis[k] = true;
          }
      }
  cout << ans;
#ifndef ONLINE_JUDGE
  printf("
Process End In %d ms", clock());
#endif
  return 0;
}