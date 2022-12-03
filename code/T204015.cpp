#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1,s2;
int main(){
  cin>>n>>m;
  do{
        s2+=m;
        s*=2;
  }while(s<n);
  cout<<s2<<endl;
  return 0;
}