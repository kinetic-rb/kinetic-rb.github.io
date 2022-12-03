#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num,mark;
};
bool cmp(node x,node y)
{
    if(x.mark==y.mark)
        return x.num<y.num;
    return (x.mark>y.mark) ;
}
int main()
{
    node p[10000];
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n;cin>>p[i].num>>p[i++].mark);
    sort(p+1,p+n+1,cmp);
    for(m*=1.5;p[m].mark==p[m+1].mark;m=m+1);
    cout<<p[m].mark<<' '<<m<<endl;
    for(int i=1;i<=m;i++)
    {
        cout<<p[i].num<<' '<<p[i].mark<<endl;
    }
    return 0;
}