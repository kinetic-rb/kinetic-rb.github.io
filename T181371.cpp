#include <bits/stdc++.h>

using namespace std;

const int LC = 1e9 + 7;

long long n, a[100000];

int main(){
  cin >> n;
  a[1] = 1;
  a[2] = 1;
  for(int i = 3;i <= n;i++){
    a[i] = (a[i - 1] + a[i - 2]) % LC;
  }
  cout << a[n] << endl;
  return 0;
}