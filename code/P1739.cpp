#include <bits/stdc++.h>

using namespace std;

int main(){
  int cnt1 = 0, cnt2 = 0;
  string s;
  getline(cin,s);
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '(')
        cnt1++;
            else
                if(s[i] == ')')
                    cnt2++;
    if(cnt2 > cnt1) {
            cout << "NO";
            return 0;
        }
  }
  (cnt1 == cnt2)?cout << "YES" : cout << "NO";
  return 0;
}