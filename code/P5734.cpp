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
  cin>>n;
  cin>>qwq;
  for(int i=0;i<n;i++)
  {
    cin>>a;
    if(a==1)//\u64cd\u4f5c1
    {
      cin>>b1;
      qwq+=b1;
      cout<<qwq<<endl;
    }
    else if(a==2)//\u64cd\u4f5c2
    {
      cin>>b>>c;
      c1=qwq.substr(b,c);
      qwq=c1;
      cout<<qwq;
      cout<<endl;
    }
    else if(a==3)//\u64cd\u4f5c3
    {
      cin>>b>>b1;
      qwq.insert(b,b1);
      cout<<qwq<<endl;
    }
    else if(a==4)//\u64cd\u4f5c4
    {
      cin>>b1;
      if(qwq.find(b1)<qwq.size())//\u627e\u4e0d\u5230\u4f1a\u8fd4\u56de\u4e00\u4e2a\u8be1\u5f02\u7684\u6570\u5b57\uff08\u53cd\u6b63\u6bd4\u5b57\u7b26\u4e32\u957f\uff09
      cout<<qwq.find(b1)<<endl;
      else
      cout<<-1<<endl;
    }
  }
    return 0;
}