#include<iostream>
#include<cstring>
using namespace std;
int main()
{
  string str1,str2;
  int a[150000],b[150000],len;
  int i;  
  memset(a,0,sizeof(a));  
  memset(b,0,sizeof(b));  
  cin>>str1>>str2;
  a[0]=str1.length();
  for(i=1;i<=a[0];i++) 
    a[i]=str1[a[0]-i]-'0';  
  b[0]=str2.length();
  for(i=1;i<=b[0];i++)
    b[i]=str2[b[0]-i]-'0';  
  len=(a[0]>b[0]?a[0]:b[0]);
  for(i=1;i<=len;i++)
  {  
    a[i]+=b[i];
    a[i+1]+=a[i]/10;
    a[i]%=10;
  }  
  len++;
  while((a[len]==0)&&(len>1))
  len--;
  for(i=len;i>=1;i--)  
    cout<<a[i];  
  return 0;   
}