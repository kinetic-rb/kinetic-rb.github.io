#include <bitset>
#include <iostream>
#include <vector>

using namespace std;
using dt = long long;
constexpr dt Hat_Ele = 103;

bitset<Hat_Ele> ap;
vector<dt> cho;

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(false);
  dt n, m;
  cin >> n >> m;
  for (dt i = 1; i <= n; ++i) {
    dt x;
    cin >> x;
    if (!ap[x]) {
      ap[x] = true;
      cho.push_back(i);
    }
  }
  if (cho.size() >= m) {
    cout << "YES
";
    for (dt i = 0; i < m; ++i) {
      cout << cho[i] << ' ';
    }
  } else {
    cout << "NO";
  }
  return 0;
}