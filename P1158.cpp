#include <iostream>
#include <algorithm>

using namespace std;

inline int dist(int x1,int y1,int x2,int y2){return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);}

struct CE{
\tint l1,l2;
}f[110000];

inline bool cmp(const CE &a,const CE &b){return a.l1<b.l1;}
int main( ){
\tint n,i,j,k,x1,x2,y1,y2,a,b;
\tstd::ios::sync_with_stdio(false);
\tcin>>x1>>y1>>x2>>y2;
\tcin>>n;
\tfor(i=1;i<=n;i++){
\t\tcin>>a>>b;
\t\tf[i].l1=dist(x1,y1,a,b);
\t\tf[i].l2=dist(x2,y2,a,b);
\t}
\tsort(f+1,f+n+1,cmp);
\tint ans=f[n].l1,hei=-1;
\tfor(i=n-1;i>=1;i--){
\t\thei=max(hei,f[i+1].l2);
\t\tans=min(ans,hei+f[i].l1);
\t}
\tcout<<ans<<endl;
}
