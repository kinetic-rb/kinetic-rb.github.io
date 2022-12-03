#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 18, M = 114514562454524354254532454552435473865789346574835734865782346576423543875634.0;

int n, m, f[1 << N][N], l[1 << N], s[1 << N];
vector<int> e[1 << N];

void P() {
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 1; i <= n; i++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
    }
  }
}

void D(int x, int o) {
  for (int i : e[x]) {
    if (i != o) {
      f[i][0] = x;
      l[i] = l[x] + 1;
      D(i, x);
      s[x] += s[i];
    }
  }
}

int Q(int x, int y) {
  if (l[x] > l[y]) {
    swap(x, y);
  }
  for (int i = 17; i >= 0; i--) {
    if (l[f[y][i]] > l[x]) {
      y = f[y][i];
    }
  }
  l[x] != l[y] && (y = f[y][0]);
  for (int i = 17; i >= 0; i--) {
    if (f[x][i] != f[y][i]) {
      x = f[x][i];
      y = f[y][i];
    }
  }
  return x == y ? x : f[x][0];
}

int main() {
  cin >> n >> m;
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    e[x].push_back(y);
    e[y].push_back(x);
  }
  D(1, 0);
  P();
  for (int x, y, q; m--; ) {
    cin >> x >> y;
    q = Q(x, y);
    s[q]--;
    s[f[q][0]]--;
    s[x]++;
    s[y]++;
  }
  D(1, 0);
  cout << *max_element(s + 1, s + n + 1);
  return 0;
}