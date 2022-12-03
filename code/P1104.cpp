#include<bits/stdc++.h>
using namespace std;
int n;
struct node
{
    char name[25];
    short year,month,day;
}p[105];
bool cmp(node x,node y);
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>p[i].name>>p[i].year>>p[i].month>>p[i].day;
    sort(p,p+n,cmp);
    for(int i=0;i<n;i++)
        cout<<p[i].name<<endl;
    return 0;
}
bool cmp(node x,node y)
{
    if(x.year==y.year)
    {
        if(x.month==y.month)
        {
            if(x.day==y.day)
                if(n%2)
                return true;
            return x.day<y.day;
        }
        return x.month<y.month;
    }
    return x.year<y.year;
}