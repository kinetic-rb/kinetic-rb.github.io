#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[1000];
    int len=0,i;
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!=' ')
            len++;
                else
                {
                    if(len>0)
                        cout<<len<<",";
                    len=0;
                }
    }
    cout<<len;
    return 0;
}