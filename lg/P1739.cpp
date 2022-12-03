#include <bits/stdc++.h>

using namespace std;

int main(){
\tint cnt1 = 0, cnt2 = 0;
\tstring s;
\tgetline(cin,s);
\tfor(int i = 0; i < s.size(); i++){
\t\tif(s[i] == '(')
\t\t    cnt1++;
\t\t        else
\t\t            if(s[i] == ')')
\t\t                cnt2++;
\t\tif(cnt2 > cnt1) {
            cout << "NO";
            return 0;
        }
\t}
\t(cnt1 == cnt2)?cout << "YES" : cout << "NO";
\treturn 0;
}