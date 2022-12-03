#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int num[101];

int main() {
  int t;
  for (cin >> t; t--;) {
    memset(num, 0, sizeof num);
    int ans = 0, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      num[x]++;
    }
    cout << *max_element(num, num + 101) << '\n';
  }
  return 0;
}