#include<bits/stdc++.h>
using namespace std;
long long n = 49,a[4],i,j,s;
int b[51];
int main(){
  cin >> a[1] >> a[2] >> a[3];
  for(i = 1; i <= 3; i++){
    for(j = n; j >= 0; j--){
      if(a[i] >= pow(2,j)){
        a[i] -= pow(2,j);
        b[j]++;
      }
    }
  }
  for(i = 0; i <= n; i++){
        if(b[i] == 3) s++;
    }
    cout<< s << endl;
  return 0;
}