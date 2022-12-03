#include<bits/stdc++.h>
using namespace std;
char a[50];//\u5b58\u50a8\u5b57\u7b26\u4e32 
int lena;
int main()
{
    cin>>a;
    lena=strlen(a);//strlen\u51fd\u6570\u8fd4\u56dechar\u578b\u6570\u7ec4\u7684\u957f\u5ea6 
    if(a[lena-1]=='r' && a[lena-2]=='e') a[lena-1]=a[lena-2]=' ';
    if(a[lena-1]=='y' && a[lena-2]=='l') a[lena-1]=a[lena-2]=' ';
    if(a[lena-1]=='g' && a[lena-2]=='n' && a[lena-3]=='i') a[lena-1]=a[lena-2]=a[lena-3]=' ';
    //\u5220\u9664\u540e\u7f00 
    cout<<a;//\u8f93\u51fa\u5220\u9664\u540e\u540e\u7f00\u540e\u7684\u5b57\u7b26\u4e32 
    return 0;
 } 