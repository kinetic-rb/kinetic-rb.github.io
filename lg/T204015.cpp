#include<bits/stdc++.h>
using namespace std;
long long n,m,s=1,s2;
int main(){
\tcin>>n>>m;
\tdo{
        s2+=m;
        s*=2;
\t}while(s<n);
\tcout<<s2<<endl;
\treturn 0;
}