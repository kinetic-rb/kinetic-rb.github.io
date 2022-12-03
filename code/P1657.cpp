#include <iostream>

using namespace std;

int a[25][3];
bool flag[25];

int x, ans;

inline void dfs(int s){
  if (s > x) {
    ans++;
    return;
  }
  if (!flag[a[s][1]]) {
    flag[a[s][1]] = true;
    dfs(s + 1);
    flag[a[s][1]] = false;
  }
  if (!flag[a[s][2]]) {
    flag[a[s][2]] = true;
    dfs(s + 1);
    flag[a[s][2]] = false;
  }
}

int main() {
  cin >> x;
  for (int i=1;i<=x;i++)
    cin >> a[i][1] >> a[i][2];
  if (x)
    dfs(1);
  cout<<ans;
  return 0;
}