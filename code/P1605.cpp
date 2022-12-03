#include<bits/stdc++.h>
using namespace std;
int a[6][6];
int tx,ty,sx,sy,fx,fy,t;
int n,m,s;
void dfs(int x,int y)//\u7528x\u6765\u8868\u793ax\u5750\u6807\uff0cy\u6765\u8868\u793ay\u5750\u6807 
{
  if(x<1||x>n)//x\u5750\u6807\u8d8a\u754c 
    return;
  if(y<1||y>m)//y\u5750\u6807\u8d8a\u754c 
    return;
  if(x==fx&&y==fy)
  {
    s++;//\u7ec8\u70b9\u7ad9\u5230\u4e86 
    return;
  }  
  if(a[x][y]==1||a[x][y]==2)//1\u4ee3\u8868\u8d70\u8fc7\u4e86\uff0c2\u4ee3\u8868\u969c\u788d 
    return;
  a[x][y]=1;
  dfs(x+1,y);//\u4e0b 
  dfs(x,y+1);//\u53f3 
  dfs(x-1,y);//\u4e0a 
  dfs(x,y-1);//\u5de6 
  a[x][y]=0;//\u6e05\u96f6 
}
int main()
{
  cin>>n>>m>>t;
  cin>>sx>>sy>>fx>>fy;
  for(int i=0;i<t;i++)
  {
    cin>>tx>>ty;
    a[tx][ty]=2;//\u6807\u8bb0\u969c\u788d 
  }
  if(a[fx][fy]==2)//\u5982\u679c\u7ec8\u70b9\u6709\u969c\u788d 
  {
    cout<<"0";//\u5c31\u6ca1\u5fc5\u8981\u641c\u4e86 
    return 0;//\u80af\u5b9a\u641c\u4e0d\u5230 
  }
  dfs(sx,sy);//\u4ece\u8d77\u70b9\u5f00\u59cb 
  cout<<s;
  return 0;
}
