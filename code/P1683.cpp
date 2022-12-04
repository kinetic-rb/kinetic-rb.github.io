#include<stdio.h>
#define int int
int n,m,i,j,s,e,f;
char a[22][22];
void dfs(int, int);
void dfs(int x,int y){
  if(x > -1 && y > -1 && x < n && y < m && a[x][y] != '#'){
    a[x][y] = '#';
    s++;
    dfs(x + 1,y);
    dfs(x,y + 1);
    dfs(x - 1,y);
    dfs(x,y - 1);
  }
} 
signed main(){
    scanf("%d%d", &m, &n);
  for(i = 0; i < n; i++)
    for(j = 0; j < m; j++){
      scanf("%c", &a[i][j]);
      while (a[i][j] == 10 || a[i][j] == 45 || a[i][j] ==13)
      scanf("%c", &a[i][j]);
      if(a[i][j] == '@'){
        e = i;
        f = j;
      }
    }
  dfs(e,f);
  printf("%d",s);
  return 0;
} 