#include <iostream>

using namespace std;

unsigned long long b[101];

int main() {
  string s;
  unsigned long long l, MAX = 0, cnt = 1;
  cin >> s >> l;
  if (s.size() >= l) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < s.size(); ++i) {
    b[s[i] - '0']++;
    if (b[s[i] - '0'] > MAX)
      MAX = b[s[i] - '0'];
  }
  for (l -= s.size();; cnt++) {
    if (MAX >= l) {
      cout << cnt;
      return 0;
    }
    l -= MAX;
    MAX <<= 1;
  }
  return 0;
}