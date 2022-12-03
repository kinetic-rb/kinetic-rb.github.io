#include<bits/stdc++.h>

using namespace std;

struct node
{
    string t;
    int num,len;
}s[25];

bool cmp(node a,node b)
{
    if(a.len>b.len)
        return true;
    if(a.len==b.len&&a.t>b.t)
        return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].t;
        s[i].num=i;
        s[i].len=s[i].t.size();
    }
    sort(s+1,s+n+1,cmp);
    cout<<s[1].num<<endl<<s[1].t;
    return 0;
}