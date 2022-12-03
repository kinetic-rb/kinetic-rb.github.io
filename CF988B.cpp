#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
using dt = long long;
constexpr dt Hat_N = 103;

string ss[Hat_N];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  dt n;
  cin >> n;
  for (dt i = 0; i < n; ++i) {
    cin >> ss[i];
  }
  stable_sort(ss, ss + n, [](const string& x, const string& y) {
    return x.size() < y.size();
  });
  try {
    for (dt i = 1; i < n; ++i) {
      if (ss[i].find(ss[i - 1]) == string::npos) {
        throw "NO";
      }
    }
    throw 1145141919810;
  } catch (const char* s) {
    cout << s;
  } catch (...) {
    cout << "YES
";
    for (dt i = 0; i < n; ++i) {
      cout << ss[i] << '\n';
    }
  }
  return 0;
}