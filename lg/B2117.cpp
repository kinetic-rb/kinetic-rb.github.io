#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    char str[25];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%s",str);
        if(str[0]>='a'&&str[0]<='z')
            str[0]-=32;
        for(int j=1;j<strlen(str);j++)
            if(str[j]>='A'&&str[j]<='Z')
                str[j]+=32;
        puts(str);
    }
    return 0;
}