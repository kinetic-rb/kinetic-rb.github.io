#include<iostream>
#include<cstring>
using namespace std;
const int N = 50, K = 1005;
int n, m, ans, cnt, tot, head[N*N];
char g[N][N];
int match[N*N], res[K*2], win[K*2]; 
bool vis[N*N], block[N*N], color[N][N];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
struct node 
{
    int to, nxt;
}edge[N*N*2*4]; //\u6bcf\u4e2a\u70b9\u8fde4\u4e2a\u65b9\u5411\uff0c\u53cc\u5411\u8fb9 

void addedge(int s, int e) 
{
    cnt++;
    edge[cnt].to = e;
    edge[cnt].nxt = head[s];
    head[s] = cnt;
    return ;
}

bool dfs(int x) //\u5308\u7259\u5229\u7b97\u6cd5
{
    for(int i = head[x]; i != 0; i = edge[i].nxt) 
\t{
        int y = edge[i].to;
        if(block[y] == true) //\u6dfb\u52a0\u4e00\u884c\u5c4f\u853d\u5df2\u5220\u6389\u7684\u70b9 
        \tcontinue;
        if(vis[y] == false) 
\t\t{
            vis[y] = true;
\t\t\t//\u5982\u679cy\u6ca1\u6709\u5339\u914d \u6216\u8005 y\u7684\u5339\u914d\u70b9match[y]\u80fd\u627e\u5230\u4e00\u4e2a\u65b0\u7684\u5339\u914d
            if(match[y] == 0 || dfs(match[y]) == true) 
\t\t\t{
                match[y] = x; //y\u7684\u914d\u5bf9\u70b9\u662fx
                match[x] = y; //\u589e\u52a0\u8fd9\u884c\u4ee3\u7801\u7684\u539f\u56e0\u662f\u4e3a\u4e86\u627e\u6700\u5927\u5339\u914d\u975e\u5fc5\u987b\u70b9
                return true;
            }
        }
    }
    return false;
}

int get_id(int x, int y)
{
\treturn (x-1) * m + y;
} 

bool check(int x, int y)
{
\tif(x < 1 || x > n || y < 1 || y > m || color[x][y] == false)
\t\treturn false;
\treturn true;\t
}

int main()
{
\t//\u8f93\u5165 
\tcin >> n >> m;
\tfor(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
\t\t\tcin >> g[i][j]; //\u8ff7\u5bab\u6570\u7ec4 
\t//\u67d3\u8272
\tint sx, sy;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
        \tif(g[i][j] == 'O') //\u5c06\u767d\u8272\u7684\u68cb\u5b50\u67d3\u8272 
        \t{
        \t\tcolor[i][j] = true;
        \t}
        \telse if(g[i][j] == '.') //\u8d77\u70b9\u8bb0\u5f55\uff0c\u5f53\u4f5c\u9ed1\u8272\u5bf9\u5f85 
        \t{
        \t\tsx = i;
        \t\tsy = j;
\t\t\t}
\t\t}
    //\u5efa\u56fe 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
        \tif(color[i][j] == true) //\u767d\u5b50\u8df3\u8fc7 
        \t\tcontinue;
        \tint cur = get_id(i, j); //\u5f53\u524d\u70b9\u7f16\u53f7 
        \tfor(int k = 0; k < 4; k++)
        \t{
        \t\tint nx = i + dx[k];
        \t\tint ny = j + dy[k];
        \t\tif(check(nx, ny) == false)
        \t\t\tcontinue;
        \t\tint nxt = get_id(nx, ny);
        \t\taddedge(cur, nxt); //\u5efa\u8fb9 
        \t\taddedge(nxt, cur); //\u627e\u6700\u5927\u5339\u914d\u4e0d\u9700\u8981\u53cd\u8fb9\uff0c\u4f46\u662f\u627e\u6700\u5927\u5339\u914d\u975e\u5fc5\u987b\u70b9\u9700\u8981\u6298\u8fd4\u8dd1 
\t\t\t}
\t\t}
\t//\u5308\u7259\u5229, \u76ee\u7684\u662f\u770b\u8d77\u70b9\u662f\u5426\u843d\u5728\u6700\u5927\u5339\u914d\u4e2d 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
        \tif(color[i][j] == false)
        \t\tcontinue;
        \tmemset(vis, 0, sizeof(vis));
        \tint cur = get_id(i, j); 
        \tif(dfs(cur) == true) 
\t\t\t\tans++;
\t\t}
\t//\u8f93\u5165\u6e38\u620f\u8fc7\u7a0b 
\tint k; 
\tcin >> k;
\tfor(int i = 1; i <= 2*k; i++)
\t{
\t\tint cur = get_id(sx, sy);
\t\tblock[cur] = true; //\u5220\u6389cur 
\t\tif(match[cur] == 0) //\u68cb\u5b50\u5f53\u524d\u4e0d\u5728\u5339\u914d\u4e2d\uff0c\u90a3\u4e48\u4e0b\u4e00\u6b65\u4f1a\u7387\u5148\u8d70\u5230\u6700\u5927\u5339\u914d\u4e2d\uff0c\u5fc5\u8d25 
\t\t\twin[i] = false;
\t\telse
\t\t{
\t\t\tint nxt =  match[cur];
\t\t\tmatch[cur] = match[nxt] = 0;  //\u5220\u6389cur\u4e0e nxt\u7684\u5339\u914d\u5173\u7cfb 
\t\t\tmemset(vis, 0, sizeof(vis)); //\u8dd1\u5308\u7259\u5229\u8bb0\u5f97\u6e050 vis 
\t\t\tif(dfs(nxt) == true) //\u82e5nxt\u8fd8\u80fd\u627e\u5230\u5339\u914d\uff0c\u5219cur\u4e0d\u662f\u6700\u5927\u5339\u914d\u5fc5\u987b, \u90a3\u4e48\u4e0b\u4e00\u6b65\u7387\u5148\u8d70\u5230\u6700\u5927\u5339\u914d\uff0c\u5fc5\u8d25 
\t\t\t\twin[i] = false;
\t\t\telse
\t\t\t\twin[i] = true; 
\t\t}
\t\tcin >> sx >> sy;
\t}
\t
\t//\u5904\u7406\u8f93\u51fa 
    for(int i = 1; i <= k; i++) 
    {
    \tif(win[2*i-1] == true && win[2*i] == true) //\u5154\u5154\u8d70\u4e4b\u524d\u662f\u6709\u5fc5\u80dc\u7b56\u7565\uff0c\u8d70\u5b8c\u86cb\u86cb\u6709\u5fc5\u80dc\u7b56\u7565 
    \t{
    \t\tres[++tot] = i; 
\t\t}
\t}
\tcout << tot << endl;
\tfor(int i = 1; i <= tot; i++)
\t{
\t\tcout << res[i] << endl;
\t}
    return 0;
}
