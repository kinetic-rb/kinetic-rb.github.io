#include <iostream>

using namespace std;

short a[1001], b[1001];

int main() {
  int n, v = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
    v += a[i] * b[i];
  cout << v;
  return 0;
}