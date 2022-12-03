#include<bits/stdc++.h>
using namespace std;
int main()
{
\tint a,b,n,d;
\tcin>>a>>b>>n;
\ta%=b;
\tfor(int i=0;i<n;i++)
\t{
\t\td=a*10/b;
\t\ta=a*10%b;
\t}
\tcout<<d;
\treturn 0;
}