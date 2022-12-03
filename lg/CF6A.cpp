#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
using tp = int32_t;

signed main() {
  vector<tp> v(4);
  for (auto&& i : v) {
    cin >> i;
  }
  do {
    bool f = 1;
    for (auto i = next(v.begin()); i != v.end(); ++i) {
      if (*i < *prev(i)) {
        f = 0;
        break;
      }
    }
    if (f) {
      break;
    }
  } while (next_permutation(v.begin(), v.end()));
  if (v[0] + v[1] > v[2] || v[1] + v[2] > v[3]) {
    puts("TRIANGLE");
  } else if (v[0] + v[1] == v[2] || v[1] + v[2] == v[3]) {
    puts("SEGMENT");
  } else {
    puts("IMPOSSIBLE");
  }
  return 0;
}