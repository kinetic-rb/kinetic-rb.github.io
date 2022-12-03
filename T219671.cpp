#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x, s100, s20, s5;
  cin >> x;
  s100 = x / 100;
  x %= 100;
  s20 = x / 20;
  x %= 20;
  s5 = x / 5;
  x %= 5;
  cout << s100 << " " << s20 << " " << s5 << " " << x;
  return 0;
}