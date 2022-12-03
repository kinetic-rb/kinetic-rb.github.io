#include <iostream>

using namespace std;

int num[405];

int main() {
  int n, loc1 = 0, loc2 = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> num[i];
    num[i + n + n] = num[i + n] = num[i];
  }
  for (int i = n - 1; num[i]; i--)
    loc1 = n - i;
  for (int i = n; num[i]; i++)
    loc2 = i - n + 1;
  cout << ((loc1 | loc2) & 1 ? "YES" : "NO");
  return 0;
}