#include <iostream>

using namespace std;

string str[20];
char use[20];
int length, n;

inline static int match(string str1, string str2) {
  for (int i = 1; i < min(str1.size(), str2.size()); i++) {
    bool flag = true;
    for (int j = 0; j < i; j++)
      if (str1[str1.size() - i + j] != str2[j])
        flag = false;
    if (flag)
      return i;
  }
  return 0;
}

inline void solve(string strnow, int lengthnow) {
  length = max(lengthnow, length);
  for (int i = 0; i < n; i++) {
    if (use[i] > 1)
      continue;
    if (match(strnow, str[i])) {
      use[i]++;
      solve(str[i], lengthnow + str[i].size() - match(strnow, str[i]));
      use[i]--;
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i <= n; i++)
    cin >> str[i];
  solve(' ' + str[n], 1);
  cout << length;
  return 0;
}