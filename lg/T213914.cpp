
#include<iostream>  
#include<cstring>  
using namespace std;  
int main()  
{  
  string str1,str2;  
  int a[150000],b[150000],c[300000],len;
  int i,j;  
  memset(a,0,sizeof(a));  
  memset(b,0,sizeof(b));  
  cin>>str1>>str2;  
  a[0]=str1.length();  
  for(i=1;i<=a[0];i++)  
    a[i]=str1[a[0]-i]-'0';  
  b[0]=str2.length();  
  for(i=1;i<=b[0];i++)  
    b[i]=str2[b[0]-i]-'0';  
  memset(c,0,sizeof(c));  
  for(i=1;i<=a[0];i++)  
    for(j=1;j<=b[0];j++)  
    {  
    c[i+j-1]+=a[i]*b[j];  
    c[i+j]+=c[i+j-1]/10;  
    c[i+j-1]%=10;     
    }  
  len=a[0]+b[0]+1;
  while((c[len]==0)&&(len>1)) len--;
  for(i=len;i>=1;i--)  
    cout<<c[i];  
  return 0;   
}