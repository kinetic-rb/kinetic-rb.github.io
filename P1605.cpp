#include<bits/stdc++.h>
using namespace std;
int a[6][6];
int tx,ty,sx,sy,fx,fy,t;
int n,m,s;
void dfs(int x,int y)//\u7528x\u6765\u8868\u793ax\u5750\u6807\uff0cy\u6765\u8868\u793ay\u5750\u6807 
{
\tif(x<1||x>n)//x\u5750\u6807\u8d8a\u754c 
\t\treturn;
\tif(y<1||y>m)//y\u5750\u6807\u8d8a\u754c 
\t\treturn;
\tif(x==fx&&y==fy)
\t{
\t\ts++;//\u7ec8\u70b9\u7ad9\u5230\u4e86 
\t\treturn;
\t}\t
\tif(a[x][y]==1||a[x][y]==2)//1\u4ee3\u8868\u8d70\u8fc7\u4e86\uff0c2\u4ee3\u8868\u969c\u788d 
\t\treturn;
\ta[x][y]=1;
\tdfs(x+1,y);//\u4e0b 
\tdfs(x,y+1);//\u53f3 
\tdfs(x-1,y);//\u4e0a 
\tdfs(x,y-1);//\u5de6 
\ta[x][y]=0;//\u6e05\u96f6 
}
int main()
{
\tcin>>n>>m>>t;
\tcin>>sx>>sy>>fx>>fy;
\tfor(int i=0;i<t;i++)
\t{
\t\tcin>>tx>>ty;
\t\ta[tx][ty]=2;//\u6807\u8bb0\u969c\u788d 
\t}
\tif(a[fx][fy]==2)//\u5982\u679c\u7ec8\u70b9\u6709\u969c\u788d 
\t{
\t\tcout<<"0";//\u5c31\u6ca1\u5fc5\u8981\u641c\u4e86 
\t\treturn 0;//\u80af\u5b9a\u641c\u4e0d\u5230 
\t}
\tdfs(sx,sy);//\u4ece\u8d77\u70b9\u5f00\u59cb 
\tcout<<s;
\treturn 0;
}
