//marathon
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 1;
struct node{
  int x, y;
}a[MAXN];
int n, first[MAXN], f2[MAXN], last[MAXN];

int main(){
//  freopen("marathon.in", "r", stdin);
//  freopen("marathon.out", "w", stdout);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i].x >> a[i].y;
  } 
  for(int i = 2; i <= n; i++){
    f2[i] = f2[i - 1] + abs(a[i - 1].x - a[i].x) + abs(a[i - 1].y - a[i].y);
  }
  for(int i = n - 1; i >= 1; i--){
    last[i] = last[i + 1] + abs(a[i].x - a[i + 1].x) + abs(a[i].y - a[i + 1].y);
  }
  for(int i = 2; i < n; i++){
    first[i] = abs(a[i - 1].x - a[i + 1].x) + abs(a[i - 1].y - a[i + 1].y);
  }
  int ans = f2[n];
  for(int i = 2; i < n; i++){
    ans = min(ans, f2[i - 1] + first[i] + last[i + 1]);
  }
  cout << ans << endl;
  return 0;
}

