#include <bits/stdc++.h>
using namespace std;
int n,a[10000005],m;
int read(){
    char ch = getchar();
    int x = 0;
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && ch <= '9'){
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x;
}
int find(int x,int l,int r){
  if(l == r && a[l] == x) return l;
  if(l == r && a[l] != x) return -1;
  int mid = (l+r)/2;
  if(x <= a[mid]) return find(x,l,mid);
  else return find(x,mid+1,r);
}
int main(){
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) {
        a[i] = read();
        if(a[i] < 0) return 1;
    }
    for(int i = 1;i <= m;i ++) {
        int x;
    x = read();
    if(x < 0) return 1;
    cout << find(x,1,n) << " ";
  }
  return 0;
}