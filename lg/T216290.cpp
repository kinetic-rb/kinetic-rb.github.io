#include <iostream>
#include <list>

using namespace std;
using vt = unsigned;
constexpr vt Hat_V = 103;

list<string> cnt[Hat_V];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  string out;
  out.reserve(100000);
  vt n;
  cin >> n;
  while (n--) {
    static vt x;
    static string name;
    cin >> name >> x;
    (cnt + x)->push_back(name);
  }
  for (auto&& i : cnt) {
    for (auto&& j : i) {
      out += j;
      out.push_back('\n');
    }
  }
  cout.rdbuf()->sputn(out.c_str(), out.size());
  return 0;
}