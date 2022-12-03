#include<bits/stdc++.h>
using namespace std;
int main()
{
\tlong long a,b,ans;
\tcin>>a>>b;
\tans=a;
\tfor(int i=1;i<b;i++)
\t\tans=ans*a%1000;
\tif(ans<=9)
\t\tcout<<"00"<<ans;
\telse if(ans<=99)
\t\tcout<<'0'<<ans;
\telse
\t\tcout<<ans;
\treturn 0;
}