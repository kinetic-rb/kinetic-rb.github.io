#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,n,d;
  cin>>a>>b>>n;
  a%=b;
  for(int i=0;i<n;i++)
  {
    d=a*10/b;
    a=a*10%b;
  }
  cout<<d;
  return 0;
}