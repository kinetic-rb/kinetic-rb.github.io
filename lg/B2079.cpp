#include<bits/stdc++.h>
using namespace  std;
int main()
{
    double e=1;
    int n;
    long long temp=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        temp*=i;
        e+=1.0/temp;
    }
    printf("%.10lf",e);
    return 0;
}