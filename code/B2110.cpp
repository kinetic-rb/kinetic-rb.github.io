#include<bits/stdc++.h>
using namespace std;
int main()
{
    char ios[100001];
    int letters[26],len,i;
    memset(letters,0,sizeof(letters));
    gets(ios);
    len=strlen(ios);
    for(i=0;i<len;i++)
        letters[ios[i]-'a']++;
    for(i=0;i<len;i++)
    {
        if(letters[ios[i]-'a']==1)
        {
            cout<<ios[i];
            return 0;
        }
    }
    cout<<"no";
    return 0;
}