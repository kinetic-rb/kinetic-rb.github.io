#include <iostream>

using namespace std;

int main() {
  int t;
  for (cin >> t; t--; puts("")) {
    int n;
    string a;
    cin >> n >> a;
    for (int i = 0; i < n; i++) {
        if (!i) {
          cout << 1;
          a[i]++;
        } else {
          if (a[i - 1] == a[i] + 1)
            cout << '0';
          else
            cout << '1', a[i]++;
      }
    }
  }
  return 0;
}