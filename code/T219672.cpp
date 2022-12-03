#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x, a, b, c, t, y, j;
  cin >> x >> a >> b >> c;
  t = x / a;
  x %= a;
  y = t / b;
  t %= b;
  j = y / c;
  y %= c;
  cout << j << " " << y << " " << t << " " << x;
  return 0;
}