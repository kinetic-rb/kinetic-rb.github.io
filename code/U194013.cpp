#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main(){
  double a,b,c,h,o,x,res;
  cin >> a; 
  b = sqrt(2) *a;
  c = sqrt(3)*a;
  h = b/c*a; 
  x = a/4*sqrt(6);
  o = (c-sqrt(2)*x)*pow(x,2);
  res = o/3*3.1415926535;
  printf("%.3f",res);
  return 0;
  //143.26375
} 