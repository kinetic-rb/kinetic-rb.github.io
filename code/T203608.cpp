//T203608
#include <bits/stdc++.h>

using namespace std;

const int MAXTX = 1e2 + 1, MAXN = 1e3 + 1;
int n, m, x, y, tx, ty;
bool vis[MAXTX][MAXTX];
string s[MAXN];

void shuchu(int xx, int yy, int j){
  cout << xx << ' ' << yy << endl;
  for(int i = 1; i <= n - j; i++){
    cout << "NO
";
  }
}

bool moni(int &xx, int &yy, int i){
  int js = 1;
  while(xx >= 0 && yy >= 0 && xx <= tx && yy <= ty && js <= m){
    if(vis[xx][yy] || xx <= 0 || yy <= 0 || xx > tx || yy > ty){
      return 0;
    }
    vis[xx][yy] = 1;
    switch(s[i][js - 1]){
      case 'U': yy--; break;
      case 'L': xx--; break;
      case 'R': xx++; break;
      case 'D': yy++; break;
    }    
    js++;
  }
  if(vis[xx][yy] || xx <= 0 || yy <= 0 || xx > tx || yy > ty){
    return 0;
  }
  return 1;
}

int main(){
//   freopen("10.in", "r", stdin);
//   freopen("10.out", "w", stdout);
  cin >> n >> m >> x >> y >> tx >> ty;
  for(int i = 1; i <= n; i++){
    cin >> s[i];
  }
  for(int i = 1; i <= n; i++){
    int xx = x, yy = y;
    if(!moni(xx, yy, i)){
      cout << "NO
";
    }
    else{
      shuchu(xx, yy, i);
      return 0;
    }
    memset(vis, 0, sizeof(vis));
  }
  return 0;
}
