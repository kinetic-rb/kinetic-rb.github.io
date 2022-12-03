#include<bits/stdc++.h>
using namespace std;
int main()
{
    double x,y;
    int n,sy[20][2];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>sy[i][0]>>sy[i][1];
    x=sy[0][1]*1.0/sy[0][0];
    for(int i=1;i<n;i++)
    {
        y=sy[i][1]*1.0/sy[i][0];
        if(y-x>0.05)
            cout<<"better"<<endl;
                else
                    if(x-y>0.05)
                        cout<<"worse"<<endl;
                            else
                                cout<<"same"<<endl;
    }
    return 0;
}