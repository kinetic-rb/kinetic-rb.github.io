#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b,ans;
  cin>>a>>b;
  ans=a;
  for(int i=1;i<b;i++)
    ans=ans*a%1000;
  if(ans<=9)
    cout<<"00"<<ans;
  else if(ans<=99)
    cout<<'0'<<ans;
  else
    cout<<ans;
  return 0;
}