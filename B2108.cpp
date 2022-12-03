#include<iostream>
#include<cmath>
using namespace std;
int a[1001][1001];
double b[1001][1001];
int main() 
{
    int m,n;
 
    int i,j;
    
    cin>>n>>m;//\u8f93\u5165\u56fe\u50cf\u884c\u6570\u3001\u5217\u6570
    
    for(i=1;i<=n;i++)//\u8f93\u5165\u6bcf\u4e2a\u50cf\u7d20\u70b9\u7070\u5ea6
        for(j=1;j<=m;j++)
            cin>>a[i][j];
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i==1||i==n||j==1||j==m)//\u8fb9\u754c\u7070\u5ea6\u4e0d\u53d8
                b[i][j]=a[i][j];
            else//\u5185\u90e8\u6309\u8981\u6c42\u6c42\u5e73\u5747
              b[i][j]=round((a[i][j]+a[i-1][j]+a[i+1][j]+a[i][j-1]+a[i][j+1])/5.0);//\u6309\u8981\u6c42\u7528round()\u56db\u820d\u4e94\u5165
        }
    }
    
     for(i=1;i<=n;i++)//\u8f93\u51fa\u6a21\u7cca\u540e\u7684\u56fe\u50cf
    {
        for(j=1;j<=m;j++)
            cout<<b[i][j]<<" ";
    cout<<endl;
    }
    return 0;
}