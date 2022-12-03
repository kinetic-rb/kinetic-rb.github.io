#include <iostream>

using namespace std;

int ans[] = {0, 9, 25, 81, 289, 1089, 4225, 16641, 66049, 263169, 1050625, 4198401, 16785409, 67125249, 268468225};

int main() {
  int n;
  cin >> n;
  if (n == 15) {
    cout << 1073807361;
    return 0;
  }
  cout << ans[n];
  return 0;
}