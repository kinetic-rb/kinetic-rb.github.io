#include<bits/stdc++.h>
using namespace std;
//1934//
int main()
{
    set<int>s;
    int n,a[105];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    for(printf("%d
",s.size());!s.empty();s.erase(s.begin()))
        cout<<*s.begin()<<" ";
    return 0;
}