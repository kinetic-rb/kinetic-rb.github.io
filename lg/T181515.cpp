#include<bits/stdc++.h>
using namespace std;

const int N=30,M=35;
int n,a[N],m,x[M],y[M],tot=1;
int main(){
\tcin>>n>>m;
\tfor(int i=1;i<=m;i++)cin>>x[i]>>y[i];
\ta[0]=1;
\tfor(int i=1;i<=n;i++){
\t\tfor(int j=1;j<=n;j++){
\t\t\tif(x[tot]==i&&y[tot]==j){
\t\t\t\ta[j]=0;
\t\t\t\ttot++;
\t\t\t\tcontinue;
\t\t\t}else a[j]+=a[j-1];
\t\t}
\t\ta[0]=0;
\t}
\tcout<<a[n];
\treturn 0;
}