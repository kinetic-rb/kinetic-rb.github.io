#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
struct IO_Tp {
    const static ll _I_Buffer_Size = 2 << 22;
    char _I_Buffer[_I_Buffer_Size], *_I_pos = _I_Buffer;

    const static ll _O_Buffer_Size = 2 << 22;
    char _O_Buffer[_O_Buffer_Size], *_O_pos = _O_Buffer;

    IO_Tp() { fread(_I_Buffer, 1, _I_Buffer_Size, stdin); }
    ~IO_Tp() { fwrite(_O_Buffer, 1, _O_pos - _O_Buffer, stdout); }

    IO_Tp &operator>>(int &res) {
        ll f=1;
        while (!isdigit(*_I_pos)&&(*_I_pos)!='-') ++_I_pos;
        if(*_I_pos=='-')f=-1,++_I_pos;
        res = *_I_pos++ - '0';
        while (isdigit(*_I_pos)) res = res * 10 + (*_I_pos++ - '0');
        res*=f;
        return *this;
    }

    IO_Tp &operator<<(ll n) {
        if(n<0)*_O_pos++='-',n=-n;
        static char _buf[10];
        char *_pos = _buf;
        do
            *_pos++ = '0' + n % 10;
        while (n /= 10);
        while (_pos != _buf) *_O_pos++ = *--_pos;
        return *this;
    }

    IO_Tp &operator<<(char ch) {
        *_O_pos++ = ch;
        return *this;
    }
} IO;
//1e5,5e5
int n,m,cnt;
int ind[500005],tot[500005];
ll sumans;
ll c[100005],maxa,mina=1e9,p[200005];
ll a[100005];
bool flag[500005];
int f[25000005],inde[25000005],t[100005];
struct NOde
{
    int num,l,r;
}nd[500005];
inline int lowbit(int x){ return x&-x;}
inline void upd(int x,ll k){ while(x<=n){c[x]+=k;x+=lowbit(x);}}
inline ll query(int x){ll res=0;while(x>=1){res+=c[x];x-=lowbit(x);}return res;}
int fin(int x,int r)
{
    while(x!=f[x]&&x<=r) x=f[x]=f[f[x]];
    return x;
}
struct nodee
{
    int shu,indd;
}b[200005];
bool cmp(nodee aa,nodee bb)
{
    if(aa.shu!=bb.shu) return aa.shu<bb.shu;
    return aa.indd<bb.indd;
}
void sortt(int l,int r)
{
  if(l>r) return;
  int len=r-l+1;
  if(len*int(log2(len))<=2*len+2*n)//\u6309\u7167\u5faa\u73af\u6b21\u6570\u6392\u7684\uff0c\u548c\u590d\u6742\u5ea6\u6bd4\u8f83\u65e0\u592a\u5927\u533a\u522b
  {
    sort(inde+l,inde+r+1);
  }
  else
  {
    for(int i=1;i<=n;i++) t[i]=0;
    for(int i=l;i<=r;i++)
    {
      t[inde[i]]++;
    }
    int cntt=l;
    for(int i=1;i<=n;i++)
    {
      if(t[i]>0)
      {
        for(int j=1;j<=t[i];j++) inde[cntt]=i,cntt++;
      }
    }
  }
}
int main()
{
  memset(flag,true,sizeof(flag));
    IO>>n>>m;
    for(register int i=1;i<=n;i++)
    {
        int tmp;
        IO>>tmp;
        a[i]=b[i].shu=tmp;
        b[i].indd=i;
        upd(i,tmp);
        maxa=(maxa>a[i]?maxa:a[i]);
        mina=(a[i]<mina?a[i]:mina);
    }
    sort(b+1,b+n+1,cmp);
    for(register int i=1;i<=n;i++)
    {
        if(b[i].shu!=1&&b[i].shu!=0&&ind[b[i].shu]==0) ind[b[i].shu]=i;
        tot[b[i].shu]++;
    }
    cnt=1;
    for(register int i=2;i<=maxa;i++)
    {
        nd[i].l=cnt;
        nd[i].r=cnt-1;
        for(register int j=i;j<=maxa;j+=i)
        {
            if(tot[j]>0)
            {
                for(register int k=ind[j];k<=ind[j]+tot[j]-1;k++)
                {
                    nd[i].r++;
                    f[nd[i].r]=nd[i].r;
                    inde[nd[i].r]=b[k].indd;
                    if(nd[i].r!=nd[i].l&&inde[nd[i].r-1]>b[k].indd) flag[i]=false;
                }
            }
        }
        cnt=nd[i].r+1;
    }
    ll lastans=0;
    for(register int i=1;i<=m;i++)
    {
        int opt,l,r,x;
        IO>>opt>>l>>r;
        if(opt==2)
        {
            l^=lastans;
            r^=lastans;
            lastans=query(r)-query(l-1);
            IO<<lastans<<'\n';
        }
        if(opt==1)
        {
            IO>>x;
            l^=lastans;
            r^=lastans;
            x^=lastans;
            if(x < 2) continue;
            if(x>maxa) continue;
            if(nd[x].l>nd[x].r) continue;
            if(!flag[x]) sortt(nd[x].l,nd[x].r),flag[x]=true;
            int fir=lower_bound(inde+nd[x].l,inde+nd[x].r+1,l)-inde;
            if(fir>nd[x].r) continue;
            for(register int j=fir;inde[j]<=r&&j<=nd[x].r;j=fin(j,nd[x].r)+1)
            {
                int indt=inde[j];
                if(a[indt]%x)
                {
                    f[j-1]=j;
                    continue;
                }
                a[indt]/=x;
                if(a[indt]%x!=0) f[j-1]=j;
                upd(indt,-a[indt]*(x-1));
            }
        }
    }
    return 0;
}