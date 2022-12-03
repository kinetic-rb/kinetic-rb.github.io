#include<bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c;
  cin>>a>>b>>c;
  int mx=max(a,max(b,c));
  int sum=a+b+c;
  sum-=mx;
  if(sum>mx)
    {
        cout<<1;
    }
  else cout<<0;
}