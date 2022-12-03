#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define R register
#include<cstdio>
#include<iostream>
using namespace std;
const int N=1e5+5;
int n,m,a[N];
float x;
static char buf[1000000],*p1=buf,*p2=buf;
#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int read()
{
\tR int x=0;
\tR char a=getchar();
\twhile (a<'0'||a>'9')  a=getchar();
\twhile (a>='0'&&a<='9') x=(x<<1)+(x<<3)+(a^48),a=getchar();
\treturn x;
}
int main()
{
\tn=read(); m=read();
\tfor(int i=1;i<=n;i++) a[i]=read();
\twhile (m--)
\t{
\t\tR int opt,l,r,ans=0;
\t\topt=read(); l=read(); r=read(); x=read();
\t\tif (opt==1)
\t\t\tfor (R int i=l;i<=r;i++) a[i]-=(a[i]>x)?x:0;
\t\telse
\t\t{
\t\t\tfor (R int i=l;i<=r;i++) ans+=!(a[i]-x);
\t\t\tprintf("%d
",ans);
\t\t}
\t}
\treturn 0;
}