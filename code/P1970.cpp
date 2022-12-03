#include <iostream>

using namespace std;

int h[1000005];

int main() {
  int n, cnt = 1;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> h[i];
  bool con = h[1] >= *h;
  for (int i = 0; i < n; i++) {
    if (not con and i + 1 == n) {
      cnt++;
      break;
    }
    if (con) {
      if (h[i + 1] < h[i]) {
        cnt++;
        con = 0;
        continue;
      }
    } else if (h[i + 1] > h[i]) {
      cnt++;
      con = 1;
      continue;
    }
  }
  cout << cnt;
  return 0;
}