#include<bits/stdc++.h>
using namespace std;
int main()
{
    int L,R,ans=0;
    for(scanf("%d%d",&L,&R);L<=R;L++)
        for(int i=L;i;i/=10)
            if(i%10==2)
                ans++;
    printf("%d",ans);
    return 0;
}