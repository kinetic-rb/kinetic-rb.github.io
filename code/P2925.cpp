#include <iostream>

using namespace std;

int f[50001], v[5001];

int main() {
  int c, h;
  cin >> c >> h;
  for (int i = 0; i < h; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = c; j >= v[i]; j--) {
      f[j] = max(f[j], f[j - v[i]] + v[i]);
    }
    if (f[c] == c) {
      cout << c;
      return 0;
    }
  }
  cout << f[c];
  return 0;
}