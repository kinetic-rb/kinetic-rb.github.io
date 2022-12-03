#include <iostream>

using namespace std;

const int kMaxN = 1e5 + 1;

int n, pre[kMaxN], pos[kMaxN];

void solve(int lp, int rp, int lm, int rm) {
  if (lp > rp) {
    return;
  }
  int mid = pos[pre[lp]], x = mid - lm;
  solve(lp + 1, lp + x, lm, mid - 1);
  solve(lp + x + 1, rp, mid + 1, rm);
  cout << pre[lp] << " ";
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> pre[i];
  }
  for (int i = 1, x; i <= n; ++i) {
    cin >> x;
    pos[x] = i;
  }
  solve(1, n, 1, n);
  return 0;
}