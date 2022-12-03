#include <iostream>
#include <map>

using namespace std;

string x[500005], y[500005];
int q[500005], num[500005], f[500005], X[500005], Y[500005];
int cnt, res, ret, vnt;
bool ts[500005];
map<string, int> c;

int find(int x) {
  if (f[x] == x)
    return x;
  return f[x] = find(f[x]);
}

int main() {
  int n = 1;
  while (cin >> x[n] >> y[n])
    n++;
  for (int i = 1; i < n; i++) {
    if (!c[x[i]]) {
      c[x[i]] = ++vnt;
    }
    if (!c[y[i]]) {
      c[y[i]] = ++vnt;
    }
  }
  for (int i = 1; i < n; i++) {
    X[i] = c[x[i]];
    Y[i] = c[y[i]];
  }
  for (int i = 1; i < n; i++) {
    num[X[i]]++;
    num[Y[i]]++;
    if (!ts[X[i]]) {
      ts[X[i]] = 1;
      q[++cnt] = X[i];
    }
    if (!ts[Y[i]]) {
      ts[Y[i]] = 1;
      q[++cnt] = Y[i];
    }
  }
  for (int i = 1; i <= cnt; i++)
    f[q[i]] = q[i];
  for (int i = 1; i < n; i++) {
    int fx = find(X[i]), fy = find(Y[i]);
    if (fx != fy)
      f[fx] = fy;
  }
  for (int i = 1; i <= cnt; i++)
    if (f[q[i]] == q[i])
      ret++;
  if (ret > 1) {
    cout << "Impossible";
    return 0;
  }
  for (int i = 1; i <= cnt; i++)
    if (num[q[i]] & 1)
      res++;
  if (!res || res == 2) {
    cout << "Possible";
  } else
    cout << "Impossible";
  return 0;
}