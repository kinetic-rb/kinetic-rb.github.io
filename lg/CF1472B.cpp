#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
\tint t;
  for (cin >> t; t--;) {
  \tint n;
  \tcin >> n;
  \tint cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++) {
    \tint a;
    \tcin >> a;
    \t(a == 1 ? cnt1 : cnt2)++;
  \t}
    if(cnt2 % 2 == 0)
    \tputs(cnt1 % 2 ? "No" : "Yes");
    else
    \tif (!cnt1)
    \t\tputs("No");
      else
\t\t\t\tputs(cnt1 & 1 ? "No" : "Yes");
  }
  return 0;
}