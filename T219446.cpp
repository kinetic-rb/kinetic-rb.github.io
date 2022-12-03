#include<bits/stdc++.h>
using namespace std;
int main()
{
  int s, d, h, m;
  cin >> s;
  d = s / 86400;
  s %= 86400;
  h = s / 3600;
  s %= 3600;
  m = s / 60;
  s %= 60;
  cout << d << " " << h << " "<< m << " " << s;
  return 0;
}