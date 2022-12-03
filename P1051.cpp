#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mp,mt,mu=0,maxmark=0,sum=0,x;
    char a,b;
    string name,MAXname;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>name>>mp>>mt>>a>>b>>x;
        if(mp>80)
            if(x>0)
                mu+=8000;
        if(mp>85)
            if(mt>80)
                mu+=4000;
        if(mp>90)
            mu+=2000;
        if(mp>85)
            if(b=='Y')
                mu+=1000;
        if(mt>80 && a=='Y')
            mu+=850;
        sum+=mu;
        if(mu>maxmark)
            MAXname=name,maxmark=mu;
        mu=0;
    }
    cout<<MAXname<<endl<<maxmark<<endl<<sum;
    return 0;
}