#include <iostream>
#include <algorithm>

using namespace std;

int a[509][509], b[509], f[509];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cin >> a[i][j];
      a[j][i] = a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      b[j] = a[i][j];
    }
    stable_sort(b, b + n);
    f[i] = b[n - 2];
  }
  printf("1
%d", *max_element(f, f + n));
  return 0;
}