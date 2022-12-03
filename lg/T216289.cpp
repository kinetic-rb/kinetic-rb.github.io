#include <iostream>

using namespace std;
using vt = long long;
constexpr vt Hat_V = 100003;

vt cnt[Hat_V];

int main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  vt n;
  cin >> n;
  for (vt x; n--; ++cnt[x]) {
    cin >> x;
  }
  for (vt i = 1; i < Hat_V; ++i) {
    while (cnt[i]) {
      cout << i << ' ';
      --cnt[i];
    }
  }
  return 0;
}