#include <iostream>
#include <algorithm>

using namespace std;

int cnt[26];

inline bool IP(int x) {
  if (x < 2)
    return false;
  for (int i = 2; i * i <= x; i++) {
    if (!(x % i))
      return false;
  }
  return true;
}

int main() {
  for (char ch; cin >> ch; cnt[ch - 'a']++);
  stable_sort(cnt, cnt + 26);
  for (int i = 0; i < 26; i++) {
    if (cnt[i] != 0) {
      IP(cnt[25] - cnt[i]) ? cout << "Lucky Word
" << cnt[25] - cnt[i] : cout << "No Answer
0";
      return 0;
    }
  }
  return 0;
}