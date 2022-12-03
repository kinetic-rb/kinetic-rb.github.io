#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;
double a,b,r;
int k;
int main(){
  cin>>a>>b;
  k=a/b;
  r=a-k*b;
  cout<<r;
  return 0;
}