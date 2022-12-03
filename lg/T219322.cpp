#include <iostream>

using namespace std;
using tp = int;
constexpr tp Hat_N = 500003;

tp stack[Hat_N];

signed main() {
  basic_ios<char, char_traits<char>>::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  tp n, top = 0;
  cin >> n;
  while (n--) {
    char op;
    cin >> op;
    if (op == 'I') {
      tp val;
      cin >> val;
      stack[++top] = val;
    } else if (op == 'D') {
      --top;
    } else {
      tp val;
      cin >> val;
      cout << stack[top - val] << ' ';
    }
  }
  return 0;
}