#include<bits/stdc++.h>
using namespace std;
char n;
int p[21][21],q[21][21],dp[1<<20];
vector<char> t[1<<20];
void init(){
    for(register int i=0;i<(1<<n);i++){
        for(register char j=1;j<=n;j++){
            if((i>>j-1)&1) t[i].push_back(j); 
        }
    }
}
int main(){
    scanf("%d",&n);
    for(register char i=1;i<=n;i++) for(register char j=1;j<=n;j++) scanf("%d",&p[i][j]);
    for(register char i=1;i<=n;i++) for(register char j=1;j<=n;j++) scanf("%d",&q[i][j]);
    for(register char i=1;i<=n;i++) for(register char j=1;j<=n;j++) p[i][j]*=q[j][i];
    init();
    for(register char i=1;i<=n;i++){
        for(register int j=(1<<n)-1;j>=0;j--){
            for(register char z=0;z<t[j].size();z++){
                int k=t[j][z];
                if((j>>k-1)&1) dp[j]=max(dp[j],dp[j-(1<<k-1)]+p[i][k]);
            }
        }
    }
    printf("%d",dp[(1<<n)-1]);
    return 0;
}