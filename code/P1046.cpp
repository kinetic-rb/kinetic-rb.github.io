#include<bits/stdc++.h>
using namespace std;
int main()
{
  short a,b,c,d,e,f,g,h,i,j,s,io=0;
  cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>s;
  if(s+31>a) io++;
  if(s+31>b) io++;
  if(s+31>c) io++;
  if(s+31>d) io++;
  if(s+31>e) io++;
  if(s+31>f) io++;
  if(s+31>g) io++;      
  if(s+31>h) io++;
  if(s+31>i) io++;
  if(s+31>j) io++;
  cout<<io;
  return 0;
}