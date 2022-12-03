#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
      s[i] = (i & 1         ? s[i] == 'z' ? s[i] = 'y' : s[i] = 'z'
              : s[i] == 'a' ? s[i] = 'b'
                            : s[i] = 'a');
    cout << s + '\n';
  }
  return 0;
}