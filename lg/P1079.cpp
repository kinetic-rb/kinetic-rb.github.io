#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void turn(char &x);
int main()
{
    char key[1000],secret[1000];
    int i,j;
    gets(key);
    gets(secret);
    for(i=0;i<strlen(key);i++)
        turn(key[i]);
    for(i=j=0;i<strlen(secret);i++)
    {
        if(secret[i]<='Z')
        {
            secret[i]=secret[i]-(key[j]-'A');
            j++;
            if(secret[i]<'A')
                secret[i]='Z'-('A'-secret[i])+1;
        }
            else
            {
                secret[i]=secret[i]-(key[j]-'A');
                j++;
                if(secret[i]<'a')
                    secret[i]='z'-('a'-secret[i])+1;
            }
        if(j>strlen(key)-1)
            j=0;
    }
    cout<<secret;
    return 0;
}
void turn(char &x)
{
    if((x>='a')&&(x<='z'))
        x-=32;
}
