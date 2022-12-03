#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,MAX;
    cin>>n;
    cin>>t;
    MAX=t;
    for(int i=1;i<n;i++)
    {
        cin>>t;
        MAX=max(MAX,t);
    }
    cout<<MAX;
    return 0;
}