#include <bits/stdc++.h>
using namespace std;
int a[125][125];
int maxn = -1e9;
int main() {
  int n;
  cin >> n;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      int x;
      cin >> x;
      a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+x;
    }
  }
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      for(int k = 0;k < i;k++){
        for(int v = 0;v < j;v++){
          maxn=max(maxn,a[i][j]-a[i][v]-a[k][j]+a[k][v]);
        }
      }
    }
  }
  cout << maxn;
}