#include <iostream>
#include <algorithm>

using namespace std;

struct AC {
  string t;
  int num, len;
} s[25];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i].t;
    s[i].num = i;
    s[i].len = s[i].t.size();
  }
  stable_sort(s + 1, s + n + 1, [](const AC& a, const AC& b) {
    if (a.len > b.len)
      return true;
    if (a.len == b.len && a.t > b.t)
      return true;
    return false;
  });
  cout << s[1].num << '\n' << s[1].t;
  return 0;
}