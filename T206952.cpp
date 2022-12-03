//cowfind
#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

ll js, ans, js1, f, wz;
string s;

int main(){
//  freopen("cowfind.in", "r", stdin);
//  freopen("cowfind.out", "w", stdout);
  cin >> s;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '('){
      wz = i;
      break;
    }
  }
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '('){
      if(i == wz){
        js++;
      }
      if(s[i + 1] == '('){
        js++; 
      }
      js1 = 0;
    }
    else{
      js1++;
      if(js >= 2 && js1 >= 2){
        ans += (js - 1);
      }
    }
  }
  cout << ans;
  return 0;
}