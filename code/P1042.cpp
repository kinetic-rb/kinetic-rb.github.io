#include<bits/stdc++.h>
using namespace std;

char str[1000000];
int f[10]={11,21};
int main(){
    int cnt=0;
    char cmp;
    for(;;cnt++){      //\u8fd9\u6837\u8f93\u5165\u5c31\u65e0\u6cd5\u5411\u6570\u7ec4\u91cc\u9762\u8bfb\u5165\u5b57\u7b26
        cin>>str[cnt];
        if(str[cnt]=='E') break;
    }
    for(int x=0;x<2;x++){
        int a=0,b=0;
        for(int i=0;i<cnt;i++){
            if(str[i]=='W') a++;
            if(str[i]=='L') b++;
            if(max(a,b)>=f[x]&&abs(a-b)>=2){
                cout<<a<<":"<<b<<endl;
                a=0,b=0;
            }
        }
        cout<<a<<":"<<b<<endl;
        if(x!=1) cout<<endl;
    }
    return 0;
}