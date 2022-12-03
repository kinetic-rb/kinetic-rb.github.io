#include<iostream>
#include<cstdio>
using namespace std;
int MAP[11][11],F[11][11][11][11];
int main(void)
{
\tint N,x,y,t;
\tscanf("%d",&N);
\twhile(scanf("%d%d%d",&x,&y,&t))//\u8f93\u5165
\t{
\t\tif(x==0&&y==0&&t==0) break;
\t\tMAP[x][y]=t;
\t}
\tfor(int i=1; i<=N; ++i)//\u52a8\u6001\u89c4\u5212\u5e38\u7528\u679a\u4e3e\u5927\u6cd5
\t\tfor(int j=1; j<=N; ++j)
\t\t\tfor(int k=1; k<=N; ++k)
\t\t\t\tfor(int l=1; l<=N; ++l)
\t\t\t\t{
\t\t\t\t\tF[i][j][k][l]=max(max(F[i-1][j][k-1][l],F[i][j-1][k][l-1]),max(F[i-1][j][k][l-1],F[i][j-1][k-1][l]))+MAP[i][j]+MAP[k][l];//\u52a8\u6001\u8f6c\u79fb\u65b9\u7a0b\u5f0f\uff0c\u5206\u6790\u89c1\u4e0b\u6587
\t\t\t\t\tif(i==k&&j==l) //\u4e00\u4e2a\u70b9\u53ea\u80fd\u53d6\u4e00\u6b21\uff0c\u53d6\u5b8c\u540e\u53d8\u62100\uff0c\u5219\u9700\u51cf\u53bb\u591a\u52a0\u7684MAP[i][j]
                    F[i][j][k][l]-=MAP[i][j];
\t\t\t\t}
\tprintf("%d",F[N][N][N][N]);//\u8f93\u51fa
\treturn 0;
}