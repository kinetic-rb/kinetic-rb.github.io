#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#define Fo(i,a,b) for(int i=(a);i<(b);++i)
#define Fr(i,a,b) for(int i=(a);i<=(b);++i)
#define Fl(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long ll;

const int MB=1<<20;
struct FastIO
{
  char ib[MB+100],*p,*q;
  char ob[MB+100],*r,stk[128];
  
  FastIO(){p=q=ib,r=ob;}
  ~FastIO(){fwrite(ob,1,r-ob,stdout);}
  
  int gc()
  {
    if(p==q)p=ib,q=ib+fread(ib,1,MB,stdin);
    return p==q?0:*p++;
  }
  template<typename T>
  void rd(T& x)
  {
    char c=gc(),l=0;
    for(x=0;!isdigit(c);c=gc())l=c;
    for(;isdigit(c);c=gc())x=x*10-'0'+c;
    if(l=='-')x=-x;
  }
  
  void wc(char c)
  {
    if(r-ob==MB)r=ob,fwrite(ob,1,MB,stdout);
    *r++=c;
  }
  template<typename T>
  void wd(T x)
  {
    if(x<0)wc('-'),x=-x;
    int tp=0;
    do stk[++tp]=x%10+'0';
    while(x/=10);
    while(tp)wc(stk[tp--]);
  }
}IO;

const int MX=1000100;

struct Heap
{
  int v[MX],cnt;
  void SiftUp(int i)
  {
    while(i>1&&v[i]<v[i>>1])
      swap(v[i],v[i>>1]),i>>=1;
  }
  void SiftDown(int i)
  {
    while((i<<1)<=cnt)
    {
      int j=i<<1;
      if(j<cnt&&v[j|1]<v[j])++j;
      if(v[j]<v[i])swap(v[i],v[j]),i=j;
      else break;
    }
  }
  void Push(int x){v[++cnt]=x,SiftUp(cnt);}
  void Pop(){v[1]=v[cnt--],SiftDown(1);}
  int Top(){return v[1];}
  void PopPush(int x){v[1]=x,SiftDown(1);}
  void PushPop(int x){if(v[1]<x)v[1]=x,SiftDown(1);}
}T;

int M;

int main()
{
  IO.rd(M);
  int o_=2,x_;
  Fr(i,1,M)
  {
    int o;
    IO.rd(o);
    if(o==1)
    {
      int x;
      IO.rd(x);
      if(o_==1)T.Push(x_),x_=x;
      else if(o_==2)o_=1,x_=x;
      else T.PopPush(x),o_=2;
    }
    else if(o==2)
    {
      int r;
      if(o_==1)
      {
        r=x_;
        if(T.cnt)r=min(r,T.Top());
      }
      else if(o_==2)r=T.Top();
      else
      {
        r=T.v[2];
        if(T.cnt>2)r=min(r,T.v[3]);
      }
      IO.wd(r),IO.wc('\n');
    }
    else
    {
      if(o_==1)T.PushPop(x_),o_=2;
      else if(o_==2)o_=3;
      else T.Pop();
    }
  }
  return 0;
}