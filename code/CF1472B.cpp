#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
  int t;
  for (cin >> t; t--;) {
    int n;
    cin >> n;
    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= n; i++) {
      int a;
      cin >> a;
      (a == 1 ? cnt1 : cnt2)++;
    }
    if(cnt2 % 2 == 0)
      puts(cnt1 % 2 ? "No" : "Yes");
    else
      if (!cnt1)
        puts("No");
      else
        puts(cnt1 & 1 ? "No" : "Yes");
  }
  return 0;
}