#include<bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>,greater<int> >heap;
int main()
{
    int n,ob,b;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&ob);
        if(ob==1)
        {
            scanf("%d",&b);
            heap.push(b);
        }
        if(ob==2)
        {
            printf("%d
",heap.top());
        }
        if(ob==3)
            heap.pop();
    }
    return 0;
}