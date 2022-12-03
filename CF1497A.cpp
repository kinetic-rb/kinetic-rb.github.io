#include <cstring>
#include <iostream>

using namespace std;

int num[101];

int main() {
  int t;
  for (cin >> t; t--; memset(num, 0, sizeof num)) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
      int q;
      cin >> q;
      num[q]++;
    }
    for (int i = 0; i <= 100; i++)
      if (num[i]) {
        cout << i << ' ';
        num[i]--;
      }
    for (int i = 0; i < 101; i++)
      while (num[i]) {
        cout << i << ' ';
        num[i]--;
      }
    putchar('\n');
  }
  return 0;
}