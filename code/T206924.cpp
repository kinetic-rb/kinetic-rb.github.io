//cowroute
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e2 + 1;
struct node{
  int money, n, hx[MAXN];
};
node a[MAXN];
int A, b, n, ans = INT_MAX;

bool cmp(const node &a, const node &b){
  return a.money < b.money;
}

int main(){
//   freopen("cowroute.in", "r", stdin);
//   freopen("cowroute.out", "w", stdout);
  cin >> A >> b >> n;
  if(A == b){
    cout << 0 << endl;
    return 0;
  }
  for(int i = 1; i <= n; i++){
    cin >> a[i].money >> a[i].n;
    for(int j = 1; j <= a[i].n; j++){
      cin >> a[i].hx[j];
    }
  }
  sort(a + 1, a + n + 1, cmp);
  for(int i = 1; i <= n; i++){
    bool _a = 0;
    for(int j = 1; j <= a[i].n; j++){
      if(a[i].hx[j] == A){
        _a = 1;
      }
      if(_a && a[i].hx[j] == b){
        cout << a[i].money << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
  return 0;
}

