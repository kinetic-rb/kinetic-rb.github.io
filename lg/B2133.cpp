#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x;
    cin>>n;
    for(int i=sqrt(6+2*n)-1;;i++)
    {
        if((i*i+i-2*n)%6==0)
        {
            x=(i*i+i-2*n)/6;
            if(x<=0)
                continue;
            if(x>0)
            {
                cout<<x<<" "<<i;
                break;
            }
        }
    }
    return 0;
}