#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
using namespace std;
int n,a;
string qwq;
string c1;
string b1;
int b,c,d=-1,e;//\u5e76\u4e0d\u5168\u6709\u7528
int main()
{
\tcin>>n;
\tcin>>qwq;
\tfor(int i=0;i<n;i++)
\t{
\t\tcin>>a;
\t\tif(a==1)//\u64cd\u4f5c1
\t\t{
\t\t\tcin>>b1;
\t\t\tqwq+=b1;
\t\t\tcout<<qwq<<endl;
\t\t}
\t\telse if(a==2)//\u64cd\u4f5c2
\t\t{
\t\t\tcin>>b>>c;
\t\t\tc1=qwq.substr(b,c);
\t\t\tqwq=c1;
\t\t\tcout<<qwq;
\t\t\tcout<<endl;
\t\t}
\t\telse if(a==3)//\u64cd\u4f5c3
\t\t{
\t\t\tcin>>b>>b1;
\t\t\tqwq.insert(b,b1);
\t\t\tcout<<qwq<<endl;
\t\t}
\t\telse if(a==4)//\u64cd\u4f5c4
\t\t{
\t\t\tcin>>b1;
\t\t\tif(qwq.find(b1)<qwq.size())//\u627e\u4e0d\u5230\u4f1a\u8fd4\u56de\u4e00\u4e2a\u8be1\u5f02\u7684\u6570\u5b57\uff08\u53cd\u6b63\u6bd4\u5b57\u7b26\u4e32\u957f\uff09
\t\t\tcout<<qwq.find(b1)<<endl;
\t\t\telse
\t\t\tcout<<-1<<endl;
\t\t}
\t}
    return 0;
}