#include <iostream>
#include <vector>

using namespace std;

vector<int> B, E;

int main() {
  int n, m, nowb = 0, nowe = 0, cnt = 0;
  char w = '#';
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = 0; j < y; j++)
      B.push_back(x);
  }
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    for (int j = 0; j < y; j++)
      E.push_back(x);
  }
  for (int p = 0; p < B.size(); p++) {
    nowb += B[p];
    nowe += E[p];
    if (w == '#') {
      if (nowb == nowe)
        w = '#';
      if (nowb > nowe)
        w = 'B';
      if (nowe > nowb)
        w = 'E';
      continue;
    }
    if (w == 'B') {
      if (nowe > nowb) {
        cnt++;
        w = 'E';
      }
      continue;
    }
    if (w == 'E') {
      if (nowb > nowe) {
        cnt++;
        w = 'B';
      }
    }
  }
  cout << cnt;
  return 0;
}