#include<bits/stdc++.h>
using namespace std;
string word;
signed main(){
  while(cin>>word){//\u8bfb\u5165
    reverse(word.begin(),word.end());//\u53cd\u8f6c
    cout<<word<<'\n';//\u8f93\u51fa
  }
  return 0;
}