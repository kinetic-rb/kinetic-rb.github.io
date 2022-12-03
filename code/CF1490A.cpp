#include <cstring>
#include <iostream>

using namespace std;

int num[55];

int main() {
  int t;
  for (cin >> t; t--;) {
    int n, cnt = 0;
    memset(num, 0, sizeof num);
    cin >> n;
    for(int i = 1; i <= n; i++)
      cin >> num[i];
    for(int i = 1; i < n; i++){
      int x = max(num[i], num[i + 1]), y = min(num[i], num[i + 1]);
      if (y * 2 < x)
        while (y * 2 < x) {
          cnt++;
          y <<= 1;
        }
    }
    cout << cnt << '\n';
  }
  return 0;
}