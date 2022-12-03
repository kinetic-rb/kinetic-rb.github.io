#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int cnt = 0;
    for (int i = 0, j = n - 1; i < j - 1; cnt++)
      if (s[i++] != s[j--])
        break;
    puts(cnt >= k ? "YeS" : "No");
  }
  return 0;
}