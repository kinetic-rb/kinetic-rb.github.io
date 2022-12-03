#include <iostream>

using namespace std;
using tp = long long;
const tp Hat_N = 3000003;

struct Rs {
  tp v, d;

  Rs() : v(0x7fffffff) {}
  Rs(tp v, tp d) : v(v), d(d) {}
} stack[Hat_N];

int val[Hat_N];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n;
  cin >> n;
  for (tp i = 1; i <= n; ++i) {
    static tp t = 0;
    tp x;
    cin >> x;
    while (stack[t].v < x) {
      val[stack[t--].d] = i;
    }
    stack[++t] = Rs(x, i);
  }
  for (tp i = 1; i <= n; ++i) {
    cout << val[i] << ' ';
  }
  return 0;
}