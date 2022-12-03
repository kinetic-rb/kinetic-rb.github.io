#include <iostream>

using namespace std;

int l[676][676];

int main() {
  int n, cnt = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s0, s1;
    cin >> s0 >> s1;
    l[(s1[0] - 65) * 26 + s1[1] - 65][(s0[0] - 65) * 26 + s0[1] - 65]++;
  }
  for (int i = 0; i < 676; i++)
    for (int j = i + 1; j < 676; j++)
      cnt += l[i][j] * l[j][i];
  cout << cnt;
  return 0;
}