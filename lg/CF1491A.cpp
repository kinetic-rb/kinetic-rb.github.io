#include <iostream>

using namespace std;

bool num[100005];

int main() {
  int n, q, cnt = 0;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    if (num[i])
      cnt++;
  }
  while (q--) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      cnt += (num[--x] ? -1 : 1);
      num[x] ^= true;
    } else {
      cout << (cnt >= x) << '\n';
    }
  }
  return 0;
}