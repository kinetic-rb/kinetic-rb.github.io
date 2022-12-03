#include<bits/stdc++.h>
using namespace std;
int main()
{
    char sp;
    int n=0;
    string str[101],a,b;
    do
    {
        n++;
        cin>>str[n];
        scanf("%c",&sp);
    }
    while(sp==' ');
    cin>>a>>b;
    for(int i=1;i<=n;i++)
        (str[i]==a)?cout<<b<<" ":cout<<str[i]<<" ";
    return 0;
}